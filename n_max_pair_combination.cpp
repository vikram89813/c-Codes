#include<bits/stdc++.h>

using namespace std;

vector<int> func(vector<int> &a,vector<int> &b, int k)
{
  priority_queue<pair<int,pair<int,int>>> q;
  set<pair<int,int>> s;

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  int n = a.size();

  q.push(make_pair(a[n-1]+b[n-1],make_pair(n-1,n-1)));
  s.insert(make_pair(n-1,n-1));
  vector<int> ans;

  while(k--) {
    pair<int,pair<int,int>> temp = q.top();
    q.pop();
    ans.push_back(temp.first);

    int l = temp.second.first;
    int r = temp.second.second;

    if(l>0 && r>=0 && s.find(make_pair(l-1,r)) == s.end())
    {
      q.push(make_pair(a[l-1]+b[r], make_pair(l-1,r)));
      s.insert(make_pair(l-1,r));
    }
    if(l>=0 && r>0 && s.find(make_pair(l,r-1)) == s.end())
    {
      q.push(make_pair(a[l]+b[r-1], make_pair(l,r-1)));
      s.insert(make_pair(l,r-1));
    }
  }

  return ans;
}

int main()
{
  vector<int> a = {1,4,2,3};
  vector<int> b = {2,5,1,6};
  vector<int> res = func(a,b,4);
  for(auto i : res) cout<<i<<" ";
  cout<<endl;
  return 0;
}
