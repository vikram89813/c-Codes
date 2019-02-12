#include<bits/stdc++.h>
using namespace std;

long long n,k,a,b,x,y,i,dp[100005];

int main(){
	cin>>n>>k;

	for(i =0;i<100005;i++)
    {
		if(i<k)
          dp[i]=1;
		else
          dp[i]=(dp[i-1]+dp[i-k])%1000000007;
	}
	for(i=0;i<100005;i++)
    {
		dp[i]=(dp[i]+dp[i-1])%1000000007;
	}
	while(i<n)
    {
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1]+1000000007)%1000000007<<"\n";
		i++;
	}
    return 0;
}
