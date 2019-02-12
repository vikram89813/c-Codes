#include<iostream>

using namespace std;

struct node {
  int val;
  node *next;
};

class llist {
  public:
  node *head;
  node *tail;
  llist() {head = NULL;tail=NULL;}

  void insert_(int v) {
    node *tmp = new node;
    tmp->val = v;
    tmp->next = NULL;
    if(head) {
      tail->next = tmp;
      tail = tmp;
    }
    else {
      head = tmp;
      tail = tmp;
    }
  }

  void print_(node *h)
  {
    node *tmp = h;
    while(tmp) {
      cout<<tmp->val<<" ";
      tmp = tmp->next;
    }
    cout<<endl;
  }

  node * get_head() {return head;}
};

void rev(node **h)
{
  node *prev = NULL;
  node *tmp = *h;
  node *next = NULL;
  while(tmp) {
    next = tmp->next;
    tmp->next = NULL;
    prev = tmp;
    tmp = next;
  }
  *h = prev;
}

int main()
{
  llist A;
  A.insert_(1);
  A.insert_(2);
  A.insert_(3);
  A.insert_(4);
  A.insert_(5);
  node *h = A.get_head();
  node *prev = NULL;
  node *prev2 = NULL;
  int m = 2,n=4;
  node *f = NULL;
  node *e = NULL;
  for(int i=1;i<=m;i++) {
    prev = h;
    h = h->next;
  }
  f = h;
  prev->next = NULL;
  for(int i=1;i<n-m;i++)
  {
    prev2 = h->next;
    h = h->next;
  }
  e = h;
  e->next = NULL;
  rev(&f);
  prev->next = f;
  e->next = prev2;
  //A.print_(A.get_head());
  node *he = A.get_head();
  return 0;
}
