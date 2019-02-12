#include<iostream>

using namespace std;

int main() {
  string a = "abcdefghij";
  string b = "cde";
  auto i = a.find(b);
  cout<<i<<endl;
  return 0;
}
