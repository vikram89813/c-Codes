#include<bits/stdc++.h>


#define DISALLOW_COPY_ASSIGN(TypeName) \
    TypeName(const TypeName&) = delete;\
    TypeName(TypeName&&) = delete;\
    TypeName& operator=(const TypeName&) = delete;\
    TypeName& operator=(TypeName&&) = delete;


template <class T>
class Singleton {
public:
    static T& getInstance(){
        static T instance;
        return instance;
    }
protected:
    Singleton() = default;
    DISALLOW_COPY_ASSIGN(Singleton);
};

class Widget : public Singleton<Widget>{
public:
    void setValue(int value){ this->value = value; }
    int getValue() const { return this->value; }
private:
    int value;
    Widget() = default;
    DISALLOW_COPY_ASSIGN(Widget);

    friend class Singleton<Widget>;
};


int main()
{
    auto& w = Widget::getInstance();
    w.setValue(1000);

    auto& w1 = Widget::getInstance();
    std::cout << w1.getValue() << std::endl;
    return 0;
}

