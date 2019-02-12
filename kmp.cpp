#include<bits/stdc++.h>

using namespace std;

int lps[10];

void preprocess(char *pat,int s) {
  int len = 0;
  int i=1;
  while(i<s) {
    if(pat[len] == pat[i])
      lps[i++] = len++;
    else {
      if(len) len = lps[len-1];
      else lps[i] = 0,i++;
    }
  }
}

void KMPSearch(char *pat,char *txt) {
  int pat_s = strlen(pat);
  int txt_s = strlen(txt);
  preprocess(pat,pat_s);
  int i=0,j=0;
  while(i<txt_s) {
    if(txt[i] == pat[j]) i++,j++;
    if(j == pat_s) cout<<"found @ : "<<i-j<<endl,j=lps[j-1];
    else if(txt[i] != pat[j]) {
      if(j) j = lps[j-1];
      else i++;
    }
  }
}

int main()
{
    char txt[] = "ABABDABACDABABCABABABABCABAB";
    char pat[] = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}
