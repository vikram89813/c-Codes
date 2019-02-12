#include<bits/stdc++.h>

using namespace std;

int func(vector<vector<int>> &arr) {
  if(arr.empty()) return 0;
  int ans = 0;
  for(int i =1;i<arr.size();i++)
    for(int j=0;j<arr[i].size();j++) {
      if(arr[i][j] == 1) arr[i][j] += arr[i-1][j];
    }

  for(int i=0;i<arr.size();i++) sort(arr[i].begin(),arr[i].end());
  for(int i=0;i<arr.size();i++)
  {
    int n=arr[i].size();
    for(int j=n-1;j>=0;j--)
    {
      int t = arr[i][j] *(n-j);
      if(t > ans) ans = t;
    }
  }
  return ans;
}

int main()
{
  vector<vector<int>> arr = {{1,0,1},{0,1,0},{1,0,0}};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
