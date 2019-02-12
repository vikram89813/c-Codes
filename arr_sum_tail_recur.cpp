#include<iostream>

using namespace std;

int arrSum(int *arr,int size,int idx=0,int sum=0) {
  if(idx==size) return sum;
  return arrSum(arr,size,idx+1,sum + arr[idx]);
}

int main() {
    int array[] = { 2, 55, 1, 7 };
    int size = sizeof(array) / sizeof(array[0]);
    cout << arrSum(array, size);
    return 0;
}
