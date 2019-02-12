#include<iostream>
#include<unordered_map>

using namespace std;

struct node {
  char val;
  node *left;
  node *right;

  node(char v, node *l=NULL,node *r=NULL) {
    val=v;
    left = l;
    right = r;
  }
};

unordered_map<char,int> hash_;

void make_hash(string &in) {
  int i=0;
  for(auto c : in) hash_[c] = i++;
}

void printInorder(node *root) {
  if(root) {
    printInorder(root->left);
    cout<<root->val<<" ";
    printInorder(root->right);
  }
}

int idx = 0;

node * buildTree(string pre, int s,int e) {
  if(s > e) return NULL;
  node *t = new node(pre[idx++]);
  if(s==e) return t;
  int i = hash_[t->val];
  t->left = buildTree(pre,s,i-1);
  t->right = buildTree(pre,i+1,e);
  return t;
}

int main()
{
    string in = { 'D', 'B', 'E', 'A', 'F', 'C' };
    string pre = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = in.size();
    make_hash(in);
    node* root = buildTree(pre, 0, len - 1);
    printf("Inorder traversal of the constructed tree is \n");
    printInorder(root);
    cout<<endl;
}
