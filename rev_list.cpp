#include<iostream>

using namespace std;

struct node {
    int val;
    node *next;
};

class llist {
  public:
    node *head,*tail,*break_;

    llist() {head = NULL;tail=NULL;}

    void insert_(int v) {
      node* tmp = new node;
      tmp->val = v;
      tmp->next = NULL;
      if(head)
      {
        tail->next= tmp;
        tail = tmp;
      }
      else {
        head = tmp;
        tail = tmp;
      }
    }

    void print_list()
    {
      node *tmp = head;
      while(tmp)
        {cout<<tmp->val<<" ";tmp=tmp->next;}
      cout<<endl;
    }

    node* get_head() {return head;}

    node* get_mid() {
      node *fast = head;
      node *slow = head;
      node* prev = NULL;
      while(fast && fast->next)
      {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
      }
      prev->next = NULL;
      break_ = prev;
      return slow;
    }

    bool palin(node *h)
    {
      node* t1 = head;
      node* t2 = h;
      while(t1 && t2)
      {
        if(t1->val == t2->val) {
          t1 = t1->next;
          t2 = t2->next;
        }
        else return false;
      }
      return true;
    }
    void fix_(node *mid)
    {
      break_->next = mid;
    }
};

void rev(node **head)
{
  node *prev = NULL;
  node *next;
  node *temp = *head;
  while(temp)
  {
    next = temp->next;
    temp->next = prev;
    prev = temp;
    temp = next;
  }
  *head = prev;
}

int main()
{
  llist A;
  A.insert_(1);
  A.insert_(2);
  A.insert_(3);
  A.insert_(3);
  A.insert_(2);
  A.insert_(1);

  node *mid = A.get_mid();
  rev(&mid);
  if(A.palin(mid)) cout<<"yes"<<endl;
  else cout<<"no"<<endl;
  rev(&mid);
  A.fix_(mid);
  return 0;
}
