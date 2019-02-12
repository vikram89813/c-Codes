#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sol(vector<int> &A)
{
  int ans = -1;
  const int n = A.size();
  int min_arr[n];
  int max_arr[n];
  min_arr[0] = A[0];
  max_arr[n-1] = A[n-1];

  for(int i=1;i<n;i++)
    min_arr[i] = min(A[i],min_arr[i-1]);

  for(int i=n-2;i>=0;i--)
    max_arr[i] = max(A[i],max_arr[i+1]);

  int i=0,j=0;
    while (j < n && i < n)
    {
        if (min_arr[i] <= max_arr[j])
        {
            ans = max(ans, j-i);
            j = j + 1;
        }
        else
            i = i+1;
    }

  return ans;
}

int main()
{
  vector<int> arr = {100,100,100,100};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}
