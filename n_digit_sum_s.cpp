#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int helper(int n,int s,vector<vector<int>> dp) {
  if(n==0 && s==0) return 1;
  if(s<0) return 0;
  if(n==0) return 0;
  if(dp[n][s] != -1) return dp[n][s];

  int ans=0;
  for(int i=0;i<10;i++)
    ans += helper(n-1,s-i,dp),ans%=mod;

  return dp[n][s] = ans;
}

int func(int n,int s) {
  if(s==0) return 0;
  if(n==0) return 0;
  vector<vector<int>> dp;

  dp.resize(n+1);
  for(int i =0;i<n+1;i++) {
    dp[i].resize(s+1);
    for(int j=0;j<s+1;j++)
      dp[i][j] = -1;
  }

  int ans = 0;
  for(int i =1;i<10;i++) {
    ans+=helper(n-1,s-i,dp);
    ans%=mod;
  }
  return ans;
}

int main() {
  int n =2;
  int s =4;
  int ans = func(n,s);
  cout<<ans<<endl;
  return 0;
}
