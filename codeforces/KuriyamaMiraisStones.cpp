#include<bits/stdc++.h>

using namespace std;
vector<long> arr;
vector<long> arr_;
int N,M;

int main()
{
  int a,b,c;
  long temp;
  arr.push_back(0);
  arr_.push_back(0);
  cin>>N;
  for(int i=1;i<=N;i++) {
    scanf("%ld",&temp);
    arr.push_back(temp);
    arr_.push_back(temp);
    arr[i]+=arr[i-1];
  }
  sort(arr_.begin(),arr_.end());
  for(int i=1;i<=N;i++)
    arr_[i]+=arr_[i-1];
  cin>>M;
  for(int i=0;i<M;i++) {
    scanf("%d%d%d",&a,&b,&c);
    if(a==2) cout<<arr_[c]-arr_[b-1]<<endl;
    else cout<<arr[c]-arr[b-1]<<endl;
  }
  return 0;
}
