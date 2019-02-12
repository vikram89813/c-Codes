#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int fact(int n)
{
  return (n<=1)?1:fact(n-1)*n;
}

void updatecount (int *hash_, char ch)
{
    int i;
    for( i = ch; i < 256; ++i )
        --hash_[i];
}

int cal(string s)
{
  int len = s.size();
  int mul = fact(len);
  int rank = 1;
  int hash_[256] = {0};
  for(int i = 0;i<len;i++)
    hash_[s[i]]++;
  for(int i =1;i<256;i++)
    hash_[i] += hash_[i-1];

  for(int i=0;i<len;i++)
  {
    mul/=(len-i);
    rank+= hash_[s[i] - 1] * mul;
    updatecount(hash_,s[i]);
  }
  return rank;
}

int main()
{
  string s = "STRING";
  int rank = cal(s);
  cout<<rank<<endl;
  return 0;
}

