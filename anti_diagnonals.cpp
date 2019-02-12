#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> sol(vector<vector<int>> &A)
{
    vector< vector<int> > ans;
    vector<int> temp;
    int n=A.size();
    if(n==0)
        return ans;
   int i,j,d;
   for(d=0;d<=2*(n-1);d++)
   {
       for(i=0;i<=d;i++)
       {
           if(i<n && d-i<n)
            temp.push_back(A[i][d-i]);
       }
       ans.push_back(temp);
       temp.clear();
   }
   return ans;
}

int main()
{
  vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>> res = sol(arr);
  for(int i = 0;i<res.size();i++)
  {
    for(int j = 0;j<res[i].size();j++)
      cout<<res[i][j]<<" ";
    cout<<endl;
  }
  return 0;
}
