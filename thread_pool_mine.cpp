#include<iostream>
#include<vector>
#include<condition_variable>
#include<mutex>
#include<queue>
#include<thread>
#include<functional>
#include<future>

class ThreadPool {
    std::vector<std::thread> mThreads;
    std::condition_variable mCond;
    std::mutex mMutex;
    using Task = std::function<void()>;
    std::queue<Task> mQueue;
    bool stopping = false;

    void start(std::size_t num) {
        for(auto i=0u;i<num;i++) {
            mThreads.emplace_back([=]() {
                while(true)
                {
                    Task task;
                    {
                        std::unique_lock<std::mutex> lock(mMutex);
                        mCond.wait(lock,[=](){
                            return (stopping || !mQueue.empty());
                        });

                        if(stopping && mQueue.empty()) break;
                        task = std::move(mQueue.front());
                        mQueue.pop();
                    }
                    task();
                }
            });
        }
    }

    void stop() noexcept {
        {
            std::unique_lock<std::mutex> lock(mMutex);
            stopping = true;
        }
        mCond.notify_all();
        for(auto &thread : mThreads)
            thread.join();
    }
    public:
    explicit ThreadPool(std::size_t n) {
        start(n);
    }
    ~ThreadPool() {
        stop();
    }

    template<class T>
    auto enqueue(T task) -> std::future<decltype(task())>
    {
        auto wrapper = std::make_shared<std::packaged_task<decltype(task()) ()>>(std::move(task));
        {
            std::unique_lock<std::mutex> lock(mMutex);
            mQueue.emplace([=](){
                (*wrapper)();
            });
        }
        mCond.notify_one();
        return wrapper->get_future();
    }
};

int main() {
    ThreadPool th(36);
    auto f1 = th.enqueue([=](){
        return 1;
    });
    auto f2 = th.enqueue([=](){
        return 2;
    });

    auto f3 = th.enqueue([=](){
        std::cout<<"hello!!"<<std::endl;
    });

    std::cout<<f1.get() + f2.get()<<std::endl;
    return 0;
}