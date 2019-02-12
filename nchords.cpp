#include<bits/stdc++.h>

using namespace std;

#define mod 1000000007

int func(int n) {
  if(n == 0) return 1;
  int *table = new int[n + 1];
  table[0] = 1;
  table[1] = 1;
  for(int i = 2; i <= n; i++) {
    for(int j = 0; j < i; j++) {
      long long temp = (table[j] * table[i - 1 - j])%mod;
      table[i] = (table[i] + temp)%mod;
    }
  }
  return table[n];
}

int main() {
  int n=5;
  int ans = func(n);
  cout<<ans<<endl;
  return 0;
}
