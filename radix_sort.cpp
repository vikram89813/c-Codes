#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void countSort(vector<int> &arr, int exp,int n)
{
	int output[n];
	int i, count[10] = {0};

	for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
		count[ (arr[i]/exp)%10 ]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixsort(vector<int> &arr)
{
	int m = *max_element(arr.begin(),arr.end());
    int n = arr.size();

	for (int exp = 1; m/exp > 0; exp *= 10)
		countSort(arr,exp,n);
}

int main()
{
	vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
	radixsort(arr);
	for(auto i : arr) cout<<i<<" ";
    cout<<endl;
	return 0;
}

