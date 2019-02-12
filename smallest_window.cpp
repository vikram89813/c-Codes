#include<iostream>
#include<unordered_map>
#include<climits>

using namespace std;

string findSubString(string &str,string &pat) {
  int len = pat.size();
  int c = 0;
  unordered_map<char,int> hash_;
  unordered_map<char,int> hash_pat;
  int begin = 0;
  int f_len= INT_MAX;
  int s_idx = -1;
  for(auto i : pat) hash_pat[i]++;
  for(int i=0;i<str.size();i++) {
    hash_[str[i]]++;
    if(hash_pat.find(str[i]) != hash_pat.end() && hash_[str[i]] <= hash_pat[str[i]]) c++;
    if(c==len) {
      while(hash_pat.find(str[begin]) == hash_pat.end() || hash_[str[begin]] > hash_pat[str[begin]]) {
        if(hash_[str[begin]] > hash_pat[str[begin]]) hash_[str[begin]]--;
        begin++;
      }
      int t_len = i-begin+1;
      if(t_len < f_len) f_len = t_len, s_idx = begin;
    }
  }
  if(f_len != INT_MAX) return str.substr(s_idx,f_len);
}

int main() {
    string str = "this is a test string";
    string pat = "tist";

    cout << "Smallest window is : "
        << findSubString(str, pat)<<endl;
    return 0;
}
