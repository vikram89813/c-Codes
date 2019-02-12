#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  int a = 30,b=12;
  while(__gcd(a,b) != 1)
  {
    a = a/__gcd(a,b);
  }
  cout<<a<<endl;
  return 0;
}
