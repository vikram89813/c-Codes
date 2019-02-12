#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

int lps(string s)
{
  int len = 0;
  vector<int> lps_(s.size(),0);
  int i = 1;
  lps_[0] = 0;
  while(i < s.size())
  {
    if(s[i] == s[len])
    {
      len++;
      lps_[i] = len;
      i++;
    }
    else {
      if(len != 0)
      {
        len = lps_[len-1];
      }
      else {
        lps_[i] = 0;
        i++;
      }
    }
  }
  return lps_.back();
}

int solve(string &str)
{
  if(str.size()==0) return 0;
  string c = str;
  int l = str.size();
  reverse(str.begin(),str.end());
  c = c + '$' + str;
  int v = lps(c);
  return (l-v);
}

int main()
{
  string str = "AACECAAAA";
  int res = solve(str);
  cout<<res<<endl;
  return 0;
}
