#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int helper(int idx,int stable,string &str,int k) {
  int n= str.size();
  if(idx == n) {
    if(stable == k) return 0;
    else return INT_MAX;
  }

  if(stable == k) return INT_MAX;

  if(dp[idx][stable] != -1) return dp[idx][stable];

  int w = 0;
  int b = 0;
  int ans = INT_MAX;

  for(int i = idx;i<n;i++) {
    w += str[i] == 'W';
    b += str[i] == 'B';
    if(w*b > ans) break;
    int temp = helper(i+1,stable+1,str,k);
    if(temp != INT_MAX) ans = min(ans,temp+(w*b));
  }
  return dp[idx][stable] = ans;
}

int func(string &str,int k) {
  if(str.size() == 0) return 0;
  int n = str.size();
  dp.clear();
  dp.resize(n,vector<int>(k,-1));
  int ans = helper(0,0,str,k);
  for(auto i : dp) {
    for(auto j : i)
      cout<<j<<" ";
    cout<<endl;
  }
  return ans == INT_MAX ? -1 : ans;
}

int main() {
  string str = "WWWB";
  int ans = func(str,2);
  cout<<ans<<endl;
  return 0;
}
