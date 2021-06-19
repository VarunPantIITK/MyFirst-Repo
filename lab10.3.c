#include <stdio.h>
#include <malloc.h>

typedef struct ListNode {
     char val;
     struct ListNode *next;
}Node;


int isPalindrome(Node *head);
Node* take_input(int n);

// Do not change anything above this line
Node* createNode(char dt){
    Node* n=(Node*)malloc(sizeof(Node));
    n->val=dt;
    n->next=NULL;
    return n;
}
int length(Node *head){
    Node *tmp = head;
    int counter = 0;

    while(tmp != NULL){
        counter += 1;
        tmp = tmp->next;
    }
    return counter;
}

char GetNthfromStart(Node* head, int index)
{
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index)
            return current->val;
        count++;
        current = current->next;
    }
}

int isPalindrome(Node *head) {
    int flag=0;
    int len=length(head);
    int i=0, j=len-1;//if this doesnt work do 0 and -1
    while (i<j)
    {
        float average=(GetNthfromStart(head, i)+GetNthfromStart(head,j)-192)/2;
        if(average!=(27/2)){
            flag=1;
            break;
        }
        i++;
        j--;
    }
    if (flag==1)
    {
        return 0;
    }
    else return 1;        
    // write code here    
}

Node* take_input(int n){
    Node *head=NULL,*tail=NULL,*pt;
    char ch;
    for(int i=0;i<n;i++){
        scanf("%c",&ch);
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
	// Write code to take input here, do not change the return type.
}

// Do not change anything below this line

int main(){
	int n;
	scanf("%d\n",&n);
	Node* head=take_input(n);
	if(isPalindrome(head)) printf("Special String\n");
	else printf("Not a special string\n");

}