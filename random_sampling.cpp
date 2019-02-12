#include<iostream>
#include<vector>
#include<random>

using namespace std;

int main()
{
  vector<int> a = {5,7,3,11};
  default_random_engine seed((random_device()) ());
  for(int i=0;i<3;i++)
    swap(a[i],a[uniform_int_distribution<int>{i,static_cast<int>(a.size())-1}(seed)]);
  for(auto i : a)
    cout<<i<<" ";

  cout<<endl;
  return 0;
}
