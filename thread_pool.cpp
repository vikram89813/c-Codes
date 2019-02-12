#include<iostream>
#include<vector>
#include<thread>
#include<functional>
#include<condition_variable>
#include<queue>
#include<future>

class ThreadPool {
    public:

    using Task = std::function<void()>;
    explicit ThreadPool(std::size_t numThreads) {
        start(numThreads);
    }
    ~ThreadPool() {
        stop();
    }

    // future used to store thread data.
    template<class T>
    auto enqueue(T task) -> std::future<decltype(task())> 
    {
        // shared pointer used because we are executing in thread pool.
        // package_task is a wrapper for any executables such as functor. return type of a package
        // task is a future.
        auto wrapper = std::make_shared<std::packaged_task<decltype(task()) ()>>(std::move(task));
        {
            std::unique_lock<std::mutex> lock(mEventMutex);
            mTasks.emplace([=] {
                (*wrapper)();
                // here future contains result of the task.
            });
        }
        // set this task to one of the thread.
        meventVar.notify_one();
        // return to the caller.
        return wrapper->get_future();
    }

    private:
    std::vector<std::thread> mThreads;
    std::condition_variable meventVar;
    std::mutex mEventMutex;
    bool mStopping = false;
    std::queue<Task> mTasks;

    void start(std::size_t numThreads) {
        for(auto i=0u;i<numThreads;i++) {
            mThreads.emplace_back([=] {
                while(true) {
                    Task task;
                    {
                      std::unique_lock<std::mutex> lock(mEventMutex);
                      meventVar.wait(lock,[=]{
                          return (mStopping || !mTasks.empty());
                      });

                      if(mStopping && mTasks.empty()) break;

                      task = std::move(mTasks.front());
                      mTasks.pop();
                    }
                    task();
                }
            });
        }
    }

    void stop() noexcept {
        {
          std::unique_lock<std::mutex> lock(mEventMutex);
          mStopping = true;
        }
        meventVar.notify_all();
        for(auto &thread : mThreads)
          thread.join();
    }
};

int main(){
    {
      ThreadPool pool(36);
      auto f1 = pool.enqueue([](){
          return 1;
      });
      auto f2 = pool.enqueue([](){
          return 2;
      });

      std::cout<<(f1.get() + f2.get()) << std::endl;
    }
    return 0;
}