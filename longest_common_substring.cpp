#include<bits/stdc++.h>

using namespace std;

int lcs( string &X, string &Y) 
{ 
    int m = X.size();
    int n = Y.size();
   int L[m+1][n+1]; 
   int i, j; 

   for (i=0; i<=m; i++) 
   { 
     for (j=0; j<=n; j++) 
     { 
       if (i == 0 || j == 0) 
         L[i][j] = 0; 
   
       else if (X[i-1] == Y[j-1]) 
         L[i][j] = L[i-1][j-1] + 1; 
   
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]); 
     } 
   } 
   return L[m][n]; 
} 

int main() {
    string s1 = "acab";
    string s2 = "cba";
    unordered_map<char,bool> h;
    for(auto c:s2) h[c] = true;

    bool flag = false;

    for(auto c : s1) {
        if(h.find(c) == h.end()) {
            flag = true;
            break;
        }
    }
    if(!flag) {
      int m = s1.size();
      int l = lcs(s1,s2);
      cout<<(m-l) + 1<<endl;
    }
    else {
        cout<<"0"<<endl;
    }
    return 0;
}

