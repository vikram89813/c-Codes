#include<iostream>
#include<math.h>

using namespace std;

int val(char c)
{
  if(c >= 'A' && c<='F')
    return c-'A'+10;
  else
    return c-'0';
}

int main() {
  string s;
  cin>>s;
  int num = 0;
  int len = s.size();
  len--;
  while(len>=0)
  {
    num+=(val(s[len])) * pow(16,s.size()-1-len);
    len--;
  }
  cout<<num<<endl;
  return 0;
}
