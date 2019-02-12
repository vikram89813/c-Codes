#include<iostream>

using namespace std;

char arr[1001];
int dp[1001][1001];
int N;

void init() {
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++) dp[i][j] = 0;
}

int cal() {
  for(int i=0;i<N;i++) dp[i][i] = 1;
  int ans = 1;
  for(int k=2;k<=N;k++) {
    for(int i=0;i<N-k+1 ;i++) {
      int j=i+k-1;
      if(k==2) {
        if(arr[i] == arr[i+1]) {
          ans =2;
          dp[i][i+1] = 1;
        }
      } else {
        if(dp[i+1][j-1] && arr[i] == arr[j]) {
          dp[i][j] = 1;
          if(k > ans) ans = k;
        }
      }
    }
  }
  return ans;
}

int main() {
  int T;
  cin>>T;
  for(int t=1;t<=T;t++) {
    cin>>arr;
    N=0;
    int i=0;
    init();
    while(arr[i]) {N++;i++;}
    int ans = cal();
    cout<<"#"<<t<<" "<<ans<<endl;
  }
  return 0;
}
