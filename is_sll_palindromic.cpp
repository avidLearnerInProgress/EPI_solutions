//is SLL palindromic
//https://ide.geeksforgeeks.org/OrwKA8z84i
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

int countLL(struct Node *head){
    if(head == NULL) return 0;
    int cnt = 1;
    while(head){
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
}

Node* reverseLL(Node *head){
    
    
    //return head;
}

void isSLLPalindromic(Node *head){
    if(head == NULL) return;
    
    Node *traverse = head;
    Node *c1 = head;
    int total = countLL(traverse);
    int mid = total/2;
    if(mid%2 == 0) mid = mid -1;
    
    for(int i=1; i<=mid; i++){
        if(traverse == NULL) return;
        traverse = traverse->next;
    }
    if(traverse == NULL) return;
    
    Node *subHead = traverse->next;
    Node *prev = NULL;
    Node *next;
    Node *curr = subHead;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    subHead = prev;
    Node *c2 = subHead;
    
    bool flag = true;
    for(int i=1; i<=mid; i++){
        if(c1->data != c2->data){
            flag = false;
        }
        c1 = c1->next;
        c2 = c2->next;
    } 
    
    if(!flag){
        cout<<"Not palindrome"<<"\n";
    }
    else{
        cout<<"Palindrome"<<"\n";
    }

    //printLL(head);
}

int main() 
{ 

	Node* head1 = newNode(1); 
	head1->next = newNode(2); 
	head1->next->next = newNode(3); 
	head1->next->next->next = newNode(4);
	head1->next->next->next->next = newNode(3); 
	head1->next->next->next->next->next = newNode(2); 
	head1->next->next->next->next->next->next = newNode(1);

    
	Node* head2 = newNode(1); 
	head2->next = newNode(2); 
	head2->next->next = newNode(3); 
	head2->next->next->next = newNode(4);
	head2->next->next->next->next = newNode(3); 
	head2->next->next->next->next->next = newNode(2); 
	head2->next->next->next->next->next->next = newNode(5);
    
    printLL(head1);
    isSLLPalindromic(head1);
    cout<<"\n";
    printLL(head2);   
    isSLLPalindromic(head2);
    return 0; 
} 
