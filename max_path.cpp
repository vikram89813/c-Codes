#include<iostream>
#include<climits>

using namespace std;

struct node {
  int val;
  node *left;
  node *right;

  node(int v, node *l=NULL,node *r=NULL) {
    left = l;
    right = r;
    val = v;
  }
};

int ans = INT_MIN;

int cal(node *root) {
  if(!root) return -9999;
  if(!root->left && !root->right) return root->val;
  int l,r;
  l = cal(root->left);
  r = cal(root->right);
  ans = max(max(l,r),ans);
  ans = max(ans,root->val);
  ans = max(max(max(l+root->val, r+root->val), l+r+root->val),ans);
  return max(max(root->val+l, root->val+r),root->val);
}

int main() {
  node *root = new node(-10);
  root->left = new node(9);
  root->right = new node(20);
  root->right->left = new node(15);
  root->right->right = new node(7);
  cal(root);
  if(ans == INT_MIN) cout<<root->val<<endl;
  else cout<<ans<<endl;
  return 0;
}
