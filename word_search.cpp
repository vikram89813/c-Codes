#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

unordered_map<int,vector<string>> hash_;

void fun(vector<string> &words, string str) {
  for(auto word : words) {
    int s=0;
    for(auto c : word) {
      s = s+ c-'0';
    }
    hash_[s].push_back(word);
  }

  int s=0;
  for(auto c: str) s += c-'0';
  for(auto word : hash_[s]) {
    if(word != str) cout<<word<<endl;
  }
}

int main() {
  vector<string> words= {"cat","good","tac","act"};
  string str = "tac";
  fun(words,str);
  return 0;
}

