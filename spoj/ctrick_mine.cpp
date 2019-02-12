#include<bits/stdc++.h>

using namespace std;

#define MAX  20005

int arr[MAX];
int bit[MAX];
int N;

void update(int idx,int v) {
  while(idx<=N) {
    bit[idx] += v;
    idx+= idx & (-idx);
  }
}

int get_s(int idx) {
  int s = 0;
  while(idx>0) {
    s+=bit[idx];
    idx-= idx & (-idx);
  }
  return s;
}

int main() {
  int T;
  cin>>T;
  while(T--) {
    fill(arr,arr+MAX,0);
    fill(bit,bit+MAX,0);
    cin>>N;
    for(int i=1;i<=N;i++) update(i,1);
    int L=1;
    int M=N;
    for(int i =1;i<=N;i++) {
      L = (L+i)%M;
      L = (!L)?M:L;
      M--;
      int s=1,e=N;
      while(s<=e) {
        int mid = (s+e)/2;
        if(get_s(mid) >= L) e=mid-1;
        else s=mid+1;
      }
      arr[s] = i;update(s,-1);
    }
    for(int i =1;i<=N;i++) cout<<arr[i]<<" ";
    cout<<endl;
  }
}
