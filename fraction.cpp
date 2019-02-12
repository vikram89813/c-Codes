#include<bits/stdc++.h>

using namespace std;

string cal(int n,int d)
{
  if(n==0) return "0";

  string res;
  if(n<0 || d<0) res+='-';

  n = abs(n);
  d = abs(d);
  res+=to_string((n/d));

  if(n%d == 0) return res;

  res+='.';

  unordered_map<int,int> hash_;
  for(int r = n%d; r>0; r = r%d)
  {
    if(hash_.find(r) != hash_.end())
    {
      res.insert(hash_[r],1,'(');
      res+=')';
      break;
    }
    hash_[r] = res.size();
    r = r*10;
    res.push_back((char)('0' + (r/d)));
  }
  return res;
}

int main()
{
  int a = 9;
  int b = 2;

  string res = cal(a,b);
  cout<<res<<endl;
  return 0;
}
