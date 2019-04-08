//Merge two linked lists
//https://ide.geeksforgeeks.org/YSEVWnXdSk

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head;

//createNode
struct Node* createNode(int data){
    struct Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;
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

struct Node* mergeLL1(struct Node* A, struct Node* B){
    struct Node* head;
    if(A == NULL &&  B == NULL) return NULL;
    if(A == NULL) return B;
    else if(B == NULL) return A;
    else{
        
        //set the head
        
        if(A->data <= B->data){
            head = A; A = A->next;
            head->prev = NULL;
        }
        else{
            head = B; B = B->next;
            head->prev = NULL;
        }
        
        struct Node* curr = head; //now we have head set lets loop in
        
        while((A != NULL) || (B != NULL)){
            if(A == NULL){
                curr->next = B;
                B->prev = curr;
                return head;
            }
            else if(B == NULL){
                curr->next = A;
                A->prev = curr;
                return head;
            }
            else{
                if(A->data <= B->data){
                    curr->next = A;
                    A->prev = curr;
                    curr = curr->next;
                    A = A->next;
                }
                else{
                    curr->next = B;
                    B->prev = curr;
                    curr = curr->next;
                    B = B->next;
                }
            }
        }
        curr->next = NULL;
        return head;
    }
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
    head1->prev = NULL;
    head1->next->next = createNode(6); 
    head1->next->prev = head1;
    head1->next->next->prev = head1->next->prev;
    
    struct Node *head2 = createNode(1); 
    head2->next = createNode(3); 
    head2->prev = NULL;
    head2->next->prev = head2;
    head2->next->next = createNode(5); 
    head2->next->next->prev = head2->next->prev;
    
    struct Node* head = mergeLL1(head1, head2);
    printLL(head);
    
}
