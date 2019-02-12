#include<bits/stdc++.h>

template<class T>
class SingleTon{
public:
    static T& getInstance() {
        static T instance;
        return instance;
    }
protected:
    SingleTon() = default;

    SingleTon(const SingleTon&) = delete;
    SingleTon& operator= (const SingleTon&) = delete;

    SingleTon& operator=(SingleTon&&) = delete;
    SingleTon(SingleTon&&) = delete;
};

class Widget : public SingleTon<Widget>{
    int value;
public:
    void setValue(int value){
        this->value = value;
    }
    int getValue() const { return this->value; }
private:
    Widget() = default;

    Widget(const Widget&) = delete;
    Widget(Widget&&) = delete;

    Widget& operator=(const Widget&) = delete;
    Widget& operator=(Widget&&) = delete;

    friend class SingleTon<Widget>;
};

int main() {
    auto &d = Widget::getInstance();
}
