#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int sol(vector<int> &a, vector<int> &b, vector<int> &c)
{
  if(a.size()==0 || b.size()==0 || c.size() == 0) return 0;
  int i=0,j=0,k=0;
  int ans = INT_MAX;
  while(i<a.size()&&j<b.size()&&k<c.size())
  {
    int t1 = a[i];
    int t2 = b[j];
    int t3 = c[k];
    int m1 = min(t1,min(t2,t3));
    int m2 = max(t1,max(t2,t3));
    int temp = m2-m1;
    if(temp < ans) ans = temp;
    if(m1 == t1)i++;
    if(m1 == t2)j++;
    if(m1 == t3)k++;
  }
  return ans;
}

int main()
{
  vector<int> a = {1,4,5,8,10};
  vector<int> b = {6,9,15};
  vector<int> c = {2,3,6,6};
  int res = sol(a,b,c);
  cout<<res<<endl;
  return 0;
}
