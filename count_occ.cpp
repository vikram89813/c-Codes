#include<iostream>

using namespace std;

int ans = 0;
int test = 0;

void countOccurrences(int *arr, int l,int h , int x) {
  if(l<=h) {
    if(arr[l] == arr[h]) {
      if(arr[l] == x) {
        ans+= ((h-l) + 1);
      }
    }
    else {
      int m = l + (h-l)/2;
      countOccurrences(arr,l,m,x);
      countOccurrences(arr,m+1,h,x);
    }
  }
}

int main() {
    int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    countOccurrences(arr, 0, n-1, x);
    cout<<ans<<endl;
    return 0;
}
