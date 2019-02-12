#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> arr = {2,0,4,1,3};
  int temp,curr_idx;
  for(int i=0;i<arr.size();i++)
  {
    temp = arr[i];
    curr_idx = i;
    if(arr[temp] == i) continue;
    while(arr[temp] != curr_idx)
    {
      int temp_ = arr[temp];
      int curr_idx_ = temp;
      arr[temp] = curr_idx;
      temp = temp_;
      curr_idx = curr_idx_;
    }
  }
  for(auto i : arr)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
