#include<iostream>
#include<vector>

using namespace std;

int main() {
  vector<int> arr = {2,0,2,1,1,0};
  sort_(arr);
  for(auto i : arr) cout<<i<<" ";
  cout<<endl;
  return 0;
}
