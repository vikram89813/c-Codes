#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,k,i,t;
ll a[1000000];

int main(){
  cin>>n>>k;
  for(i=0;i<n;i++)
    cin>>a[i];

  sort(a,a+n);
  k--;

  for(i=0;i<n;i+=t){
    t=1;
    while(a[i]==a[i+t]){
      t++;
    }
    if(t*n>k)
      break;
    k=k-t*n;
  }
  cout<<a[i]<<" "<<a[k/t]<<endl;
}
