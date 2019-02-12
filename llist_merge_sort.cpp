#include<iostream>

using namespace std;

struct Node {
  int val;
  Node *next;
  Node(int v=0,Node *n=NULL) {
    val = v;
    next = n;
  }
};

void push(Node **head, int v) {
  Node *t = new Node(v);
  t->next = *head;
  *head = t;
}

void printList(Node *head) {
  while(head) {
    cout<<head->val<<" ";
    head = head->next;
  }
  cout<<endl;
}

Node * Merge(Node *a, Node *b) {
  Node *res=NULL;
  if(!a) return b;
  if(!b) return a;
  if(a->val <= b->val) {
    res = a;
    res->next = Merge(a->next,b);
  }
  else {
    res = b;
    res->next = Merge(a,b->next);
  }
  return res;
}

void find_middle(Node *head, Node **a, Node **b) {
  Node *slow = head;
  Node *fast = head;
  Node *prev = NULL;
  while(fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  *b = slow;
  if(prev)
    prev->next = NULL;
  *a = head;
}

void MergeSort(Node **head) {
  if(!(*head) || !(*head)->next) return;
  Node *a;
  Node *b;
  find_middle(*head,&a,&b);
  MergeSort(&a);
  MergeSort(&b);
  *head = Merge(a,b);
}

int main() {
  Node* a = NULL;

  //Created list a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);
  push(&a, 20);
  push(&a, 3);
  push(&a, 2);

  MergeSort(&a);

  printf("Sorted Linked List is: \n");
  printList(a);

  return 0;
}
