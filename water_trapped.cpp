#include<bits/stdc++.h>

using namespace std;

int func(vector<int> &arr) {
  bool flag = false;
  if(arr[0] == 0) flag = true;

  stack<pair<int,int>> s;
  int i;
  int n = arr.size();
  int ans=0;
  if(flag) s.push(make_pair(1,arr[1])),i=2;
  else s.push(0,arr[0]),i=1;

  while(i<n) {
    if(arr[i] < s.top() || s.empty()) s.push(make_pair(i,arr[i])),i++;
    else {
      while()
      pair<int,int> temp = s.top();
      s.pop();
       
    }
  }

  return ans;
}

int main() {
  vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
