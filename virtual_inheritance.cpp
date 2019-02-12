#include<bits/stdc++.h>

using namespace std;

class Base {
  public:
    virtual void show() {
      cout<<"hello! Base"<<endl;
    }
};

class D1 : public virtual Base{
  public:
    void show_d() {
      cout<<"hello! D1"<<endl;
    }
    void show() {
      cout<<"hello!! test D1"<<endl;
    }
};

class D2 : public virtual Base{
  public:
    void show_d() {
      cout<<"hello! D2"<<endl;
    }
    void show() {
      cout<<"hello!! test D2"<<endl;
    }
};

class Test : public D1,public D2 {
  public:
    void t() {
      cout<<"hello! test!"<<endl;
    }
};

int main() {
  Test t;
  t.show();
  return 0;
}
