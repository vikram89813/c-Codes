#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sol(vector<int> arr, int k)
{
  vector<int> heap_;
  for(int i=0;i<k;i++)
    heap_.push_back(arr[i]);

  make_heap(heap_.begin(),heap_.end());
  for(int i=k;i<arr.size();i++)
  {
    if(heap_.front() > arr[i]) {
      pop_heap(heap_.begin(),heap_.end());
      heap_.pop_back();
      heap_.push_back(arr[i]);
      push_heap(heap_.begin(),heap_.end());
    }
  }
  return heap_.front();
}

int main()
{
  vector<int> arr= {2,1,4,3,2};
  int res = sol(arr,3);
  cout<<res<<endl;
  return 0;
}
