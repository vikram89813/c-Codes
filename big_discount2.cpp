#include<iostream>

using namespace std;

int hash_[100001];
int N;

int main() {
  int T;
  int temp;
  int max_ = -1;
  cin>>T;
  for(int t=1;t<=T;t++) {
    cin>>N;
    for(int i=0;i<100001;hash_[i++] = 0);
    for(int i=0;i<N;i++) {
      scanf("%d",&temp);
      if(temp > max_) max_ = temp;
      hash_[temp]++;
    }
    N=0;
    long long ans = 0;
    for(int i=max_;i>=0;i--) {
      while(hash_[i]) {
        N++;
        hash_[i]--;
        if(N%3) {
          ans+=i;
        }
      }
    }
    cout<<"#"<<t<<" "<<ans<<endl;
  }
}
