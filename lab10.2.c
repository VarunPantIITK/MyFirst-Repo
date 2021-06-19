#include<stdio.h>
#include <stdlib.h>

// List node structure and related typedefs
// You can use your own "singly-linked-list" if you prefer.
typedef struct node {
    int val;
    struct node *next;
}ListNode;

ListNode * reverse(ListNode * head);
ListNode * swap(ListNode * head, int m, int n);


void printList(ListNode* head) 
{
    if (head==NULL)
        printf("Empty List");
    else{
        while(head->next!=NULL){
            printf("%d->",head->val);
            head=head->next;
        }
        printf("%d",head->val);
    }
    printf("\n");
}

ListNode* createNode(int dt){
    ListNode* n=(ListNode*)malloc(sizeof(ListNode));
    n->val=dt;
    n->next=NULL;
    return n;
}

ListNode* take_input(int n){
    ListNode *head=NULL,*tail=NULL,*pt;
    int ch;
    for(int i=0;i<n;i++){
        scanf("%d",&ch);
        pt=createNode(ch);
        if(head==NULL){
            tail=pt;
            head=tail;
        }
        else{
            tail->next=pt;
            tail=pt;
        }
    }
    return head;
}


ListNode * swap(ListNode * head, int m, int n)
{
    if(m==n){
        return head;
    }
    int count = 0;
    ListNode * current = head;
    ListNode * prev = NULL;
    ListNode * start;
    ListNode * end;
    ListNode * next;
    ListNode *part;
    while(count<m-1)
    {
        prev = current;
        current = current->next;
        ++count;
    }
    start=current;
    while(count < n-1)
    {
        current = current->next;
        ++count;
    }
    
    end = current;
    next = current->next;
    current->next = NULL;
    part = reverse(start);
    
    if(prev)
    {
        prev->next->next = next;
        prev->next = part;
        return head;
    }
    else
    {
        if(next) head->next = next;
        head = part;
        return head;
    }
}

ListNode * reverse(ListNode * head)
{
    int flag=0;
    if(head->next == NULL ) {
        flag=1;
    }
    else if(head == NULL){
        flag=1;
    }
    if (flag==1) return head;
    ListNode * temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main()
{
    int L;
    int m;
    int n;
    scanf("%d %d %d\n", &L,&m,&n);
    ListNode* head=take_input(L);
    head=swap(head, m, n);
    printList(head);
    return 0;
}