#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int repeat(vector<int> &A)
{
  int slow = A[0];
  int fast = A[A[0]];
  while (slow != fast) {
    slow = A[slow];
    fast = A[A[fast]];
  }

  fast = 0;
  while (slow != fast) {
    slow = A[slow];
    fast = A[fast];
  }
  return slow;
}

int main()
{
  vector<int> arr = {3,4,1,4,1};
  int res = repeat(arr);
  cout<<res<<endl;
  return 0;
}
