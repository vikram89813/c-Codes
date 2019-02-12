#include<iostream>

using namespace std;

double findMedianSortedArrays(int arr1[], int n,int arr2[],int m) {
  int idx_l=0;
  int idx_r = n;
  int med = 0;
  int i,j;
  while(idx_l<=idx_r) {
    i = (idx_l + idx_r)/2;
    j = ((n+m+1)/2) - i;
    if(i<n && j>0 && arr2[j-1] > arr1[i]) idx_l = i+1;
    else if(i>0 && j<m && arr1[i-1] > arr2[j]) idx_r = i-1;
    else {
      if(i==0) med = arr2[j-1];
      else if(j==0) med = arr1[i-1];
      else med = max(arr1[i-1],arr2[j-1]);
      break;
    }
  }
  if((n+m) %2) return (double)med;
  if(i==n) return (med + arr2[j])/2.0;
  else if(j==m) return (med+arr1[i])/2.0;
  else return (med + min(arr1[i],arr2[j])) / 2.0;
}

int main()
{
    int a[] = {900};
    int b[] = { 10, 13, 14};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);
    if (n < m)
        cout << "The median is : "
             << findMedianSortedArrays(a, n, b, m) <<endl;
    else
        cout << "The median is : "
             << findMedianSortedArrays(b, m, a, n)<<endl;
    return 0;
}
