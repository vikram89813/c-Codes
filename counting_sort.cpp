#include<iostream>
using namespace std;

#define RANGE 10

void countSort(int arr[])
{
	int output[RANGE];
	int count[RANGE+1], i;
    fill(count,count+11,0);

	for(i = 0; i<7; ++i)
		++count[arr[i]];

	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i-1];

	for (i = 6; i>=0; i--)
	{
		output[count[arr[i]]-1] = arr[i];
		--count[arr[i]];
	}

	for (i = 0; arr[i]; ++i)
		arr[i] = output[i];
}

int main()
{
    int arr[] = {1, 4, 1, 2, 7, 5, 2};
	countSort(arr);
    for(auto i : arr) cout<<i<<" ";
    cout<<endl;
	return 0;
}

