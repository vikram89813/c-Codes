#include<bits/stdc++.h>

using namespace std;

unordered_map<int,int> h;

static bool comp (const int &a, const int &b) {
  return abs(a) <= abs(b);
}

bool canReorderDoubled(vector<int>& arr) {
  if(arr.size() == 1) return false;
  for(auto i : arr) {
    if(h.find(i) == h.end()) h[i] = 1;
    else h[i] += 1;
  }
  make_heap(arr.begin(),arr.end(),comp);
  sort_heap(arr.begin(),arr.end(),comp);

  for(auto i : arr) {
    if(!h[i]) continue;
    if(!h[2*i]) return false;
    h[i]--;
    h[2*i]--;
  }

  return true;
}

int main() {
  vector<int> arr= {-6,2,-6,4,-3,8,3,2,-2,6,1,-3,-4,-4,-8,4};
    //vector<int> arr = {-33,54,29,-14,-98,98,22,-58,-49,-3,-86,-68,-43,9,-23,98,-78,-96,36,22,16,18,40,68,-46,52,-20,-36,68,16,-62,66,6,-34,-8,8,72,49,80,34,34,44,-6,-31,17,-66,-90,27,58,18,-31,2,-31,-19,23,32,38,49,-6,46,28,-42,-7,62,-14,44,-52,-52,-39,-18,-68,-34,-47,41,-26,29,31,-26,44,4,-41,47,72,11,-98,-68,82,2,34,22,-48,3,-29,-7,34,-94,-29,-44,36,-4,-12,-62,-58,4,2,66,-84,-45,4,-62,27,36,33,26,-52,18,36,33,-10,-98,27,-12,-9,-6,17,-6,-38,-34,-3,-18,22,-26,94,54,-88,58,54,76,-82,14};
  //vector<int> arr= {1,2,1,-8,8,-4,4,-4,2,-2};
  cout<<canReorderDoubled(arr)<<endl;
  return 0;
}
