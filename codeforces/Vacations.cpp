#include<bits/stdc++.h>
using namespace std;

int dp[110][3],n;

int main()
{
	cin>>n;
	for (int i=1,x;i<=n;i++)
	{
		cin>>x;

		dp[i][0]=max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2]));

		if (x==1 || x==3)
          dp[i][1]=max(dp[i-1][0],dp[i-1][2])+1;

		if (x==2 || x==3)
          dp[i][2]=max(dp[i-1][0],dp[i-1][1])+1;
	}
	cout<<n-max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
    return 0;
}
