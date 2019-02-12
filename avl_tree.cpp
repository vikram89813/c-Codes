#include<iostream>
#include<algorithm>

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

int main()
{
    Node *root = NULL;
    root = insert_(root, 9);
    root = insert_(root, 5);
    root = insert_(root, 10);
    root = insert_(root, 0);
    root = insert_(root, 6);
    root = insert_(root, 11);
    root = insert_(root, -1);
    root = insert_(root, 1);
    root = insert_(root, 2);
    /* The constructed AVL Tree would be
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */
    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);
    cout<<endl;
    root = deleteNode(root, 10);
    /* The AVL Tree after deletion of 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */
    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);
    cout<<endl;
    return 0;
}
