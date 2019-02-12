#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int sq(int A)
{
  if(A==0) return 0;
  if(A==1) return 1;


  long long l = 0,r = A/2;
  long long ans_max = -1;
  long long ans_min = A/2;
  while(r>=l)
  {
    long long mid = (r+l)/2;
    cout<<mid<<endl;
    long long temp = mid * mid;
    if((temp > A && ans_max==-1) || (temp>A && temp<ans_max)) {ans_max = mid; r = mid-1;}
    if(temp == A) return mid;
    if((temp < A && ans_min == A) || (temp < A && temp > ans_min)) {ans_min = mid; l =mid+1;}
  }
  return (int)ans_min;
}

int main()
{
  //int res = sq(930675566);
  int res = sq(14);
  cout<<res<<endl;
  return 0;
}
