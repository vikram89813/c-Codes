#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int,int> hash_;
unordered_map<int,int> hash2_;

struct node {
  int val;
  node *left;
  node *right;
};

node * getNode(int v) {
  node *t = new node();
  t->val = v;
  t->left= NULL;
  t->right = NULL;
  return t;
}

node *t = NULL;
void fillsucc(node *root) {
  if(root) {
    fillsucc(root->right);
    hash_[root->val] = (t?t->val:0);
    t = root;
    fillsucc(root->left);
  }
}

node *t1 = NULL;
void fillpre(node *root) {
  if(root) {
    fillpre(root->left);
    hash2_[root->val] = (t1?t1->val:0);
    t1 = root;
    fillpre(root->right);
  }
}

void fill(node *root) {
  if(root) {
    root->val = hash_[root->val] + hash2_[root->val];
    fill(root->left);
    fill(root->right);
  }
}

void cal(node *root) {
  fillsucc(root);
  fillpre(root);
  fill(root);
}

void preorderTraversal(node *root) {
  if(root) {
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

int main()
{
    // binary tree formation
    node* root = getNode(1); /*         1        */
    root->left = getNode(2);        /*       /   \      */
    root->right = getNode(3);       /*     2      3     */
    root->left->left = getNode(4);  /*    /  \  /   \   */
    root->left->right = getNode(5); /*   4   5  6   7   */
    root->right->left = getNode(6);
    root->right->right = getNode(7);

    cout << "Preorder Traversal before tree modification:"<<endl;
    preorderTraversal(root);
    cout<<endl;

    cal(root);

    cout << "\nPreorder Traversal after tree modification:"<<endl;
    preorderTraversal(root);
    cout<<endl;

    return 0;
}
