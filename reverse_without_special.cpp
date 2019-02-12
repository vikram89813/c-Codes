#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

void rev(string &str) {
  unordered_map<int,char> hash_;
  for(int i=0;i<str.size();i++) {
    if(str[i] < 'a' || str[i] > 'z') hash_[i] = str[i];
  }
  string temp = str;
  int j =0;
  reverse(str.begin(),str.end());
  for(int i=0;i<str.size();i++) {
    if(str[i] < 'a' || str[i] > 'z') str.erase(i,1);
  }
  for(int i=0;i<temp.size();i++) {
    if(hash_.find(i) != hash_.end()) {
      temp[i] = hash_[i];
    } else {
      temp[i] = str[j++];
    }
  }
  cout<<temp<<endl;
}

int main() {
  string str = "a,b$c";
  rev(str);
  return 0;
}
