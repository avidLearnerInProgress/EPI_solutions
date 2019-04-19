//Remove kth last node from LinkedList
//https://ide.geeksforgeeks.org/kFO6n0UB5N
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

void mergeEvenOdd(Node *head){
    Node *traverse = head;
    Node *eStart = NULL;
    Node *eEnd = NULL;
    Node *oStart = NULL;
    Node *oEnd = NULL;
    
    while(traverse!=NULL){
        int val = traverse->data;
        
        if(val%2 == 0){
            if(eStart == NULL){
                eStart = traverse;
                eEnd = eStart;
            }
            else{
                eEnd->next = traverse;
                eEnd = eEnd->next;
            }
        }
        else{
            if(oStart == NULL){
                oStart = traverse;
                oEnd = oStart;
            }
            else{
                oEnd->next = traverse;
                oEnd = oEnd->next;
            }
        }
        
        traverse = traverse->next;
    }
    
    if(oStart == NULL || eStart == NULL) return;
    eEnd->next = oStart;
    oEnd->next = NULL;
    head = eStart;
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
    mergeEvenOdd(head1);
    return 0; 
} 
