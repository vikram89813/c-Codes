#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isMatch(string text, string pat) {
        int i=0;
        while(i < pat.size()) {
            if(pat[i] == '*') {
                 int s = i;
                int len =0;
                while(pat[i] == '*') {
                    len++;
                    i++;
                }
                pat.erase(s+1,len-1);
                i++;
            } else i++;
        }
        int n = text.size();
        int m = pat.size();
        bool dp[n+1][m+1];
        for(int i=0;i<n+1;i++) {
            for(int j=0;j<m+1;j++)
                dp[i][j] = false;
        }
        dp[0][0] = true;

        if(m==0 && n==0) return true;

        for(int i=1;i<=m;i++) {
            if(pat[i-1] == '*') dp[0][i] = dp[0][i-1];
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(pat[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else if(pat[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(pat[j-1] == text[i-1]) dp[i][j] = dp[i-1][j-1];

                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution o;
    //string s = "babbbaabbaaaaabbababaaaabbbbbbbbbbabbaaaabbababbabaa";
    //string p = "**a****a**b***ab***a*bab";
    //string s = "acdcb";
    //string p = "a*c?b";

    string s = "adceb";
    string p = "*a*b";
    //string s = "aa";
    //string p = "a";
    //string s = "baaabab";
    //string p = "*****ba*****ab";
    //string s = "aaabbaabbbbabaabababaaaaabaabbbbababaaababbbabbaababaababbaabbbbbbabaaaababbbaaaaabaaaaaaaabbaaababba";
    //string p = "abb**bb**b*b******b*a**a*bba****a*b*a***a*a**abb**b*aa";
    cout<<o.isMatch(s,p)<<endl;
}