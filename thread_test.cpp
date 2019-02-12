#include<iostream>
#include<thread>

using namespace std;

void fun(string &s,int x) {
  while(x)
  	cout<<s<<endl,--x;
}

int main() {
  string str = "hello!!";
  thread t1(fun,ref(str),3);
  t1.join();
  return 0;
}
