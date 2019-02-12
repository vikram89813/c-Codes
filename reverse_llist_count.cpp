#include<iostream>
#include<forward_list>
#include<list>

using namespace std;

void printList(forward_list<int> l) {
  for(auto i:l) cout<<i<<" ";
  cout<<endl;
}

forward_list<int> reverse_(forward_list<int> &head, int k) {
  forward_list<int> *prev = NULL;
  forward_list<int> *next = NULL;
  forward_list<int> *curr = &head;

  int c=0;
  while(curr != NULL && c<k) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    c++;
  }
  if(next)
    curr->next = reverse_(next,k);

  return prev;
}

int main(void)
{
    //struct Node* head = NULL;

     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     /*push(&head, 9);
     push(&head, 8);
     push(&head, 7);
     push(&head, 6);
     push(&head, 5);
     push(&head, 4);
     push(&head, 3);
     push(&head, 2);
     push(&head, 1);*/
     forward_list<int> head;
     for(int i=9;i>=1;i--) head.push_front(i);


     printf("\nGiven linked list \n");
     printList(head);
     head = reverse_(head, 3);
     //head = reverse(head, 3);
     //printf("\nReversed Linked list \n");
     //printList(head);
     return(0);
}
