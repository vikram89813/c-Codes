#include<iostream>
#include<vector>

using namespace std;

int N,K;
vector<int> arr;

int cal(int l,int r,int l_miss) {
  if(r-l == 1) {
    return arr[l] + (K-l_miss);
  }

  int missing = (arr[r] - arr[l]) - (r-l);
  if(K-l_miss > missing) return -1;

  int mid = l + (r-l)/2;
  int left_missing = (arr[mid] - arr[l]) - (mid - l);
  if(l_miss + left_missing >=K) return cal(l,mid,l_miss);
  else return cal(mid,r,l_miss + left_missing);
}

int main() {
  int T;
  cin>>T;
  while(T--) {
    cin>>N>>K;
    arr.resize(N,0);
    for(int i=0;i<N;i++) cin>>(arr[i]);
    int ans = cal(0,N-1,0);
    if(ans == arr[N-1] +1) cout<<-1<<endl;
    else cout<<ans<<endl;
  }
  return 0;
}
