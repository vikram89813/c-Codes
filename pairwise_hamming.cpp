#include<iostream>
#include<vector>
#include<bitset>
#include<algorithm>
#include<string>

using namespace std;

int sol(vector<int> &A)
{
  if(A.size() <= 0) return 0;
  int sum = 0;
  for(int i = 0;i<31;i++)
  {
    int one_ = 0, zero_ = 0;
    for(int j=0;j<A.size();j++)
    {
      if(A[j] & (1<<i)) one_++;
      else zero_++;
    }
      sum = sum + 2 * one_ * zero_;
  }
  return sum;
}

int main()
{
  vector<int> arr = {2,4,6};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}
