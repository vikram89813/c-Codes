#include<bits/stdc++.h>

using namespace std;

int main() {
  vector<int> arr={6, 1, 5, 4, 5, 2, 6};
  sort(arr.begin(),arr.end());
  int n = arr.size();
  int ans = 0;
  for(int i=n-1;i>=0;i--) {
    int t = arr[i] * (n-i);
    if(t > ans) ans = t;
  }
  cout<<ans<<endl;
  return 0;
}
