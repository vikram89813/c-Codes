#include<bits/stdc++.h>

using namespace std;

struct trie {
  bool eow;
  char c;
  trie *a[26];
};

string alpha = "abcdefghijklmnopqrstuvwxyz";

trie t_arr[3000];
int t_idx;
trie t;
int N;
string query;

void insert_(trie *tr, string word) {
  int len = word.size();
  int i=0;
  while(tr && i<len) {
    if(!tr->a[word[i] - 'a']) {
      trie *t = &t_arr[t_idx++];
      for(int i=0;i<26;i++) t->a[i] = NULL;
      t->eow = false;
      t->c = word[i];
      tr->a[word[i] - 'a'] = t;
      tr = tr->a[word[i] - 'a'];
      i++;
      if(i==len) tr->eow = true;
    }
    else {
      tr = tr->a[word[i] - 'a'];
      i++;
    }
  }
}

void get_s(trie *tr,string word) {
  if(tr->eow) {
    cout<<word<<" ";
    return;
   }

  for(int i=0;i<26;i++) {
    if(tr->a[i]) get_s(tr->a[i],word + alpha[i]);
  }
}

void init() {
  t_idx = 0;
  t = t_arr[t_idx++];
  for(int i=0;i<26;i++) t.a[i] = NULL;
}

void sol() {
  string pre = "";
  int len = query.size();
  trie *prev = &t;
  int i=0;
  for(;i<len;i++) {
    pre+=query[i];
    prev = prev->a[pre[i] - 'a'];
    if(!prev) {cout<<0<<endl;i++;break;}
    get_s(prev,pre);
    cout<<endl;
  }
  while(i<len) {cout<<0<<endl;i++;}
}

int main() {
  int T;
  cin>>T;
  while(T--) {
    init();
    cin>>N;
    int n = N;
    while(n--) {
      string term;
      cin>>term;
      insert_(&t,term);
    }
    cin>>query;
    sol();
  }
  return 0;
}
