/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };

int traverse(ListNode* );

int main()
{
    int i;
    struct ListNode* head = NULL;
    
    //Initializing the list

    for(i=10; i>=1; i--)
    {

        struct ListNode* B = (ListNode*)malloc(sizeof(struct ListNode));

        B->val = i;
        B->next = head;
        head = B;
    }

    struct ListNode* ptr = head;
    while(ptr->next!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<"\n";

    int D = traverse(head);
    cout<<"\n";

    ptr = head;

    while(ptr->next!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }

    cout<<"\n";
}

int traverse(ListNode* A)
{
    if(A->next->next == NULL)
    {
        cout<<A->val<<" ";
        return A->val;
    }
    
    A->val = traverse(A->next);
}