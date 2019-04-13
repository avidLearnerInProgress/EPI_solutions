//finding starting point of loop in LL
//https://ide.geeksforgeeks.org/srPsOYSEEm

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

struct Node* findAndDetectLoop(struct Node* head){
    
    struct Node* fast = head;
    struct Node* slow = head;
    
    slow = slow->next; 
    fast = fast->next->next; 
  
    
    while(fast && fast->next){
        if(slow == fast){
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != fast) 
        return NULL; 
        
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
  
int main() 
{ 
    Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;  //loop
    Node* find = findAndDetectLoop(head);
    cout<<"Starting point of loop is: "<<find->data<<"\n";
    return 0; 
} 
