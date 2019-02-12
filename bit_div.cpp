#include<iostream>

using namespace std;

int div_(int a1,int b1)
{
  long long ans = 0,q=0;
  long long a = a1,b=b1;
  for(long long i =31;i>=0;i--)
  {
    if((b<<i) <= a-ans)
    {
      ans += (b<<i);
      q|=(1LL<<i);
    }
  }
  return q;
}

int main()
{
  int a=19;
  int b = 5;
  long long res = div_(a,b);
  cout<<res<<endl;
  return 0;
}
