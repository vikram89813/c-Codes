#include<iostream>

using namespace std;

//not modifiable
struct node {
    int val;
    node *next;
    node(int v=0,node *n=nullptr) {
        val=v;
        next=n;
    }
};

// u can modify only this method.
void insert_(node* head,int num) {
    node *t = new node(num);
    t->next = head;
    head = t;
}

// not modifiable
void create_l() {
    node *head = nullptr;
    int num=2;
    while(num) {
        insert_(head,num);
        num--;
    }

    // expected o/p 1->2
    while(head!=nullptr) {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

int main() {
    node *head=nullptr;
    create_l();
    return 0;
}