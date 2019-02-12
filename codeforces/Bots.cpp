#include<iostream>
#include<math.h>

using namespace std;

int N;
int div_ = 1000000007;

long long cal(int n1,int n2)
{
  long long cnt = 0;
  if(n1==0 && n2==0)
    return 1;

  if(n1==n2)
  {
    cnt+=(2*cal(n1-1,n2)+1)%div_;
  }
  else
  {
    if(n1>0 && n2>0)
    {
      cnt+=(((cal(n1-1,n2))+(cal(n1,n2-1))) + 1)%div_;
    }
    else if(n1>0 && n2==0)
    {
      cnt+=(cal(n1-1,n2)+1)%div_;
    }
    else if(n1==0 && n2>0)
    {
      cnt+=(cal(n1,n2-1)+1)%div_;
    }
  }
  return cnt;
}

int main()
{
  cin>>N;
  long long ans = 0;
  ans = cal(N,N);
  cout<<ans<<endl;
  return 0;
}


