#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

void maxLen(vector<int> &arr) {
  unordered_multimap<int,int> hash_;
  int curr_sum = 0;
  for(int i=0;i<arr.size();i++) {
    curr_sum+= arr[i]==0?-1:arr[i];
    hash_.insert(i);
  }
}

int main() {
    vector<int> arr= {1, 0, 0, 1, 0, 1, 1};
    maxLen(arr);
    return 0;
}
