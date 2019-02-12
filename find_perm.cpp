#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sol(string A,int n)
{
  if(n==0 || n==1) return vector<int>();
  vector<int> res;
  vector<int> arr;
  int in = 1;
  for(int i=0;i<n;i++) arr.push_back(in++);
  int s_idx = 0;
  int e_idx = n-1;
  for(int i=0;i<n-1;i++) {
    if(A[i] == 'D') res.push_back(arr[e_idx--]);
    if(A[i] == 'I') res.push_back(arr[s_idx++]);
  }
  if(A[n-2] == 'D') res.push_back(arr[s_idx++]);
  if(A[n-2] == 'I') res.push_back(arr[e_idx--]);
  return res;
}

int main()
{
  int n = 3;
  string s = "II";
  vector<int> res = sol(s,n);
  for(int i : res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
