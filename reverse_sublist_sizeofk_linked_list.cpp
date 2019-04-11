//reverse sublist of list
//https://ide.geeksforgeeks.org/xsGoV4klso
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printLL(struct Node* head){
    while(head != NULL){
        cout<<head->data<<"\t";
        head = head->next;
    }
    cout<<"\n";
}

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 


struct Node* reverseInSizeOfK(struct Node* head, int k){
    
    struct Node* prev = NULL;
    struct Node* current = head;
    stack<Node* > myst;
    
    while(current != NULL){
        int count = 0;
        while(current != NULL && count < k){
            myst.push(current);
            current = current->next;
            count++;
        }
        
        while(myst.size()> 0){
            if(prev == NULL){
                prev = myst.top();
                head = prev;
                myst.pop();
            }
            else{
                prev->next = myst.top();
                prev = prev->next;
                myst.pop();
            }
        }
    }
    prev->next = NULL;
    return head;
}
  
int main() 
{ 
    struct Node* head = NULL; 
    push(&head, 9);  
    push(&head, 8);  
    push(&head, 7);  
    push(&head, 6);  
    push(&head, 5);  
    push(&head, 4);  
    push(&head, 3);  
    push(&head, 2);  
    push(&head, 1);   
    printLL(head); 
    head = reverseInSizeOfK(head, 3);
    printLL(head); 
    return 0; 
} 
