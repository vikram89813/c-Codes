#include<bits/stdc++.h>

using namespace std;

int helper(int n,int idx,vector<int> &arr) {
  if(idx == n) return 1;
  if(idx > n) return 0;
  if(arr[idx] != -1) return arr[idx];

  int ways = 0;
  ways += helper(n,idx+1,arr);
  ways += helper(n,idx+2,arr);
  arr[idx] = ways;
  return arr[idx];
}

int func(int n) {
  if(n==0) return 0;
  if(n==1) return 1;
  vector<int> arr(n,-1);
  int ans = helper(n,0,arr);
  return ans;
}

int main() {
  int n = 3;
  int ans = func(n);
  cout<<ans<<endl;
  return 0;
}
