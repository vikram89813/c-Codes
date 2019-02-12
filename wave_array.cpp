#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> sol(vector<int> &A)
{
  if(!A.size())
    return vector<int>();

  sort(A.begin(),A.end());
  for(int i = 0;i<A.size()-1;i+=2)
  {
    swap(A[i],A[i+1]);
  }
  return A;
}

int main()
{
  vector<int> arr = {1,2,3,4};
  vector<int> res = sol(arr);
  for(int i : res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}


