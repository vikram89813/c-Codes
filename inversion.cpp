#include<iostream>

using namespace std;

int arr[100005];
int arr2[100005];
int arr3[100005];
int arr4[100005];
int bit[100005];
int N;
long long ans;

void merge(int arr[],int l,int m,int r) {
  int l1 = m-l + 1;
  int l2 = r-m;

  for(int i=0;i<l1;i++) arr2[i] = arr[l+i];
  for(int i=0;i<l2;i++) arr3[i] = arr[m+i+1];
  int i= 0;
  int j=0;
  int k = l;
  while(i < l1 && j<l2) {
    if(arr2[i] <= arr3[j]) {arr[k] = arr2[i];i++;}
    else {
      arr[k] = arr3[j];j++;
    }
    k++;
  }
  while(i<l1) {arr[k] = arr2[i];i++;k++;}
  while(j<l2) {arr[k] = arr3[j];j++;k++;}
}

void sort_(int arr[], int l,int r) {
  if(l<r) {
    int m = l+(r-l)/2;
    sort_(arr,l,m);
    sort_(arr,m+1,r);
    merge(arr,l,m,r);
  }
}

int binary_s(int arr[], int l, int r, int term)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == term)
            return mid;
        if (arr[mid] > term)
            return binary_s(arr, l, mid-1, term);
        return binary_s(arr, mid+1, r, term);
   }
}

long long get_s(int idx) {
  long long s =0;
  while(idx > 0) {
    s += bit[idx];
    idx-= idx & (-idx);
  }
  return s;
}

void update(int idx,int v) {
  while(idx<=N) {
    bit[idx] += v;
    idx += idx & (-idx);
  }
}

void cal() {
  sort_(arr4,0,N-1);
  for(int i =0;i<N;i++) {
    arr[i] = binary_s(arr4,0,N-1,arr[i]) + 1;
  }
  for(int i =0;i<N+1;i++) bit[i] = 0;
  for(int i = N-1;i>=0;i--) {
    ans+= get_s(arr[i] -1);
    update(arr[i],1);
  }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input_inv", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
      cin>>N;
      ans = 0;
      for(int i =0;i<N;i++) {cin>>arr[i];}
      for(int i =0;i<N;i++) {arr4[i] = arr[i];}
      cal();
      cout<<"#"<<test_case<<" "<<ans<<endl;
	}
	return 0;
}
