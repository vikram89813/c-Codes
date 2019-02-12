#include<iostream>
#include<vector>

using namespace std;

int sol(vector<int> arr)
{
  int one=0,two=0,three=0;
  for(int i=0;i<arr.size();i++)
  {
    two|=one & arr[i];
    one^=arr[i];
    three = one & two;
    one = one & ~three;
    two = two & ~three;
  }
  return one;
}

int main()
{
  vector<int> arr = {1,2,4,3,3,2,2,3,1,1};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}
