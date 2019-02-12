#include<iostream>
#include<vector>

using namespace std;

int sol(vector<int> arr)
{
  if(arr.size()==0)
    return 0;

  int ans = arr[0];
  for(int i = 1;i<arr.size();i++)
  {
    ans ^= arr[i];
  }
  return ans;
}

int main()
{
  vector<int> arr = {1,2,2,3,1};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}
