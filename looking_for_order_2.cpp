#include<iostream>
#include<cmath>

using namespace std;

int dp[1<<24];
int d[25][25];
int x[25];
int y[25];
int INF = 1000007;
int N;

int main() {
  int hx,hy;

  //inputs
  cin>>hx>>hy>>N;
  for(int i=0;i<N;i++)
    cin>>x[i]>>y[i];

  // base case settings
  x[N] = hx;y[N] = hy;
  for(int i=0;i<=N;i++)
    for(int j=0;j<=N;j++)
      d[i][j] = pow((x[j]-x[i]),2) + pow((y[j]-y[i]),2);

  for(int i=1;i<(1<<N);i++)
    dp[i] = INF;

  //solution
  for(int i = 0;i<(1<<N);i++) {
    for(int j=0;j<N;j++) {
      if(i&(1<<j)) continue;
      for(int k=j;k<N;k++) {
        if(i & (1<<k)) continue;
        // new state
        int t = i | (1<<j) | (1<<k);
        if(dp[t] > dp[i] + d[N][j] + d[j][k] + d[k][N])
          dp[t] = dp[i] + d[N][j] + d[j][k] + d[k][N];
      }
    }
  }

  int temp = (1<<N) - 1;
  cout<<dp[temp]<<endl;
}

