#include<bits/stdc++.h>

using namespace std;

vector<int> shortestToChar(string s, char c) {
    int si = s.size();
    vector<int> res(si,INT_MAX);
    vector<int> h;
    stack<int> s;
    int idx=-1;
    for(int i=0;i<si;i++) {
        if(s[i]==c) {
            h.push_back(i);
        }
    }

    int nidx = h[0];
    for(int i=0;i<nidx;i++) {
        int t = abs(i-nidx);
        res[i] = min(t,res[i]);
    }

    res[nidx] = 0;

    //int nidx = 


}

int main() {
    string str = "loveleetcode";
    char c='e';
    vector<int> res = shortestToChar(str,c);
    for(auto i:res) cout<<i<<" ";
    cout<<endl;
    return 0;
}