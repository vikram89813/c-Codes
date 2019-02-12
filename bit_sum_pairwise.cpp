#include<iostream>
#include<vector>

using namespace std;

int sol(vector<int>& arr)
{
  if(arr.size() == 0) return 0;
  int c = 0;
  for(int i=0;i<31;i++)
  {
    int x =0,y=0;
    for(int j=0;j<arr.size();j++)
    {
      if((arr[j]>>i) & 1) x++;
      else y++;
    }
    c += 2 * x * y;
  }
  return c;
}

int main()
{
  vector<int> arr = {1,3,5};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}
