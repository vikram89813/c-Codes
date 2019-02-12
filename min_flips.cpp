#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dp;

int func(vector<int> &arr){
  int n = arr.size();
  if(n==0) return 0;
  int sum_ = 0;
  int ans = n+1;
  for(auto i : arr) sum_+=i;
  dp.resize(n+1,vector<int>(n+1,sum_));
  ans = sum_ +1;
  int curr_min=sum_+1;

  for(int i =1;i<=n;i++) {
    for(int j = 0;j<n;j++) {
      if(i==1) {
        int t = dp[j][i-1] - 2*arr[j];
        if(t > 0) {
          dp[j][i] = t;
         if(t < curr_min) ans = i,curr_min=t;
        }
      }
      else {
        for(int k = 0;k<j;k++) {
          int t = dp[k][i-1] - 2*arr[j];
          if(t > 0) {
            dp[j][i] = min(dp[j][i],t);
            if(t < curr_min) ans = i,curr_min=t;
          }
          else {
            dp[j][i] = min(dp[j][i-1],dp[j][i]);
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  //vector<int> arr = {15,10,6};
  //vector<int> arr = {14,10,4};
  //vector<int> arr = {1,2,3,8};
  vector<int> arr = { 8, 4, 5, 7, 6, 2};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
