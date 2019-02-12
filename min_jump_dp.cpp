#include<bits/stdc++.h>

using namespace std;

int func(vector<int> &A) {
     int sz = A.size();
     vector<int> buf(sz, 0);
     for (int i = sz -2; i >= 0; i--) {
         int steps = A[i];
         int min = INT_MAX;
         for (int j = 1; (j <= steps) && (i + j < sz); j++) {
             if ((buf[i + j] != -1) && (min > buf[i + j])) {
                 min = buf[i + j];
             }
         }
         buf[i] = (min == INT_MAX) ? -1 : min + 1;
     }

     return buf[0];
}

int main() {
  vector<int> arr = {2,3,1,1,4};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
