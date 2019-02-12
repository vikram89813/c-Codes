#include<bits/stdc++.h>

using namespace std;

#define N 8

int arrL[N];
int arrR[N];

int cal(int arr[]) {
  int ans =-1;
  arrL[0] = arr[0];
  arrR[N-1] = arr[N-1];
  for(int i=1;i<N;i++) arrL[i] = max(arr[i],arrL[i-1]);
  for(int i=N-2;i>=0;i--) arrR[i] = min(arr[i],arrR[i+1]);
  int i=0;
  int j=0;
  while (i < N && j < N) {
    if (arrL[i] > arrR[j]) {
      ans = max(ans, j-i);
      j++;
    } else i++;
  }
  return ans+1;
}

int main() {
  int arr[] = {2,13,4,7,10,100,110,5};
  cout<<cal(arr)<<endl;
  return 0;
}
