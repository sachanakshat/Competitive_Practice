#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void push(struct Node** head, int ndata){
    struct Node* new_node = new Node;
    new_node->data = ndata;
    new_node->next = *head;
    *head = new_node;
}

void print(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

Node* reverse(struct Node**head){
    struct Node* temp=*head;
    if(head!=NULL){
        while(temp!=NULL){
            temp->next=
        }
    }
}

int main(){
    int i;
    struct Node* head = NULL;
    cin>>i;
    for(;i>=0; i--){
        push(&head, i);
        // print(head);
    }
    print(head);
    return 0;
}