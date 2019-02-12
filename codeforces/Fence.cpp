#include<stdio.h>
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;

int min_val = 999999;
int idx = -1;
vector<int> arr;
int n,k;

void printKMax()
{
	int j, min_;

	for (int i = 0; i <= n-k; i++)
	{
        vector<int>::iterator it = arr.begin();
        advance(it,i);
        vector<int>::iterator it_ = it;
        advance(it_,k);
        int sum = accumulate(it, it_, 0);
        min_ = sum;
		if(min_ <= min_val)
		{
		  min_val = min_;
		  idx = i+1;
		}
	}
}

int main()
{
    cin>>n>>k;
    int temp;
    for(int i=0;i<n;i++)
    {
      scanf("%d",&temp);
      arr.push_back(temp);
    }
	printKMax();
    cout<<idx<<endl;
	return 0;
}

