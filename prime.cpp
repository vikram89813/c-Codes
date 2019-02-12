#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<bool> arr(21,true);
  arr[0] = false;
  arr[1] = false;
  for(int i=2;i<arr.size();i++)
  {
    if(arr[i])
    {
      for(int j=2*i;j<arr.size();j+=i)
        arr[j] = false;
    }
  }
  for(int i=0;i<arr.size();i++)
    if(arr[i])
      cout<<i<<" ";
  cout<<endl;
  return 0;
}
