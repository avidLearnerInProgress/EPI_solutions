//finding and remove loop in LL
//https://ide.geeksforgeeks.org/KhlNf75cDP

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

void findAndRemoveLoop(struct Node* head){
    
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
    if (slow == fast){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
    
}
  
int main() 
{ 
    Node* head = newNode(50); 
    head->next = newNode(20); 
    head->next->next = newNode(15); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(10);
    head->next->next->next->next->next = head->next->next;  //loop
    findAndRemoveLoop(head);
    printLL(head);
    return 0; 
} 
