#include<bits/stdc++.h>

using namespace std;

long long bit[100005];
int N;
vector<pair<string,string>> arr;
vector<string> arr2;

int get_s(int idx) {
  int s =0;
  while(idx>0) {
    s+=bit[idx];
    idx-= idx & (-idx);
  }
  return s;
}

void update(int idx, int v) {
  while(idx<=N) {
    bit[idx] += v;
    idx += idx & (-idx);
  }
}

int main() {
  cin>>N;
  for(int i =0;i<N;i++) {
    string t1,t2;
    cin>>t1;
    t2 = t1;
    reverse(t2.begin(),t2.end());
    arr.push_back(make_pair(t1,t2));
    arr2.push_back(t2);
  }

  sort(arr2.begin(),arr2.end());
  sort(arr.begin(),arr.end());

  long long ans = 0;
  for(int i = arr.size()-1;i>=0;i--) {
    int idx = (lower_bound(arr2.begin(),arr2.end(),arr[i].second) - arr2.begin()) + 1;
    ans+=get_s(idx);
    update(idx,1);
  }
  cout<<ans<<endl;
}













