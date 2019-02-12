#include<iostream>
#include<string>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> flip(string A) {
  int n = A.size();
  vector<int> arr;
  for(int i=0;i<n;i++) {
    if(A[i] == '1') arr.push_back(-1);
    else arr.push_back(1);
  }
  int max_ending_here = 0,max_so_far= INT_MIN;int idx_s = -1;int idx_e = -1;
  int l =0;
  for(int i=0;i<n;i++)
  {
    if(arr[i]+max_ending_here < 0) max_ending_here = 0,l = i+1;
    else {
     max_ending_here = arr[i]+max_ending_here;
    if(max_so_far < max_ending_here) {
       max_so_far = max_ending_here;
       idx_s = l;
       idx_e = i;
      }
    }
  }
  vector<int> r = {};
  if(idx_s == -1) return r;
  r.push_back(idx_s+1);
  r.push_back(idx_e+1);
  return r;
}

int main()
{
  string str = "1";
  vector<int> res = flip(str);
  for(auto i : res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
