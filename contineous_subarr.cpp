#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int fun(vector<int> &arr) {
  size_t s = arr.size();
  unordered_map<int,int> hash_;
  for(int i=0;i<s;i++) hash_[arr[i]] = i;
  sort(arr.begin(),arr.end());
  int ans = 1;
  int t_ans = 1;
  int t_val = arr[0];
  int i =0;
  while(i < s-1) {
    int j =i;
    int max_idx=0;
    int min_idx=s;
    int c=0;
    while(arr[j+1] - arr[j] == 1) {
      if(hash_[arr[j+1]] > max_idx) max_idx = hash_[arr[j+1]];
      if(hash_[arr[j]] > max_idx) max_idx = hash_[arr[j]];
      if(hash_[arr[j+1]] < min_idx) min_idx = hash_[arr[j+1]];
      if(hash_[arr[j]] < min_idx) min_idx = hash_[arr[j]];
      j++;
      c++;
    }
    if(max_idx - min_idx == c) {
      if(c+1 > ans) ans = c+1;
    }
    i = j+1;
  }
  return ans;
}

int main() {
  vector<int> arr = {1,56,58,57,90,92,94,93,91,45};
  cout<<fun(arr)<<endl;
  return 0;
}
