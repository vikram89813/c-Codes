#include<iostream>

using namespace std;

int hf(std::string const& s) {
    unsigned long hash = 5381;
    for (auto c : s) hash = (hash << 5) + hash + c; /* hash * 33 + c */
    return hash;
}

int main() {
  string s1 = "kumar";
  string s2 = "vikram";
  cout<<hf(s1)<<endl;
  cout<<hf(s2)<<endl;
  return 0;
}
