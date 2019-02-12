#include<iostream>
#include<vector>
#include<mutex>
#include<functional>

template<class T>
class Event final{
    using Task = std::function<T>;
    std::vector<Task> mEvents;
    std::mutex m;
    public:
    explicit Event() = default;
    void operator +=(const Task &e) noexcept{
        std::lock_guard<std::mutex> lock(m);
        mEvents.emplace_back(std::move(e));
    }
    void operator -=(const Task &e) noexcept {
        std::lock_guard<std::mutex> lock(m);
        //TODO:: add code to delete.
    }

    template<class ...TArgs>
    void operator() (TArgs ...args) {
        std::lock_guard<std::mutex> lock(m);
        for(auto &listener : mEvents) {
            listener(std::forward<TArgs>(args)...);
        }
    }

    Event(const Event&) = delete;
    //Event(Event &&) = delete;
    Event& operator = (const Event &) = delete;
    //Event& operator = (Event &&) = delete;
};

int main() {
    Event<void(std::string)> Alarm;
    Event<void(int)> Alarm1;
    const std::string str = "abcdefgh!!!";
    Alarm += [=](const std::string &s) {
            std::cout<<s<<std::endl;
    };
    Alarm1 += [=](int a) {
        std::cout<<a<<std::endl;
    };
    Alarm(str);
    Alarm1(56);
    return 0;
}