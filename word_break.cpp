#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<string,bool> dic;
unordered_map<string,bool> dp;

bool wordBreakHelper(string str) {
  if(dic[str]) return true;
  if(dp[str] == true) return true;
  int n = str.size();
  dp[str] = false;
  for(int i=0;i<n;i++) {
    string s1 = str.substr(0,i+1);
    string s2 = str.substr(i+1,n);
    if(!s1.empty() && !s2.empty()) {
      dp[s1] = dp[s2] = false;
      dp[s1] = dp[s1] || wordBreakHelper(s1);
      if(dp[s1] == true)
        dp[s2] = dp[s2] || wordBreakHelper(s2);
      dp[str] = dp[str] || (dp[s1] && dp[s2]);
    }
  }
  return dp[str];
}

bool wordBreak(string str) {
  int n = str.size();
  dp.clear();
  dp[str] = false;
  if(dic[str] || str.empty()) return true;
  for(int i=0;i<n;i++) {
    string s1 = str.substr(0,i);
    string s2 = str.substr(i+1,n);
    if(!s1.empty() && !s2.empty()) {
      dp[s1] = false;
      dp[s2] = false;
      if(dic[s1]) dp[s1] = true;
      if(dic[s2]) dp[s2] = true;
    }
  }
  return wordBreakHelper(str);
}

int main() {
    vector<string> arr = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};

    for(auto i : arr) dic[i] = true;

    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    return 0;
}
