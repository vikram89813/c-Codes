#include<bits/stdc++.h>
using namespace std;

int N,K;
long long dp[2002][2002];

int main()
{
  cin>>N>>K;
  for(int i=0;i<=N;i++)
    dp[i][1] = 1;

  for(int k=2;k<=K;k++)
    for(int i=1;i<=N;i++)
      for(int j=i;j<=N;j+=i)
       dp[i][k] = (dp[i][k] + dp[j][k-1])%1000000007;

  long ans = 0;
  for(int i=1;i<=N;i++)
    ans=(ans+dp[i][K])%1000000007;

  cout<<ans<<endl;
  return 0;
}
