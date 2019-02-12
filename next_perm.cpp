#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  vector<int> arr = {6,2,1,5,4,3,0};
  auto inv_point = is_sorted_until(arr.rbegin(),arr.rend());
  auto it = upper_bound(arr.rbegin(),inv_point,*inv_point);
  iter_swap(inv_point,it);
  reverse(arr.rbegin(),inv_point);
  for(auto i : arr) cout<<i<<" ";
  cout<<endl;
  return 0;
}
