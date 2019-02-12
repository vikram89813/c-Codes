#include<iostream>

using namespace std;

int main()
{
  string str = "geeks for geeks";
  string pat = "geeks";
  size_t i = 0,j=0;
  while(j < str.size()) {
    j = str.find(pat,i);
    if(j != string::npos)
      cout<<"found at : "<<j<<endl;
    i = j+1;
  }
  return 0;
}
