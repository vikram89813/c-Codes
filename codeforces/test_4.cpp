#include<iostream>
#include<bitset>

using namespace std;

int main()
{
  int x1 = (1<<1) | (1<<3);
  int x = x1 & (1<<1);
  bitset<4> str(x1);
  string s;
  for(int i=0;i<4;i++)
    s[i] = str[i];
  cout<<bitset<4>(x1)<<" "<<__builtin_popcount(x1)<<" "<<str<<" "<<s<<endl;
  cout<<"*********"<<endl;
  cout<<s[0]<<endl;
  return 0;
}
