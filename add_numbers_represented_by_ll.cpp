//add numbers represented by LL
//https://ide.geeksforgeeks.org/ZoHr7P69xu
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


void addLL(Node *first, Node *second){
    
    int sum = 0, carry = 0;
    Node *temp;
    Node *prev = NULL;
    Node *res = NULL;
    
    while(first != NULL || second != NULL){
        sum = carry + (first? first->data : 0) + (second? second->data : 0);
        carry = (sum) > 10 ? 1:0;
        sum = sum%10;
        
        temp = newNode(sum);
        
        if(res == NULL){
            res = temp;
        }
        else{
            prev->next = temp;
        }
        
        prev = temp;
        
        if(first) 
            first = first->next;
        if(second)
            second = second->next;
    }
    
    if(carry > 0) temp->next = newNode(carry);
    printLL(res);
}



int main() 
{ 

	Node* head1 = newNode(9); 
	head1->next = newNode(2); 
	head1->next->next = newNode(3); 


	Node* head2 = newNode(1); 
	head2->next = newNode(2); 
	head2->next->next = newNode(3); 
	
    
    addLL(head1, head2);
    return 0; 
} 
