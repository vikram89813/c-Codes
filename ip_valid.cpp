#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool is_valid(string &s)
{
  if(s.front() == '0' && s.size()>1) return false;
  if(s.size() > 3) return false;
  int val = stoi(s);
  return (val>=0 && val<=255);
}

vector<string> find_ip(string &s)
{
  vector<string> result;
  for(int i=1;i<4&&i<s.size();i++)
  {
    string first = s.substr(0,i);
    if(is_valid(first))
    {
      for(int j=1;j<4 && i+j<s.size();j++)
      {
        string second = s.substr(i,j);
        if(is_valid(second))
        {
          for(int k=1;k<4 && i+j+k<s.size();k++)
          {
            string third = s.substr(i+j,k);
            if(is_valid(third))
            {
              string forth = s.substr(i+j+k);
              if(is_valid(forth))
              {
                string temp = first + '.' + second + '.' + third +'.'+forth;
                result.push_back(temp);
              }
            }
          }
        }
      }
    }
  }
  return result;
}

int main()
{
  string str = "19216811";
  vector<string> res = find_ip(str);
  for(string s : res)
    cout<<s<<endl;
  return 0;
}
