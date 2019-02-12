#include<iostream>
using namespace std;
int g_ans,a[11],n;
int find_score(int index,bool explode[])
{
	int left_index=index-1,right_index=index+1,score=0;
	while(left_index>=0 && explode[left_index]==true)
		left_index--;
	
	while(right_index<n && explode[right_index]==true)
		right_index++;

	if(right_index==n && left_index==-1)
		score=a[index];
	else if(right_index==n && left_index!=-1)
		score=a[left_index];
	else if(right_index!=n && left_index==-1)
		score=a[right_index];
	else if(right_index!=n && left_index!=-1)
		score=a[left_index]*a[right_index];

	return(score);
}
void recurse(int sum_till_now,int leftover,bool explode[])
{
	
	if(leftover==0)
	{
		if(sum_till_now>g_ans)
			g_ans=sum_till_now;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(explode[i]==false)
			{
				int temp=find_score(i,explode);
				explode[i]=true;
				recurse(sum_till_now+temp,leftover-1,explode);
				explode[i]=false;
			}
		}
	}	
}

int main()
{
	int t,T;
	cin>>t;
	T=t;
	while(t--) //for each test case
	{
		g_ans=0;
		bool explode[11];
		cin>>n;
		for(int i=0;i<n;i++)
		{	
			cin>>a[i];
			explode[i]=false;
		}
		recurse(0,n,explode);
		cout<<"# "<<T-t<<" "<<g_ans<<"\n";
	}

	return 0;
}
