#include<iostream>

using namespace std;

int arr1[n];
int arr2[n];

void maxLen(int *arr, int n) {
  int z_c =0;
  int o_c =0;
  for(int i=0;i<n;i++) {
    if(arr[i] == 0) arr1[i] = ++z_c;
    else arr1[i] = z_c;
  }
  for(int i=0;i<n;i++) {
    if(arr[i] == 1) arr2[i] = ++o_c;
    else arr2[i] = o_c;
  }
}

int main()
{
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxLen(arr, n);
    return 0;
}

