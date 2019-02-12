#include<bits/stdc++.h>

using namespace std;

int func(vector<int> &arr) {
  vector<int> rev(arr);
  reverse(rev.begin(),rev.end());
  int s = arr.size();
  if(s < 3) return 0;

  vector<int> lis1(s,1);
  vector<int> lis2(s,1);
  int ans = 0;

  for(int i=1;i<s;i++) {
    for(int j =0;j<i;j++) {
      if(arr[i] > arr[j]) {
        if(lis1[j] + 1 > lis1[i]) lis1[i] = lis1[j] + 1;
      }
    }
  }

  for(int i=1;i<s;i++) {
    for(int j =0;j<i;j++) {
      if(rev[i] > rev[j]) {
        if(lis2[j] + 1 > lis2[i]) lis2[i] = lis2[j] + 1;
      }
    }
  }

  reverse(lis2.begin(),lis2.end());
  for(int i =0;i<s;i++) {
      int t = lis1[i] + lis2[i] -1;
      if(ans < t)ans = t;
  }
  return ans;
}

int main()
{
  vector<int> arr = {1,11,2,10,4,5,2,1};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
