//singly linked list  insert and delete api - reusable functions
//https://ide.geeksforgeeks.org/M1lUVBCMaT

#include<bits/stdc++.h>
using namespace std;

//Singly Linked List Template
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

//createNode
struct Node* createNode(int data){
    struct Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

//printLL
void printLL(struct Node* head){
    if(head == NULL) return;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

struct Node* mergeLL(struct Node* A, struct Node* B){
    struct Node* dummy = createNode(0);
    struct Node* temp = dummy;
    
    while(A && B){
        if(A->data <= B->data){
            temp->next = A;
            temp = temp->next;
            A = A->next;
        }
        else{
            temp->next = B;
            temp = temp->next;
            B = B->next;
        }
    }
    
    if(!A) temp->next = B;
    if(!B) temp->next = A;
    
    return dummy->next;
}

int main(){

    struct Node* head1 = createNode(2); 
    head1->next = createNode(4); 
    head1->next->next = createNode(6); 
  
    struct Node *head2 = createNode(1); 
    head2->next = createNode(3); 
    head2->next->next = createNode(5); 
  
    struct Node* head = mergeLL(head1, head2);
    printLL(head);
    
}
