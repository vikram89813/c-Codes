#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
  string s = "ram is costly";
  reverse(s.begin(),s.end());
  int start = 0,end;
  while((end = s.find(" ",start)) != string::npos) {
    reverse(s.begin()+start,s.begin()+end);
    start = end + 1;
  }
  reverse(s.begin()+start,s.end());
  cout<<s<<endl;
  return 0;
}
