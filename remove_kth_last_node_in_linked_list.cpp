//Remove kth last node from LinkedList
//https://ide.geeksforgeeks.org/X2GQ35qElm

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

void printLL(struct Node* head){
    if(head == NULL) return;
    while(head!=NULL){
        cout<<head->data<<" ";
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

void removeKthLastNode(Node *head, int k){
    Node *first = head; Node *second = head;
    
    while(k-- > 0)
            first = first->next;
    
    if(first == NULL)cout<<head->next<<"\n";

    first = first->next;
    while(first!= NULL){
        second = second->next;
        first = first->next;
    }
    second->next = second->next->next;
    printLL(head);
}

int main() 
{ 

	Node* head1 = newNode(1); 
	head1->next = newNode(2); 
	head1->next->next = newNode(3); 
	head1->next->next->next = newNode(4); 
	head1->next->next->next->next = newNode(5);
	head1->next->next->next->next->next = newNode(6);
	head1->next->next->next->next->next->next = newNode(7);
    printLL(head1);
    cout<<"\n\n";
    removeKthLastNode(head1, 5);
    return 0; 
} 
