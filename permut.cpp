#include<iostream>
#include<vector>

using namespace std;

int main()
{
  vector<int> arr = {1,2,3,4};
  vector<int> perm = {2,1,3,0};
  for(int i=0;i<arr.size();i++)
  {
    int next = i;
    while( perm[next] >= 0 )
    {
      swap(arr[i],arr[perm[next]]);
      int temp = perm[next];
      perm[next]-=perm.size();
      next=temp;
    }
  }
  for(auto i : arr)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
