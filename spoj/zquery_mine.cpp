#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr;
vector<pair<int,int>> query;
vector<int>ans;
int zeros[50001];
int ones[50001];
int N,Q;

void cal() {
  for(int i=0;i<N;i++) {
    if(i == 0) {
      if(arr[i] == -1) {
        zeros[i] = 1;
        ones[i] = 0;
      }
      else {
        zeros[i] = 0;
        ones[i] = 1;
      }
    } else {
      if(arr[i] == -1) {
        zeros[i] = zeros[i-1] + 1;
        ones[i] = ones[i-1];
      }
      else {
        zeros[i] = zeros[i-1];
        ones[i] = ones[i-1] + 1;
      }
    }
  }

  for(int i=0;i<Q;i++) {
    int l = query[i].first;
    int r = query[i].second;
    if(l==r) {
      ans.push_back(0);
      continue;
    }
    if(l) {
      int no_z = zeros[r] - zeros[l-1];
      int no_one = ones[r] - ones[l-1];
      int t = 2 * min(no_z,no_one);
      ans.push_back(t);
    } else {
      int no_z = zeros[r];
      int no_one = ones[r];
      int t = 2 * min(no_z,no_one);
      ans.push_back(t);
    }
  }

  for(auto i : ans) cout<<i<<endl;
}

int main() {
  cin>>N>>Q;
  for(int i=0;i<N;i++) {
    int t;
    scanf("%d",&t);
    arr.push_back(t);
  }
  for(int i=0;i<Q;i++) {
    int l,r;
    scanf("%d%d",&l,&r);
    query.push_back(make_pair(l-1,r-1));
  }
  cal();
  return 0;
}
