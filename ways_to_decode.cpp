#include<bits/stdc++.h>

using namespace std;

int helper(string &s,int idx,vector<int> &arr) {
  if(idx == s.size()) return 1;
  if(idx > s.size() || (isdigit(s[idx]) && (s[idx]-'0' < 1))) return 0;
  if(arr[idx] != -1) return arr[idx];

  int ans = 0;
  ans += helper(s,idx+1,arr);
  if(idx < s.size()-1 && (((s[idx] - '0') *10 + s[idx+1]-'0') <= 26 ))
    ans+=helper(s,idx+2,arr);

  arr[idx] = ans;
  return ans;
}

int func(string &str) {
  if(str.size() == 0) return 0;
  vector<int> arr(str.size(),-1);
  int ans = helper(str,0,arr);
  return ans;
}

int main()
{
  string str = "1234567890";
  int ans = func(str);
  cout<<ans<<endl;
  return 0;
}
