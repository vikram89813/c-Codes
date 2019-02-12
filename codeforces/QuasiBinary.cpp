#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>
#include<cstdlib>

using namespace std;

int N;
vector<int> arr;
int temp[7];
bool visited[7];

int conv(int n)
{
  int i, k = 0;
  for (i = 0; i < n; i++)
    k = 10 * k + temp[i];

  return k;
}

void fill_arr(int n,int count)
{
  if(count==n)
  {
    int temp_ = conv(n);
    arr.push_back(temp_);
    return;
  }

  for(int i=0;i<n;i++)
  {
    if(!visited[i])
    {
      visited[i] = true;
      temp[i] = 0;
      count = count+1;
      fill_arr(n,count);
      temp[i] = 1;
      fill_arr(n,count);
      visited[i] = false;
    }
  }
}

int main()
{
  cin>>N;
  for(int i=0;i<7;i++)
    visited[i] = false;

  for(int i =7;i<=7;i++)
  {
    for(int i=0;i<7;i++)
      visited[i] = false;

    fill_arr(i,0);
  }

  sort(arr.begin(),arr.end());

  for(int i:arr)
    cout<<i<<endl;
  return 0;
}
