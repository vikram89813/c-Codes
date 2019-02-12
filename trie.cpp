#include<iostream>

using namespace std;

struct trie {
  int eof;
  char data;
  trie *a[26];
};

trie tnode[50];
int gid;

trie t;

void init() {
  gid = 0;
  t = tnode[gid++];
  t.eof = 0;
  t.data = '\0';
  for(int i=0;i<26;i++) {
    t.a[i] = '\0';
  }
}

void add_word(trie *tr, char word[], int s) {
  int i =0;
  while(i<s) {
    if(!tr->a[word[i] - 'a']) {
      trie *tmp = &tnode[gid++];
      for(int j =0;j<26;j++) tmp->a[j] = '\0';
      tmp->eof = 0;
      tmp->data = word[i];
      tr->a[word[i] - 'a'] = tmp;
    }
    tr = tr->a[word[i] - 'a'];
    i++;
  }
  tr->eof = 1;
}

bool get_word(trie *tr, char word[], int s) {
  int i =0;
  while (tr && i<s) {
    if(tr->a[word[i] - 'a'] != '\0') {
      tr = tr->a[word[i] - 'a'];
      i++;
    } else if(i < s && !tr->a[word[i] - 'a']) return false;
  }
  if(!tr) return false;
  return tr->eof==1?true:false;
}

int main() {
  char arr1[] = "abcd";
  char arr2[] = "cda";
  char arr3[] = "bcda";
  char arr4[] = "bcdad";
  init();

  add_word(&t, arr1,4);
  add_word(&t, arr2,3);
  add_word(&t, arr3,4);

  if(get_word(&t,arr1,4)) cout<<"found word 1\n";
  else cout<<"Not found word 1\n";

  if(get_word(&t,arr2,3)) cout<<"found word 2\n";
  else cout<<"Not found word 2\n";

  if(get_word(&t,arr3,4)) cout<<"found word 3\n";
  else cout<<"Not found word 3\n";

  if(get_word(&t,arr4,5)) cout<<"found word 4\n";
  else cout<<"Not found word 4\n";

  return 0;
}













