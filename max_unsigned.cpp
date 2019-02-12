#include<iostream>

using namespace std;

unsigned int sol(unsigned int num)
{
  for(int i=0;i<16;i++)
  {
    unsigned int a,b;
    a = ((num>>i) & 1);
    b = ((num>>(31-i)) & 1);
    if(a^b) {
      num ^= (1<<i) | (1<<(31-i));
    }
  }
  return num;
}

int main()
{
  unsigned int n = 4;
  unsigned int res = sol(4);
  cout<<res<<endl;
  return 0;
}

