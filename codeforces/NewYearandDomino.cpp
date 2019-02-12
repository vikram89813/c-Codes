#include<bits/stdc++.h>
using namespace std;

int h,w,q,r[509][509]={},c[509][509]={};
string a[509];

int main()
{
	cin>>h>>w;
	for(int i=0;i<h;i++)
		cin>>a[i];

	for(int i=0;i<h;i++)
		for(int j=1;j<w;j++)
			r[i][j]=r[i][j-1]+(a[i][j]=='.' && a[i][j-1]=='.');

	for(int j=0;j<w;j++)
		for(int i=1;i<h;i++)
			c[i][j]=c[i-1][j]+(a[i][j]=='.' && a[i-1][j]=='.');

	cin>>q;
	int x,y,x1,y1;
	while(q--)
	{
		long long ans=0;
		cin>>x>>y>>x1>>y1;
		x--,x1--,y--,y1--;
		for(int i=x;i<=x1;i++)
			ans+=r[i][y1]-r[i][y];

		for(int j=y;j<=y1;j++)
			ans+=c[x1][j]-c[x][j];

		cout<<ans<<endl;
	}
	return 0;
}
