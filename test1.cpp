#include<iostream>

using namespace std;

template<class T>
class smartptr{
    T *ptr;
    public:
    smartptr(T *p=nullptr): ptr(p) {}
    smartptr(const smartptr &p){
        cout<<"copy"<<endl;
        ptr = new T;
        *ptr = *p.ptr;
    }
    smartptr(smartptr &&p) {
        cout<<"move copy!"<<endl;
        ptr = p.ptr;
        p.ptr=nullptr;
    }

    smartptr & operator = (const smartptr &p) {
        cout<<"assign"<<endl;
        if(this == &p) return *this;

        delete ptr;

        ptr = new T;
        *ptr = *p.ptr;
        //p.ptr = nullptr;
        return *this;
    }
    smartptr & operator = (smartptr &&p) {
        cout<<"move assign!"<<endl;
        if(this == &p) {
            cout<<"h 1"<<endl;
            return *this;
            }

        cout<<"h2"<<endl;
        delete ptr;
        ptr = p.ptr;
        p.ptr = nullptr;
        return *this;
    }

    ~smartptr() {
        delete ptr;
    }
};

class test{
public:
test() {
    cout<<"cons"<<endl;
}

~test() {
    cout<<"dest"<<endl;
}
};

smartptr<test> res() {
    smartptr<test> r(new test);
    return r;
}

int main() {
    smartptr<test> p(new test);
    smartptr<test> q = p;
    smartptr<test> z;
    z = res();
    //q = p;
    return 0;
}