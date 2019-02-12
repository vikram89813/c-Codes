#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000;
const int MOD = 5000000;
int bit[51][MAX];
int N,K,max_ = INT_MIN;

int get_s(int* b, int idx) {
    int res = 0;
    while (idx >= 0) {
        res += b[idx];
        if (res >= MOD) res -= MOD;
        idx = (idx&(idx+1))-1;
    }
    return res;
}

void update(int* b, int idx, int val) {
    while (idx < MAX) {
        b[idx] += val;
        if (b[idx] >= MOD) b[idx] -= MOD;
        idx |= idx+1;
    }
}

int main() {
  cin>>N>>K;
  while(N--) {
    int x;
    scanf("%d", &x);
    if(x > max_) max_ = x;

    update(bit[1],x,1);
    for(int i =2;i<=K;i++) {
      update(bit[i],x,get_s(bit[i-1],x-1));
    }

  }
  cout<<get_s(bit[K],max_)<<endl;
}



