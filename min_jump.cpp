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

int cal(vector<int> &arr,int idx,int n,vector<int> &dp) {
  if(idx == n-1) return dp[n-1];
  if(arr[idx] == 0 && idx != n-1) return INT_MAX;
  if(dp[idx] != 0) return dp[idx];

  for(int i = idx;i>=0;i--) {
    int s = arr[i];
    int min_ = INT_MAX;
    for(int j = 1;j<=s && i+j <= n-1 ;j++) {
      min_ = min(min_, cal(arr,i+j,n,dp));
    }
    dp[i] = 1+min_;
  }
  return dp[0];
}

int func(vector<int> &arr) {
  int n = arr.size();
  if(n==0) return -1;
  if (!helper(arr,n-2)) return -1;
  vector<int> dp(n,0);
  int ans = cal(arr,n-2,n,dp);
  return ans;
}

int main() {
 // vector<int> arr = { 33, 21, 50, 0, 0, 46, 34, 3, 0, 12, 33, 0, 31, 37, 15, 17, 34, 18, 0, 4, 12, 41, 18, 35, 37, 34, 0, 47, 0, 39, 32, 49, 5, 41, 46, 26, 0, 2, 49, 35, 4, 19, 2, 27, 23, 49, 19, 38, 0, 33, 47, 1, 21, 36, 18, 33, 0, 1, 0, 39, 0, 22, 0, 9, 36, 45, 31, 4, 14, 48, 2, 33, 0, 39, 0, 37, 48, 44, 0, 11, 24, 16, 10, 23, 22, 41, 32, 14, 22, 16, 23, 38, 42, 16, 15, 0, 39, 23, 0, 42, 15, 25, 0, 41, 2, 48, 28};
  vector<int> arr = {2,3,1,1,4};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
