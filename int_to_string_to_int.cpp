#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
  int num = -123;
  string s;
  bool neg = false;
  if(num<0) neg = true;
  num = abs(num);
  while(num)
  {
    s.push_back((num%10) + '0');
    num/=10;
  }
  if(neg)
    s.push_back('-');
  reverse(s.begin(),s.end());
  cout<<s<<endl;

  neg = false;
  int idx = 0;
  int size_ = s.size();
  int num_ = 0;
  if(s[0] == '-') neg = true,idx = 1,size_--;
  for(int i = s.size()-1;i>=idx;i--)
  {
    num_ = num_ + (s[i] - '0') * pow(10,(size_ - i));
  }
  if(neg) num_*= -1;
  cout<<num_<<endl;
  return 0;
}
