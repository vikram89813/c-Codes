#include<iostream>
#include<algorithm>

using namespace std;

long long int n,m,k,p=1000000007,c[2001][2001];

int main()
{
        cin>>n>>m>>k;
	for(int i=0;i<max(n,m);i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000007;
	}
        long long ans;
        if(2*k > max(n,m))
        {
          ans = 0;  
        }
        else
        {
           ans = ((c[n-1][2*k])%1000000007*(c[m-1][2*k]%1000000007))%1000000007;
        }
        cout<<ans<<endl;
	return 0;
}
