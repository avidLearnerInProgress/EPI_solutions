//Remove kth last node from LinkedList
//https://ide.geeksforgeeks.org/wzUwymfw8I
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

void cyclicRotateRight(Node *head, int k){
    Node *traverse = head;
    int cnt = 1;
    while(cnt < k && traverse!= NULL){
        traverse = traverse->next;
        cnt++;
    }
    if(traverse == NULL) return;
    Node *kthNode = traverse;
    while(traverse->next != NULL)traverse = traverse->next;
    traverse->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
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
    int k = 4; //rotate key
    cyclicRotateRight(head1, k);
    return 0; 
} 
