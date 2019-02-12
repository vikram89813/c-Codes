#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long N,K;
vector<long long> arr;
pair<long long,long long> ans;

int main()
{
  int temp;
  cin>>N>>K;
  for(int i = 0;i<N;i++)
  {
    cin>>temp;
    arr.push_back(temp);
  }
  sort(arr.begin(),arr.end());
  long long t1,t2,l = 0;
  K--;
  t1 = arr[K/N];
  long long t = arr[K/N];
  long long count_ = count(arr.begin(),arr.end(),t);
  for(long long i = 0;i<N;i++)
  {
    if(arr[K/N] > arr[i])
      l++;
  }
  t2 = arr[(K-N*l)/count_];
  ans = make_pair(t1,t2);
  cout<<ans.first<<" "<<ans.second<<endl;
  return 0;
}
