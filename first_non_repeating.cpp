#include<iostream>
#include<unordered_map>

using namespace std;

void firstNonRepeating(string &str) {
    vector<int> h(26,0);
    unordered_map<char,int> hc;
    for(int i=0;i<str.size();i++) {
        h[str[i] - 'a'] = i;
        if(hc.find(str[i]) == hc.end()) hc[str[i]] = 1;
        else hc[str[i]] += 1;
    }
    char ans;
    for(int i=0;i<26;i++) {
        if(hc.find(i + 'a') != hc.end()) {
            if(hc[i+'a'] == 1) {
                //set the value here.
            }
        } 
    }
    cout<<ans<<endl;
}

int main() 
{ 
    string str = "geeksforgeeks";
    //string str = "geekg"; 
    firstNonRepeating(str); 
    return 0; 
} 