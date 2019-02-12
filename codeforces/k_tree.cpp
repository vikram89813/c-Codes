#include<iostream>

using namespace std;

int N,K,D;
long long dp[101][2];

int main()
{
  cin>>N>>K>>D;
  dp[0][0] = 1;

  for(int i=1;i<=N;i++)
    for(int j=1;j<=min(i,K);j++)
      ((dp[i][0] += dp[i-j][0])%=1000000007,(dp[i][1] += dp[i-j][j<D])%=1000000007);

  cout<<dp[N][1]<<endl;
  return 0;
}
