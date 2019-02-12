#include<bits/stdc++.h>

using namespace std;

/*vector<int> func(vector<int> &arr, int n) {
  if(arr.empty()) return vector<int>();
  vector<int> ans;

  vector<pair<int,int>> narr;
  int prev = INT_MAX;
  for(int i=0;i<arr.size();i++) {
    if(arr[i] < prev) narr.push_back(make_pair(i,arr[i])),prev = arr[i];
  }


  int s = narr.size();
  int t = narr[s-1].second;
  int R = n;


  int i = 0;
  while(i<s) {
    if(narr[i].second <= R && 1 + (R - narr[i].second)/t == R/t) ans.push_back(narr[i].first),R -= narr[i].second;
    else i++;
  }
  return ans;
}*/

vector<int> func(vector<int> &arr, int n) {
  if(arr.empty()) return vector<int>();
  vector<int> ans;

  auto t = min_element(arr.begin(),arr.end());
  int idx = t-arr.begin();
  int min_e = *t;

  int i = 0;
  while(i <= idx) {
    if(arr[i] <= n && 1 + (n-arr[i])/min_e == n/min_e) ans.push_back(i), n-=arr[i];
    else i++;
  }

  return ans;
}

int main() {
  //vector<int> arr = {6, 8, 5, 4, 7};
  vector<int> arr = {8, 8, 6, 5, 4};
  int n = 12;
  vector<int> ans = func(arr,n);
  for(auto i : ans) cout<<i<<" ";
  cout<<endl;
  return 0;
}
