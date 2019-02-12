#include<bits/stdc++.h>

using namespace std;

vector<int> func(vector<int> &arr,int k)
{
  vector<int> res;
  unordered_map<int,int> hash_;

  for(int i=0;i<arr.size();i++) {
    hash_[arr[i]]++;
    if(i-k+1 >= 0) {
      res.push_back(hash_.size());
      hash_[arr[i-k+1]]--;
      if(hash_[arr[i-k+1]] == 0) hash_.erase(arr[i-k+1]);
    }
  }

  return res;
}

int main()
{
  vector<int> arr = {1,2,1,3,4,3};
  vector<int> res = func(arr,3);
  for(auto i : res) cout<<i<<" ";
  cout<<endl;
  return 0;
}
