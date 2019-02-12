#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> arr;
bool dp[700+1][245001];
//bool dp[7000][(700*700)+1];

int cal() {
  int sum = 0;
  int ans = INT_MAX;
  for(auto i : arr) sum+=i;

  for(int i = 0; i <= N; i++)
    dp[i][0] = true;

  for(int i = 1; i <= sum/2 + 1; i++)
    dp[0][i] = false;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= sum/2 + 1; j++) {
           dp[i][j] = dp[i-1][j] ||
                                 dp[i - 1][j-arr[i-1]];
      }
    }
   for (int i=sum/2; i>=0; i--) {
     if (dp[N][i]) {
        ans = sum-2*i;
        break;
      }
  }
  return ans;
}

int main() {
  cin>>N;
  for(int i=0;i<N;i++) {
    int t;
    cin>>t;
    arr.push_back(t);
  }
  if(N<2) cout<<arr[0]<<endl;
  else {
    int res = cal();
    cout<<res<<endl;
  }
  return 0;
}

/*int main() {
  N=700;
  for(int i=0;i<700;i++) {
    arr.push_back(700);
  }
  cout<<cal()<<endl;
}*/
