#include<iostream>

using namespace std;

int N;
int arr[100001];
int arr1[100001];
int arr2[100001];
long long ans;

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

void cal() {
  int i=0;
  int j=N-1;
  while(i<j) {
    ans+=arr[i];
    i+=2;
    j--;
  }
}

int main() {
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    ans = 0;
    cin>>N;
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    sort_(arr,0,N-1);
    cal();
    long long s=0;
    for(int i=0;i<N;i++) s+=arr[i];
    ans = s-ans;
    cout<<"#"<<t<<" "<<ans<<endl;
  }
  return 0;
}

