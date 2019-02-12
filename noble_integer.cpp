#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sol(vector<int> &arr)
{
        sort(arr.begin(),arr.end());
        int n = arr.size();
        for (int i=0; i<n-1; i++)
        {
            if (arr[i] == arr[i+1])
                continue;
            if (arr[i] == n-i-1)
                return arr[i];
        }
        if (arr[n-1] == 0)
            return arr[n-1];
        return -1;
}

int main()
{
  vector<int> arr = {7,3,11,12};
  int res = sol(arr);
  cout<<res<<endl;
  return 0;
}


