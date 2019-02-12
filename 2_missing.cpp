#include<iostream>
#include<vector>

using namespace std;

void findTwoMissingNumbers(vector<int> &arr) {
  size_t s = arr.size();
  int n = 2 + s;
  int xor_ = 0;
  for(auto i:arr) xor_ = xor_ ^ i;
  for(auto i=1;i<=n;i++) xor_ = xor_ ^ i;

  int s_bit = xor_ & ~(xor_ -1);
  int x,y;
  x=y=0;

  for(auto i : arr) {
    if(i & s_bit) x = x ^ i;
    else y = y ^ i;
  }
  for(auto i=1;i<=n ;i++) {
    if(i & s_bit)
    	x = x ^ i;
    else y = y ^ i;
  }
  cout<<x<<" "<<y<<endl;
}

int main()
{
    vector<int> arr = {1, 3, 5, 6};
    findTwoMissingNumbers(arr);
    return 0;
}
