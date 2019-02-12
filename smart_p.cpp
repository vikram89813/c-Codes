#include<iostream>

using namespace std;

template <class T>
class smartp{
  T *ptr;
  public:
    explicit smartp(T *p=NULL) : ptr(p) {}
    T & operator * () {return *ptr;}
    T * operator -> () {return ptr;};
    ~smartp() {delete ptr;}
};

int main() {
  smartp<int> t(new int());
  *t = 20;
  cout<<*t<<endl;
}
