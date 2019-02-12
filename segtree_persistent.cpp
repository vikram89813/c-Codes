#include<iostream>

using namespace std;

#define MAX 100

struct node {
  int val;
  node *left;
  node *right;

  node(node *l,node *r,int v) {
    left = l;
    right = r;
    val = v;
  }
};

node* version[MAX];
int arr[MAX];

void build(node *root, int l,int r) {
  if(l == r) {
    root->val = arr[l];
    return;
  }

  root->left = new node(NULL,NULL,0);
  root->right = new node(NULL,NULL,0);
  int m = l + (r-l)/2;
  build(root->left, l , m);
  build(root->right, m+1 , r);
  root->val = root->left->val + root->right->val;
}

void upgrade(node *prev,node *curr, int l ,int r, int idx, int val) {
  if(idx < l || idx > r || l>r) return;
  if(l==r) {
    curr->val = val;
    return;
  }
  int m = l + (r-l)/2;
  if(idx <= m) {
    curr->right = prev->right;
    curr->left = new node(NULL,NULL,0);
    upgrade(prev->left,curr->left,l,m,idx,val);
  }
  else {
    curr->left = prev->left;
    curr->right = new node(NULL,NULL,0);
    upgrade(prev->right,curr->right,m+1,r,idx,val);
  }
  curr->val = curr->left->val + curr->right->val;
}

int query(node *root,int l,int r,int ql,int qr) {
  if(ql > r || qr < l || l>r) return 0;
  if(ql <= l && qr>=r) return root->val;
  int m = l + (r-l)/2;
  return query(root->left,l,m,ql,qr) + query(root->right,m+1,r,ql,qr);
}

int main(int argc, char const *argv[]) {
    int A[] = {1,2,3,4,5};
    int n = sizeof(A)/sizeof(int);

    for (int i=0; i<n; i++)
       arr[i] = A[i];

    node* root = new node(NULL, NULL, 0);
    build(root, 0, n-1);

    version[0] = root;

    version[1] = new node(NULL, NULL, 0);
    upgrade(version[0], version[1], 0, n-1, 4, 1);

    version[2] = new node(NULL, NULL, 0);
    upgrade(version[1],version[2], 0, n-1, 2, 10);

    cout << "In version 1 , query(0,4) : ";
    cout << query(version[1], 0, n-1, 0, 4) << endl;
    cout << "In version 2 , query(3,4) : ";
    cout << query(version[2], 0, n-1, 3, 4) << endl;
    cout << "In version 0 , query(0,3) : ";
    cout << query(version[0], 0, n-1, 0, 3) << endl;

    return 0;
}
