#include<iostream>
#include<string.h>
#include<limits.h>

using namespace std;

unsigned int swap_(unsigned int x, unsigned int i,unsigned int j) {
  unsigned int lo = (x>>i) & 1;
  unsigned int hi = (x>>j) & 1;
  if(lo ^ hi) {
    x^= (1U<<i) | (1U<<j);
  }
  return x;
}

int rev(int num)
{
  unsigned int n = sizeof(num) * 8;
  for(unsigned int i=0;i<n/2;i++)
  {
    num = swap_(num,i,n-i-1);
  }
  return num;
}

int main()
{
  unsigned int a = 3;
  unsigned int res = rev(a);
  cout<<res<<endl;
  return 0;
}
