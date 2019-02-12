#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main()
{
  vector<int> a = {-1,2,3};
  vector<int> b = {4,5,6};
  vector<int> result(a.size()+b.size(),0);
  const int sign = (a.front() < 0 || b.front() < 0) ? -1 : 1;
  a.front() = abs(a.front());
  b.front() = abs(b.front());
  for(int i = a.size()-1;i>=0;i--)
  {
    for(int j = b.size()-1;j>=0;j-- )
    {
      result[i+j+1] += a[i] * b[j];
      result[i+j]+= (result[i+j+1]/10);
      result[i+j+1] = result[i+j+1]%10;
    }
  }

  auto it = find_if(result.begin(), result.end(),
                        [](int v) { return v != 0; });

  result.erase(result.begin(),it);

  result.front() *= sign;

  for(auto i : result)
  cout<<i;

  cout<<endl;
  return 0;
}
