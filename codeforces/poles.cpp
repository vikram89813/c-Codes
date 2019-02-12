#include<iostream>
using namespace std;
#define MAX 9999999999999
long long int dp[5001][5001],n,k,i,j,weight[5001],alt[5001],cost[5001][5001],g_ans=MAX;
void print()
{
int i,j;	
for(i=0;i<n;i++)
{
	cout<<alt[i]<<"------------>"<<weight[i]<<"\n";
}

cout<<"COST..\n\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<cost[i][j]<<"  ";
		}
		cout<<"\n";
	}
cout<<"DP : \n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<k;j++)
		{
			cout<<dp[i][j]<<"  ";
		}
		cout<<endl;
	}


}
//dp[i][j]= need to add kth pole at index i.
void rec()
{
	int counter=0,l;
	for(i=n-1;i>=k-1;i--)
		dp[i][k-1]=cost[i][n-1];
//	cout<<"\nBEFORE:\n";
//	print();
//	cout<<"AFTER:\n";


	for(j=k-2,counter=1;j>=0;j--,counter++)
	{
//		cout<<"CASE TO PUT POLE AT: "<<j<<endl;
		for(i=n-counter-1;i>=j;i--)
		{
//		cout<<"\tIN ROW: "<<i<<endl;
			dp[i][j]=MAX;
			for(l=i+1;l<=n-counter;l++)
			{
//			cout<<"\t\tIN l: "<<l<<" checking if(dp["<<i<<"]["<<j<<"]>cost["<<i<<"]["<<l-1<<"]+dp["<<l<<"]["<<j+1<<"])"<<endl;
				if(dp[i][j]>cost[i][l-1]+dp[l][j+1])
					dp[i][j]=cost[i][l-1]+dp[l][j+1];
			}
		}
	}
//	print();

}
int main()
{

	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>alt[i]>>weight[i];
	
//calculating cost matrix
//[i][j] indicate pole at ith is starting and pole till jth have converged on i

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==j)
				cost[i][j]=0;
			else
			{
				cost[i][j]=cost[i][j-1]+(weight[j]*(alt[j]-alt[i]));

			}
		}
	}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		dp[i][j]=-1;
}
rec();
cout<<dp[0][0]<<"\n";
//cout<<"\n\n";

	return 0;
}


