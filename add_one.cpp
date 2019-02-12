#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> arr = {9,9,9};
  ++arr.back();
  for(int i = arr.size()-1;i>0 && arr[i] == 10;i--)
  {
    arr[i] = 0;arr[i-1]++;
  }

  if(arr[0] == 10)
    arr[0] = 0,arr.insert(arr.begin(),1);

  for(auto i : arr)
    cout<<i<<" ";

  cout<<endl;
  return 0;
}
