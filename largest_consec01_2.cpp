#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<int,int> larr;
unordered_map<int,int> rarr;
vector<int> acc;

int maxLen(vector<int> &arr) {
  size_t s = arr.size();
  acc.resize(s);
  int l = -1;
  int r = -1;
  int t =0;
  int ans = 0;
  for(int i=0;i<s;i++){
    t+=arr[i];
    acc[i] = t;
    if(larr.find(t) == larr.end()) larr[t] = i;
    rarr[t] = i;
  }
  for(int i=0;i<s;i++) {
    int t1 = larr[acc[i]];
    int t2 = rarr[acc[i]];
    if(t2-t1 > ans) {
      ans = (t2-t1);
      l = t1;
      r = t2-1;
    }
  }
  return ans;
}

int main()
{
    vector<int> arr = {1, -1, -1, 1, -1, 1, 1};
    cout<<maxLen(arr)<<endl;
    return 0;
}

