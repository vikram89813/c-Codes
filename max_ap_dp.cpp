#include<bits/stdc++.h>

using namespace std;

int func(vector<int> &arr) {
  if(arr.size() == 0) return 1;
  int s = arr.size();
  int min_ = *min_element(arr.begin(),arr.end());
  int max_ = *max_element(arr.begin(),arr.end());

  int diff = max_ - min_;
  int dp[2 *(diff+1)][s];
  for(int i=0;i<diff;i++)
    for(int j=0;j<s;j++)
      dp[i][j] = 1;

  for(int i =1;i<s;i++) {
    for(int j=0;j<i;j++) {
      int d = arr[i] - arr[j];
      if(d >= 0) {
        dp[d][i] = dp[d][i] + dp[d][j];
      }
      if(d < 0) {
        dp[abs(d)+diff+1][i] += dp[abs(d)+diff+1][j];
      }
    }
  }

  int ans = -1;
  for(int i=0;i<diff;i++)
    for(int j=0;j<s;j++)
      if(dp[i][j] > ans) ans = dp[i][j];

  return ans;
}

int main() {
  //vector<int> arr = {9,4,7,2,10};
  vector<int> arr = {3,6,9,12};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
