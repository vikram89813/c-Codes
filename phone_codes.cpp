#include<iostream>
#include<array>
#include<vector>

using namespace std;


array<string,10> arr = {"0","1","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void cal_code_helper(string &s, int digit, string &s_temp) {
  if(digit == s.size())
  {
    cout<<s_temp<<endl;
    return;
  }
  for(char c : arr[s[digit] - '0'])
  {
    s_temp[digit] = c;
    cal_code_helper(s,digit+1,s_temp);
  }
}

void cal_code(string &s)
{
  string s_temp(s.size(),0);
  int digit = 0;
  cal_code_helper(s,0,s_temp);
}

int main()
{
  string s = "2276696";
  cal_code(s);
  return 0;
}
