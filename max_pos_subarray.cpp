#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

vector<int> maxset(vector<int> &A) {
  long long  max_ending_here = 0, max_so_far = INT_MIN;
  int s=-1,e=-1,l=0;
  for(int i=0;i<A.size();i++)
  {
    if(A[i] < 0) max_ending_here = 0,l=i+1;
    else {
      max_ending_here += A[i];
      if(max_so_far <= max_ending_here)
      {
       if(max_so_far == max_ending_here) {
         int a = (e-s)+1;
         int b = (i-l)+1;
         if(b > a) s = l, e = i;
         else if(b==a) {
         }
       }
       else {
        max_so_far = max_ending_here;
        s = l;
        e = i;
       }
      }
    }
  }
  vector<int> res;
  if(s == -1) return res;
  for(int i = s;i<=e;i++) {
    int t = A[i];
    res.push_back(t);
  }

  return res;
}

int main()
{
  vector<int> arr = {1967513926,1540383426,-1303455736,-521595368};
  vector<int> res = maxset(arr);
  for(int i : res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
