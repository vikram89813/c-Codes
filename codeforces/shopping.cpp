#include<iostream>

using namespace std;

int n,m,k;
int arr[102];

void shuffle(int index)
{
	int num=arr[index];
	for(int i=index;i>1;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[1]=num;	
}

int find_time(int num)
{
	int index=0;
	for(int i=1;i<=k;i++)
	{
		if(arr[i]==num)
		{
			index=i;
			break;
		}
	}
	shuffle(index);
	return index;
}

int main()
{
	cin>>n>>m>>k;
	int num;
	int time=0;
	int temp;
	for(int i=1;i<=k;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>num;
			temp=find_time(num);
			time+=temp;
		}
	}
	cout<<time<<endl;
	return 0;
}
