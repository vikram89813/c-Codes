#include<bits/stdc++.h>

using namespace std;

int minDeletionSize(vector<string>& arr) {
  int s = arr.size();
  int s_ = arr[0].size();
  int ans = 0;
  while(s_ > 0) {
    int res = is_sorted_until(arr.begin(),arr.end()) - arr.begin();
    if(res == s) return ans;
    ans++;
    int i = res-1;
    int s1 = arr[0].size();
    int j=0;
    for( ;j<s1;j++) {
      if(arr[i][j] != arr[res][j] && arr[i][j] > arr[res][j]) break;
    }
    s_ = s_ - (j+1);
    for(int k=0;k<arr.size();k++) arr[k].erase(j,1);
  }
  return ans;
}

int main() {
  //vector<string> arr = {"xga","xfb","yfa"};
  vector<string> arr = {"ca","bb","ac"};
  cout<<minDeletionSize(arr)<<endl;
  return 0;
}
