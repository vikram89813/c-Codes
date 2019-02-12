#include<iostream>

using namespace std;

int N;
int arr[10];
int arr1[10];
int arr2[10];

void merge(int arr[],int l,int m,int r) {
  int l1 = m-l+1;
  int l2 = r-m;
  for(int i=0;i<l1;i++) arr1[i] = arr[l+i];
  for(int i=0;i<l2;i++) arr2[i] = arr[m+i+1];

  int i=0;
  int j =0;
  int k =l;
  while(i<l1 && j<l2) {
    if(arr1[i] <= arr2[j]) {arr[k] = arr1[i];i++;k++;}
    else {arr[k] = arr2[j];j++;k++;}
  }

  if(i<l1) {arr[k] = arr1[i];i++;k++;}
  if(j<l2) {arr[k] = arr2[j];j++;k++;}
}

void sort_(int arr[],int l,int r) {
  if(l<r) {
    int m = l + (r-l)/2;
    sort_(arr,l,m);
    sort_(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

int main() {
  cin>>N;
  for(int i =0;i<N;i++) cin>>arr[i];
  sort_(arr,0,N-1);
  for(auto i : arr) cout<<i<<" ";
  cout<<endl;
  return 0;
}
