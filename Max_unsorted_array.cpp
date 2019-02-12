#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sol(vector<int>& A)
{
  vector<int> res;
  if(A.size() == 0) {
    res.push_back(-1);
    return res;
  }
  vector<int>::iterator it = is_sorted_until(A.begin(),A.end());
  if(it == A.end()) {
    res.push_back(-1);
    return res;
  }
  int idx_beg = it-A.begin();
  auto min_ = min_element(it,A.end());
  idx_beg--;
  auto upper_it = upper_bound(it,A.end(),*min_);
  int idx_end = upper_it - A.begin() - 1;
  int first_ = -1;
  for(int i=idx_beg;i>=0;i--)
  {
    if(A[i] > *min_) first_ = i;
  }
  res.push_back(first_);
  res.push_back(idx_end);
  return res;
}

int main()
{
  vector<int> arr = { 3, 3, 4, 5, 5, 9, 11, 13, 14, 15, 15, 16, 15, 20, 16};
  vector<int> res = sol(arr);
  for(int i : res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
