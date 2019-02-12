#include<iostream>
#include<math.h>

using namespace std;

int N;
int div_ = 1000000007;
long long dp[1000][1000];

long long cal(int n1,int n2)
{
  long long cnt = 0;
  if(n1==0 && n2==0)
    return 1;

if(n1<=999 && n2<=999)
{
  if(dp[n1][n2])
    return dp[n1][n2];
}

  if(n1==n2 && n1<=999 && n2<=999)
  {
    dp[n1][n2] += (2*cal(n1-1,n2)+1)%div_;
    cnt+=dp[n1][n2];
  }
  else if(n1==n2 && (n1>999 || n2>999))
  {
    cnt+=(2*cal(n1-1,n2)+1)%div_;
  }
  else if(n1!=n2 && n1<=999 && n2<=999)
  {
    if(n1>0 && n2>0)
    {
      dp[n1][n2]+=(((cal(n1-1,n2))+(cal(n1,n2-1))) + 1)%div_;
      cnt+=dp[n1][n2];
    }
    else if(n1>0 && n2==0)
    {
      dp[n1][n2]+=(cal(n1-1,n2)+1)%div_;
      cnt+=dp[n1][n2];
    }
    else if(n1==0 && n2>0)
    {
      dp[n1][n2]+=(cal(n1,n2-1)+1)%div_;
      cnt+=dp[n1][n2];
    }
  }
  else if(n1!=n2 && (n1>999 || n2>999))
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
  if(n1<=999 && n2<=999)
  {
    return dp[n1][n2] = cnt;
  }
  else
    return cnt;
}

int main()
{
  cin>>N;
  long long ans = 0;
  if(N>999)
    ans = cal(999,999);

  ans = cal(N,N);
  cout<<ans<<endl;
  return 0;
}


