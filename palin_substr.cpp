#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;

string solve(string str)
{
  int n = str.size();
  bool arr[n][n];
  memset(arr,false,sizeof(arr));

  for(int i=0;i<n;i++)
    arr[i][i] = true;

  int max_l = 0;
  for(int i=0;i<n-1;i++)
    if(str[i] == str[i+1]) arr[i][i+1] = true,max_l = 2;

  int s = 0;
  for(int k = 3; k<n ;k++)
  {
    for(int i = 0;i<n;i++)
    {
      int j = i+k-1;
      if(j<n)
      {
        if(arr[i+1][j-1] && str[i] == str[j])
        {
          arr[i][j] = true;
          if(max_l < k) max_l = k,s = i;
        }
      }
    }
  }
  string ans;
  for(int i = s;i<s+max_l;i++)
    ans+=str[i];
  return ans;
}

int main()
{
  string str = "aaaabaaa";
  string s = solve(str);
  cout<<s<<endl;
  return 0;
}
