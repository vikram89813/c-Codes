#include<bits/stdc++.h>

using namespace std;

class T {
  int *ptr;
  public:
    T(int p=0) : ptr(new int(p)) {}
    void setv(int i=0) {*ptr = i;}
    void pri() {cout<<*ptr<<endl;}
    T & operator = (const T&);
};

T & T::operator = (const T &t) {
  if(this != &t)
    *(this->ptr) = *(t.ptr);
  return *this;
}

int main() {
  T t1(10);
  T t2;
  t2 = t1;
  t2.setv(5);
  t1.pri();
  t2.pri();
}
