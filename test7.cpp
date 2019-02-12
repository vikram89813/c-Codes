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
    SingleTon(const T&) = delete;
    SingleTon & operator= (const T&) = delete;

    SingleTon & operator=(T&&) = delete;
    SingleTon(T&&) = delete;
};

class derived : public SingleTon<derived>{
public:
    derived() = default;  

    private:
    //derived() = default;
    derived(const derived&) = delete;
    derived(derived&&) = delete;

    derived& operator=(const derived&) = delete;
    derived& operator=(derived&&) = delete;
};

int main()
{
    derived& d = derived::getInstance();
    //derived& d = derived::getInstance();
}
