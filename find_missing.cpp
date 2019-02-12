#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find_missing_positive(vector<int> &A)
{
  for(int i=0;i<A.size();i++)
  {
    if(A[i] >=0 && A[i] <= A.size()) {
      if(A[A[i] - 1] != A[i]) {
        swap(A[A[i]-1],A[i]);
        i--;
      }
    }
  }
  for(int i=0;i<A.size();i++)
    if(A[i] != i+1) return (i+1);

  return A.size()+1;
}

int main()
{
  vector<int> arr = {1,3,-1,8};
  int res = find_missing_positive(arr);
  cout<<res<<endl;
  return 0;
}
