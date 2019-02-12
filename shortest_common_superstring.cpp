#include<bits/stdc++.h>

using namespace std;

int overlap[20][20];
int dp[20][(1<<20)];
int final_mask;

int cal_overlap(vector<string> &arr, int last ,int b) {
  if(last == -1) return int(arr[b].size());
  if(overlap[last][b] != -1) return overlap[last][b];

  for(int i=0;i<arr[last].size();i++){
    bool suffix = true;
    for(int j=0;j<arr[b].size() && i+j < arr[last].size() && suffix;j++)
    {
      if(arr[last][i+j] != arr[b][j])suffix = false;
    }
    if(suffix) {
      int temp = arr[last].size() - i;
      overlap[last][b] = arr[b].size() - temp;
      return overlap[last][b];
    }
  }
  overlap[last][b] = arr[b].size();
  return overlap[last][b];
}

int find_opt(vector<string> &arr,int last,int mask) {
  if(mask == final_mask) return dp[last+1][mask] = 0;
  if(dp[last+1][mask] != -1) return dp[last+1][mask];

  int ans=INT_MAX;
  for(int i=0;i<arr.size();i++) {
    if(!((mask>>i)&1)) {
      ans = min(ans, find_opt(arr,i,(mask | (1<<i))) + cal_overlap(arr,last,i));
    }
  }
  dp[last+1][mask] = ans;
  return ans;
}

int func(vector<string> arr) {
  if(arr.empty()) return 0;
  vector<string> new_arr;

  for(int i=0;i<arr.size();i++) {
    for(int j=0;j<arr.size();j++) {
      if(i!=j) {
        if(arr[i].find(arr[j]) != string::npos) arr[j] = "";
      }
    }
  }

  for(auto i : arr)
    if(i != "") new_arr.push_back(i);

  final_mask = (1 << (new_arr.size())) -1;
  memset(dp,-1,sizeof(dp));
  memset(overlap,-1,sizeof(overlap));
  int mask = 0;

  int ans = find_opt(new_arr,-1,mask);
  return ans;
}

int main() {
  //vector<string> arr = {"abcd","cdef","fgh","de"};
  vector<string> arr = {"cpsklryvmcp", "nbpbwllsrehfmx", "kecwitrsglre", "vtjmxypu"};
  int ans = func(arr);
  cout<<ans<<endl;
  return 0;
}
