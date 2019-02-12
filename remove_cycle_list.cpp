#include<iostream>
using namespace std;

struct Node {
	int key;
	Node *next;
    Node(int v=0,Node *n = NULL) {
      key = v;
      next = n;
    }
};

void printList(Node *head) {
	while (head != NULL) {
		cout << head->key << " ";
		head = head->next;
	}
	cout << endl;
}

void detectAndRemoveLoop(Node *head) {
  Node *slow = head;
  Node *fast = head;

  while(slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) break;
  }
  if(slow == fast) {
    slow = head;
    while(slow->next != fast->next) {
      slow= slow->next;
      fast = fast->next;
    }
    fast->next = NULL;
  }
}

int main()
{
	Node *head = new Node(50);
	head->next = head;
	head->next = new Node(20);
	head->next->next = new Node(15);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(10);
	head->next->next->next->next->next = head->next->next;

	detectAndRemoveLoop(head);
	printf("Linked List after removing loop \n");
	printList(head);

	return 0;
}

