#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {
  srand(time(NULL));
  int a = 1 + rand() % 3;
  cout<<a<<endl;
  int b;
  cin>>b;
  vector<int> arr = {1,2,3};
  arr.push_back(a);
  arr.push_back(b);

  unordered_map<int,int> h;
  for(auto i : arr) {
    if(h.find(i) == h.end()) h[i] = 1;
    else h[i] +=1;
  }

  for(auto i : arr) {
    if(h[i] == 1) {cout<<i<<endl; break;}
  }
}
