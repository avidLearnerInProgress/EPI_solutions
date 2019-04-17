//Remove kth last node from LinkedList
//https://ide.geeksforgeeks.org/lrTyFZDqxi

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

void removeDuplicateNodes(Node *head){
    Node *first = head; Node *second = head;
    
    while(first){
        
        second = first->next;
        while(second && second->data == first->data){
            second = second->next;
        }
        first->next = second;
        first = second;
    }
    printLL(head);
}

int main() 
{ 

	Node* head1 = newNode(1); 
	head1->next = newNode(2); 
	head1->next->next = newNode(3); 
	head1->next->next->next = newNode(4);
	head1->next->next->next->next = newNode(4); 
	head1->next->next->next->next->next = newNode(4); 
	head1->next->next->next->next->next->next = newNode(5);
    printLL(head1);
    cout<<"\n\n";
    removeDuplicateNodes(head1);
    return 0; 
} 
