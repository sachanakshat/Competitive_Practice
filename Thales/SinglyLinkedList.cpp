#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node * prev = head;

    head->data = 1;
    for(int i=0; i<9; i++)
    {
        struct node* n1 = (struct node*)malloc(sizeof(struct node));
        n1->data = i;
        prev->next = n1;
        n1->next = NULL;

    }
    return 0;
}