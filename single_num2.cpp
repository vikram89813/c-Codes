#include<iostream>
#include<vector>

using namespace std;

int sol(vector<int> arr)
{
  int c[32] = {0};
  int res = 0;
  for(int i=0;i<32;i++)
  {
    for(int j=0;j<arr.size();j++)
    {
      if((arr[j] >> i) & 1) c[i]++;
    }
    res |= ((c[i]%3)<<i);
  }
  return res;
}

int main()
{
  vector<int> arr = {1,2,4,3,3,2,2,3,1,1};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}
