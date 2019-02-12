#include<iostream>

using namespace std;

int arr[100001];
int N,H;
long long ans;

int main() {
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    ans=0;
    cin>>N>>H;
    for(int i=0;i<N;i++) scanf("%d",&arr[i]);
    int val;
    long long curr_s=H;
    for(int i=0;i<N;i++) {
      scanf("%d",&val);
      if(!val) curr_s+=arr[i];
      else curr_s = 0;
      if(curr_s >= H) {ans++;curr_s = 0;}
    }
    if(!val && curr_s)ans++;
    cout<<"#"<<t<<" "<<ans<<endl;
  }
  return 0;
}
