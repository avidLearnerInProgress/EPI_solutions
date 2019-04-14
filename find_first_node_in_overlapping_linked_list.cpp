//overlapping lists
//https://ide.geeksforgeeks.org/QtpSzB97eS

/*
if the two linked lists do share a node, 
then they must have the same tail node.
*/

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

Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

int Len(struct Node* A){
    int len = 0;
    while(A!=NULL){
      A = A->next;
      len++;
    }
    cout<<len<<"\n";
    return len;
}

int overlappingLists(struct Node* l1, struct Node* l2){
    int l1_len = Len(l1);
    int l2_len = Len(l2);
    //cout<<"Length: "<<l1_len<<"\t"<<l2_len;
    int increment = abs(l1_len - l2_len);
    cout<<increment<<l1_len<<l2_len<<"reached";
    
    for(int i=0; i<increment; i++){
     l1 = l1->next;
    }
     
    while(l1!=NULL && l2!=NULL){
        if(l1->data == l2->data){
            return l1->data;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    return 0;
}
  
int main() 
{ 
    Node* head1 = newNode(50); 
    head1->next = newNode(20);
    head1->next->next = newNode(30); 
    head1->next->next->next = newNode(40); 
    head1->next->next->next->next = newNode(15); 
    printLL(head1);
    
    Node* head2 = newNode(30);
    head2->next = newNode(40); 
    head2->next->next = newNode(15); 
    printLL(head2);
    
    cout<<"\nFound start of overlapping list: "<<overlappingLists(head1, head2);
    return 0; 
} 
