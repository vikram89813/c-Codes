#include<bits/stdc++.h>

using namespace std;

int N;
vector<long> arr;
vector<long> height;
int dp[100010][3];
int ans;

void cal()
{
  for(int i=1;i<N;i++)
  {
    dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
    if(arr[i] > arr[i-1]+height[i-1])
      dp[i][0] = max(dp[i][0],dp[i-1][2]);
    if(arr[i]-height[i] > arr[i-1])
    {
      long a = dp[i-1][0];
      long b = dp[i-1][1];
      dp[i][1] = max(a,b);
      if(arr[i]-height[i] > arr[i-1]+height[i-1])
        dp[i][1] = max(dp[i][1],dp[i-1][2]);
      dp[i][1]+=1;
    }
    if(arr[i] > arr[i-1]+height[i-1])
    {
      dp[i][2] = max(dp[i-1][0],max(dp[i-1][1],dp[i-1][2])) + 1;
    }
    else
    {
      dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + 1;
    }
    dp[i][0] = max(dp[i][0],dp[i-1][0]);
    dp[i][1] = max(dp[i][1],dp[i-1][1]);
    dp[i][2] = max(dp[i][2],dp[i-1][2]);
  }
}

int main()
{
  cin>>N;
  long a,b;
  for(int i=0;i<N;i++)
  {
    scanf("%ld%ld",&a,&b);
    arr.push_back(a);
    height.push_back(b);
  }
  dp[0][0] = 0;
  dp[0][1] = 1;
  dp[0][2] = 1;
  cal();
  ans = max(dp[N-1][0],max(dp[N-1][1],dp[N-1][2]));
  cout<<ans<<endl;
  return 0;
}
