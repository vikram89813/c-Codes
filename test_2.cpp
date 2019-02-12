#include<iostream>
#include<string>

using namespace std;

int main()
{
  const char* url = "https://samsunginter.net/examples/payment-request-demo-simple/";
  std::string url_t = url;
  int idx_first = url_t.find("/",0);
  if(url_t[idx_first+1] == '/') idx_first+=2;
  int idx_end = url_t.find("/",idx_first);
  string url__= std::string(url_t.begin()+idx_first,url_t.begin()+idx_end).c_str();
  const char* url_ = url__.c_str();
  cout<<url_<<endl;
  return 0;
}
