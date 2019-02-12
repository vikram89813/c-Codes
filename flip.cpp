#include<iostream>
#include<string>
#include<vector>

using namespace std;


vector<int> flip(string A) {
  int ending_here[A.size()];
  int count = 0;
  for(int i=0;i<A.size();i++)
  {
    if(A[i] == '0')
      ending_here[i] = count+1,count++;
    else
      count = 0, ending_here[i] = -1;
  }
  int idx_e = -1,max=-1;
  for(int i=0;i<A.size();i++)
  {
    if(ending_here[i] > max) max = ending_here[i],idx_e=i;
  }
  int idx_s = idx_e;
  if(idx_e > -1) {
    for(int i=idx_e-1;i>=0;i--) {
      if(A[i]=='1') {
        idx_s = i+1;
        break;
      }
      else if(i==0 && A[i] == '0') {
        idx_s =0;
      }
    }
  }
  vector<int> res = {};
  if(idx_s != -1) {
    idx_s+=1;
    idx_e+=1;
    res.push_back(idx_s);
    res.push_back(idx_e);
  }
  return res;
}

int main()
{
  string str = "1101010001";
  vector<int> res = flip(str);
  for(auto i : res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
