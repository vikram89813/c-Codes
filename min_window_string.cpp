#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(m>n) return string("");

        unordered_map<char,int> h_p;
        unordered_map<char,int> h_s;

        for(auto c : t)
            h_p[c]++;

        int count =0;
        int f_start = -1;
        int len = INT_MAX;
        int start = 0;

        for(int i =0;i<n;i++){
            h_s[s[i]]++;

            if(h_p[s[i]] != 0 && h_s[s[i]] <= h_p[s[i]]) count++;
            if(count == m){
                while(h_p[s[start]] == 0 || h_s[s[start]] > h_p[s[start]]) {
                    if(h_s[s[start]] > h_p[s[start]]) h_s[s[start]]--;
                    start++;
                }

                int l = i-start+1;
                if(l < len) {
                    len = l;
                    f_start = start;
                }
            }
        }
        
        if(f_start == -1) return string("");
        return s.substr(f_start,len);
    }
};

int main(){
    string s = "ADOBECODEBANC";
    string p = "ABC";
    Solution o;
    cout<<o.minWindow(s,p)<<endl;
    return 0;
}