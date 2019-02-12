#include<iostream>

using namespace std;

int dp[1<<24][3];
int d[25][25];
int x[25];
int y[25];
int INF = 1000000007;

int sqr(int x)
{
  return x*x;
}

int main()
{
  int xx,yy,n;
  cin>>xx>>yy>>n;
  for(int i=0;i<n;i++)
    cin>>x[i]>>y[i];

  x[n] = xx;y[n] = yy;
  for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      d[i][j] = sqr(x[j]-x[i]) + sqr(y[j]-y[i]);

  for(int i=1;i<(1<<n);i++)
    dp[i][0] = INF;

  dp[0][1] = -1;

  for(int i = 0;i<(1<<n);i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i&(1<<j)) continue;
      for(int k=j;k<n;k++)
      {
        if(i & (1<<k)) continue;
        int t = i | (1<<j) | (1<<k);
        if(dp[t][0] > dp[i][0] + d[n][j] + d[j][k] + d[k][n])
        {
          dp[t][0] = dp[i][0] + d[n][j] + d[j][k] + d[k][n];
          dp[t][1] = j;
          dp[t][2] = k;
        }
      }
      break;
    }
  }

  int temp = (1<<n) - 1;
  cout<<dp[temp][0]<<endl;
  cout<<"0 ";
  while(dp[temp][1] >=0)
  {
    if(dp[temp][2] != dp[temp][1])
      cout<<dp[temp][2] + 1<<" ";

    cout<<dp[temp][1] + 1<<" 0 ";
    temp = temp ^ ((1<<dp[temp][2]) | (1<<dp[temp][1]));
  }
  cout<<endl;
  return 0;
}
