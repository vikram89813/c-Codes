#include<bits/stdc++.h>

using namespace std;

bool helper(vector<int> &arr,int idx) {
  int min_idx = arr.size()-1;
  for(int i = idx;i>=0;i--) {
    if(arr[i] + i >= min_idx) min_idx = i;
  }
  if(min_idx == 0) return true;
  else return false;
}

bool func(vector<int> &arr) {
  int n = arr.size();
  if(n==0) return 0;
  return helper(arr,n-2);
}

int main() {
  //vector<int> arr = {2,3,1,1,4};
  vector<int> arr = {3,2,2,0,4};
  bool ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
