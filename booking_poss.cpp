#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool hotel(vector<int> &arri, vector<int> &dep, int k) {
  if(k<=0 || arri.size()==0 || dep.size() == 0) return false;
  vector<pair<int,int>> arr;
  int count = 0;
  for(int i=0;i<arri.size();i++)
  {
    arr.push_back(make_pair(arri[i],dep[i]));
  }
  sort(arr.begin(),arr.end(),[](pair<int,int> &a, pair<int,int> &b){ return a.second < b.second;});
  int flag = 0;
  for(int i =1;i<arr.size();i++)
  {
    if(arr[i].first<arr[i-1].second)
    {
      if(!flag) count+=2,flag = 1;
      else count++;
    }
  }
  if(count>k) return false;
  return true;
}

bool hotel_(vector<int> &arrive, vector<int> &depart, int K) {
        if(K == 0)
                return false;

        int N = arrive.size();
        vector<pair<int, int> > vec;
        for(int i = 0; i < N; ++i) {
            vec.push_back(make_pair(arrive[i], 1));
            vec.push_back(make_pair(depart[i], 0));
        }
        sort(vec.begin(), vec.end());
        int curActive = 0;
        int maxAns = 0;
        for (int i = 0; i < vec.size(); i++) {
           if (vec[i].second == 1) { // arrival
               curActive++;
               maxAns = max(maxAns, curActive);
            } else {
                curActive--;
            }
        }

        if (K >= maxAns) return true;
        return false;
    }

int main()
{
  vector<int> arr = {1,5,3};
  vector<int> dep = {2,8,6};
  bool res = hotel(arr,dep,1);
  cout<<res<<endl;
  return 0;
}
