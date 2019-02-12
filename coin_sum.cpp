#include<bits/stdc++.h>

using namespace std;

int helper(vector<int> &arr,vector<int> &dp,int idx,int curr_sum,int n) {
  if(curr_sum == 0) return 1;
  if(curr_sum < 0) return 0;
  if(idx == n-1 && curr_sum != 0) return 0;
  if(idx >= n) return 0;
  if(dp[curr_sum]) return dp[curr_sum];

  dp[curr_sum] = helper(arr,dp,idx,curr_sum-arr[idx],n) + helper(arr,dp,idx+1,curr_sum,n);
  return dp[curr_sum];
}

int func(vector<int> &arr,int sum) {
  vector<int> dp(sum+1,0);
  dp[0] = 1;
  int ans = helper(arr,dp,0,sum,arr.size());
  for(auto i : dp) cout<<i<<" ";
  cout<<endl;
  return ans;
}

int main() {
  vector<int> arr = {1,2,3};
  int ans = func(arr,4);
  cout<<ans<<endl;
  return 0;
}
