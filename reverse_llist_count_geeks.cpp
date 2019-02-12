#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
    Node(int d=0, Node* n=NULL) {
      data=d;
      next = n;
    }
};

Node *reverse (Node *head, int k)
{
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	int count = 0;

	while (current != NULL && count < k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	if (next) head->next = reverse(next, k);
	return prev;
}

void push(struct Node** head_ref, int new_data) {
    Node *new_node = new Node(new_data);
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *node) {
	while (node) {
		printf("%d ", node->data);
		node = node->next;
	}
    cout<<endl;
}

int main(void) {
	Node* head = NULL;

	/* Created Linked list is 1->2->3->4->5->6->7->8->9 */
	push(&head, 9);
	push(&head, 8);
	push(&head, 7);
	push(&head, 6);
	push(&head, 5);
	push(&head, 4);
	push(&head, 3);
	push(&head, 2);
	push(&head, 1);

	printf("Given linked list \n");
	printList(head);
    cout<<endl;
	head = reverse(head, 3);

	printf("Reversed Linked list \n");
	printList(head);

	return(0);
}

