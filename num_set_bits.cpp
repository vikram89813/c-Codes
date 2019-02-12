#include<iostream>
#include<string.h>

using namespace std;

int set_b(int a)
{
  int c = 0;
  while(a!=0)
  {
    a= a & (a-1);
    c++;
  }
  return c;
}

int main()
{
  int a = 15;
  cout<<set_b(a)<<endl;
  return 0;
}
