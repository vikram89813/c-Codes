#include<iostream>
#include<vector>

using namespace std;

int findSubArray(vector<int> &arr) {
  int zero_c = 0;
  int one_c = 0;
  for(auto i : arr) {
    if(i) one_c++;
    else zero_c++;
  }
  return 2*min(zero_c,one_c);
}

int main()
{
    vector<int> arr =  {1, 0, 0, 1, 0, 1, 1};
    int ans = findSubArray(arr);
    cout<<ans<<endl;
    return 0;
}
