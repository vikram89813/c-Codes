#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<limits.h>

using namespace std;

int Gap(vector<int> &A)
{
  if(A.empty() || A.size() < 2)
    return 0;

  int max_ = *max_element(A.begin(), A.end());
  int min_ = *min_element(A.begin(), A.end());

  int ans = INT_MIN;
  int prev = min_;

  vector<int> bucketsMin(A.size() - 1, INT_MAX);
  vector<int> bucketsMax(A.size() - 1, INT_MIN);

  float delta_ = (float)(max_-min_)/((float)A.size()-1);

  for(int i=0;i<A.size();i++)
  {
    if(A[i] == max_ || A[i] == min_) continue;
    int idx = (int)floor((A[i] - min_)/delta_);
    bucketsMin[idx] = min(bucketsMin[idx],A[i]);
    bucketsMax[idx] = max(bucketsMax[idx],A[i]);
  }

  for(int i=0;i<A.size()-1;i++)
  {
    if (bucketsMin[i] == INT_MAX && bucketsMax[i] == INT_MIN) continue;
    ans = max(bucketsMin[i] - prev,ans);
    prev = bucketsMax[i];
  }

  return ans;
}

int main()
{
  vector<int> arr = {5, 3, 1, 8, 9, 2, 4};
  int res = Gap(arr);
  cout<<res<<endl;
  return 0;
}
