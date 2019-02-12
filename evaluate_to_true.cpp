#include<bits/stdc++.h>

using namespace std;

#define mod 1003

map<pair<int,int>,int> true_;
map<pair<int,int>,int> false_;

int tr(string str,int s,int e);
int fa(string str,int s,int e);

int tr(string str, int s,int e) {
  if(s>e) return 0;
  if(s==e) return str[s] == 'T';
  if(true_.count(make_pair(s,e))) return true_[make_pair(s,e)];

  int ans = 0;
  for(int i=s;i<e;i++) {
    if(str[i] == '|')
      ans = ans + (tr(str,s,i-1) * tr(str,i+1,e)) + (tr(str,s,i-1) * fa(str,i+1,e)) + (fa(str,s,i-1) * tr(str,i+1,e));
    if(str[i] == '&')
      ans+= (tr(str,s,i-1) * tr(str,i+1,e));
    if(str[i] == '^')
      ans+= (tr(str,s,i-1) * fa(str,i+1,e)) + (fa(str,s,i-1) * tr(str,i+1,e));
  }
  ans = ans % mod;
  return true_[make_pair(s,e)] = ans;
}

int fa(string str, int s,int e) {
  if(s>e) return 0;
  if(s==e) return str[s] == 'F';
  if(false_.count(make_pair(s,e))) return false_[make_pair(s,e)];

  int ans = 0;
  for(int i=s;i<e;i++) {
    if(str[i] == '|')
      ans = ans + (fa(str,s,i-1) * fa(str,i+1,e));
    if(str[i] == '&')
      ans+= (fa(str,s,i-1) * fa(str,i+1,e)) + (tr(str,s,i-1) * fa(str,i+1,e)) + (fa(str,s,i-1) * tr(str,i+1,e));
    if(str[i] == '^')
      ans+= (tr(str,s,i-1) * tr(str,i+1,e)) + (fa(str,s,i-1) * fa(str,i+1,e));
  }

  ans = ans % mod;
  return false_[make_pair(s,e)] = ans;
}

int func(string str) {
  if(str.size() == 0) return 0;
  int n = str.size()-1;
  true_.clear();
  false_.clear();
  int ans = 0;
  ans = tr(str,0,n);
  return ans;
}

int main() {
  string str = "F|T^T&F";
  int ans = func(str);
  cout<<ans<<endl;
  return 0;
}
