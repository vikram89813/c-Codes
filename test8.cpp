#include<bits/stdc++.h>

template<class T>
class SingleTon{
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }
protected:
    SingleTon<T>() = default;

    SingleTon<T>(const SingleTon&) = delete;
    SingleTon<T>& operator= (const SingleTon&) = delete;

    SingleTon<T>& operator=(SingleTon&&) = delete;
    SingleTon<T>(SingleTon&&) = delete;
};

class Widget : public SingleTon<Widget>{
private:
    Widget() = default;

    Widget(const Widget&) = delete;
    Widget(Widget&&) = delete;

    Widget& operator=(const Widget&) = delete;
    Widget& operator=(Widget&&) = delete;
};

int main() {
    auto &d = Widget::getInstance();
}
