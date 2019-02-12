#include<bits/stdc++.h>

using namespace std;

struct node {
  int val;
  node* left;
  node* right;
};

node* insert_(int v)
{
  node *temp = new node;
  temp->val = v;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

void inorder(node *root)
{
  stack<node*> s;
  node *curr = root;
  while(!s.empty() || curr) {
    if(curr) {
      s.push(curr);
      curr=curr->left;
    }
    else {
      node *top = s.top();
      s.pop();
      cout<<top->val<<" ";
      curr = top->right;
    }
  }
}

void preorder(node *root)
{
  stack<node*> s;
  node *curr = root;
  s.push(curr);
  while(!s.empty()) {
    node *temp = s.top();
    s.pop();
    cout<<temp->val<<" ";
    if(temp->right) s.push(temp->right);
    if(temp->left) s.push(temp->left);
  }
}

void postorder(node *root)
{
  stack<node*> s;
  node *curr = root;
  vector<int> arr;
  s.push(curr);
  while(!s.empty()) {
    node *temp = s.top();
    arr.push_back(temp->val);
    s.pop();
    if(temp->left)
      s.push(temp->left);
    if(temp->right)
      s.push(temp->right);
  }
  reverse(arr.begin(),arr.end());
  for(auto i:arr) cout<<i<<" ";
}

int main()
{
  node *root = insert_(1);
  root->left = insert_(2);
  root->right= insert_(3);
  root->left->left= insert_(4);
  root->left->right= insert_(5);
  inorder(root);
  cout<<endl;
  preorder(root);
  cout<<endl;
  postorder(root);
  cout<<endl;
  return 0;
}
