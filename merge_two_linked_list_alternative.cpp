//Merge two linked lists
//https://ide.geeksforgeeks.org/XEdZQrsmGH

#include<bits/stdc++.h>
using namespace std;

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

struct Node* mergeLL1(struct Node* A, struct Node* B){
    struct Node* head;
    if(A == NULL &&  B == NULL) return NULL;
    if(A == NULL) return B;
    else if(B == NULL) return A;
    else{
        
        //set the head
        
        if(A->data <= B->data){
            head = A; A = A->next;
        }
        else{
            head = B; B = B->next;
        }
        
        struct Node* curr = head; //now we have head set lets loop in
        
        while((A != NULL) || (B != NULL)){
            if(A == NULL){
                curr->next = B;
                return head;
            }
            else if(B == NULL){
                curr->next = A;
                return head;
            }
            else{
                if(A->data <= B->data){
                    curr->next = A;
                    curr = curr->next;
                    A = A->next;
                }
                else{
                    curr->next = B;
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
    head1->next->next = createNode(6); 
  
    struct Node *head2 = createNode(1); 
    head2->next = createNode(3); 
    head2->next->next = createNode(5); 
  
    struct Node* head = mergeLL1(head1, head2);
    printLL(head);
    
}
