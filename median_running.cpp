#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

struct Node {
  int data;
  int height;
  Node *left;
  Node *right;
};

Node * new_node(int v) {
  Node *t = new Node();
  t->data = v;
  t->left= NULL;
  t->right = NULL;
  t->height = 1;
  return t;
}

int height_(Node *n) {
  if(n) return n->height;
  return 0;
}

int get_balance(Node *n) {
  if(n) return height_(n->left) - height_(n->right);
  return 0;
}

Node * right_rotate(Node *y) {
  Node *x = y->left;
  Node *t2 = x->right;
  x->right = y;
  y->left = t2;
  y->height = 1 + max(height_(y->left),height_(y->right));
  x->height = 1 + max(height_(x->left),height_(x->right));
  return x;
}

Node * left_rotate(Node *x) {
  Node *y = x->right;
  Node *t2 = y->left;
  y->left = x;
  x->right = t2;
  x->height = 1 + max(height_(x->left),height_(x->right));
  y->height = 1 + max(height_(y->left),height_(y->right));
  return y;
}

Node * insert_(Node *root,int val) {
  if(root == NULL) return new_node(val);

  if(val <= root->data) root->left = insert_(root->left,val);
  else if (val > root->data) root->right = insert_(root->right,val);

  root->height = 1 + max(height_(root->left),height_(root->right));
  int b = get_balance(root);

  if(b > 1 && get_balance(root->left) >= 0) return right_rotate(root);
  if(b < -1 && get_balance(root->right) <= 0) return left_rotate(root);

  if(b > 1 && get_balance(root->left) < 0) {
    root->left = left_rotate(root->left);
    return right_rotate(root);
  }

  if(b < -1 && get_balance(root->right) > 0) {
    root->right = right_rotate(root->right);
    return left_rotate(root);
  }

  return root;
}

void preOrder(Node *root) {
  if(root != NULL) {
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

Node * inorder_succ(Node *root) {
  Node *t = root;
  while(t->left != NULL) t = t->left;
  return t;
}

Node * deleteNode(Node* root, int val) {
  if(!root) return root;
  if(val < root->data)
    root->left = deleteNode(root->left,val);
  else if(val > root->data)
    root->right = deleteNode(root->right,val);
  else {
    if(root->left == NULL || root->right == NULL) {
      Node * t = root->left?root->left:root->right;
      if(!t) {
        t = root;
        root = NULL;
      } else *root = *t;

      delete(t);
    } else {
      Node *t = inorder_succ(root->right);
      root->data = t->data;
      root->right = deleteNode(root->right,t->data);
    }
  }
    root->height = 1 + max(height_(root->left),height_(root->right));
    int b = get_balance(root);

    if(b > 1 && get_balance(root->left) >= 0) return right_rotate(root);
    if(b > 1 && get_balance(root->left) < 0) {
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }
    if(b < -1 && get_balance(root->right) <= 0) return left_rotate(root);
    if(b < -1 && get_balance(root->right) > 0) {
      root->right = right_rotate(root->right);
      return left_rotate(root);
    }
  return root;
}

int cal(Node *root) {
  if(get_balance(root) == 0) return (root->data);
  if(get_balance(root) == 1) return (float)(float(root->data)+float(root->left->data))/2.0;
  if(get_balance(root) == -1) return (float)(float(root->data)+float(root->right->data))/2.0;
}

int main()
{
    Node *root = NULL;
    vector<int> arr = {5, 15, 10, 20, 3};
    //vector<int> arr = {5, 15};
    //vector<int> arr = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    for(auto i : arr) {
      root = insert_(root,i);
      float cal_ = cal(root);
      cout<<cal_<<endl;
    }
    return 0;
}
