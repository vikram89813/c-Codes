#include<bits/stdc++.h>

using namespace std;

int func(vector<vector<int>> &arr) {
  vector<vector<int>> pre(arr.size(),vector<int> (arr[0].size(),0));
  for(int i =0;i<pre.size();i++) {
    for(int j=0;j<pre[0].size();j++) {
      pre[i][j] = arr[i][j];
      if(i) pre[i][j] += pre[i-1][j];
      if(j) pre[i][j] += pre[i][j-1];
      if(i && j) pre[i][j] -= pre[i-1][j-1];
    }
  }

  int ans =0;
  for(int r1 =0;r1 < arr.size();r1++) {
    for(int r2 =r1;r2<arr.size();r2++) {
      unordered_map<int,int> hash_;
      hash_[0]=1;
      for(int j =0;j<arr[r2].size();j++) {
        int  temp = pre[r2][j];
        if(r1) temp -= pre[r1-1][j];
        ans+=hash_[-temp];
        hash_[temp]++;
      }
    }
  }
  return ans;
}

int main() {
  vector<vector<int>> arr = {{-8,5,7},{3,7,-8},{5,-8,9}};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
