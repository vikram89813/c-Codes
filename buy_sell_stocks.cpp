#include<bits/stdc++.h>

using namespace std;

int func(vector<int> &arr) {
  int k=2;
  vector<vector<int>> dp(k+1, vector<int> (arr.size(),0));

  int ans = -1;
  for(int i = 1;i<=k;i++) {
    int temp = dp[i-1][0] - arr[0];
    for(int j =1;j<arr.size();j++) {
      dp[i][j] = max(dp[i][j-1], arr[j] + temp);
      temp = max(temp, dp[i-1][j]-arr[j]);
      ans = max(ans,dp[i][j]);
    }
  }
  return ans;
}

int main() {
  vector<int> arr = {1,2,1,2};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
