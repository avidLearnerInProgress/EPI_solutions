//reverse sublist of list
//https://ide.geeksforgeeks.org/nkEw2JhDbC

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

void printLL(struct Node* head){
    if(head == NULL) return;
    while(head != NULL){
        cout<<head->data<<"\t";
        head = head->next;
    }
    cout<<"\n";
}

void insertAtBegin(struct Node* head, int data){
    
    struct Node* newNode = createNode(data);
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
        return;
    }
    else{
        newNode->next = head;
        head = newNode;
        return;
    }
}

struct Node* reverseList(struct Node* head) {
    if(head == NULL) return NULL;
    
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    //head = prev;
    return prev;
}

struct Node* reverseSubList(struct Node* head, int m, int n){
    struct Node* start = NULL;
    struct Node* prev_start = NULL;
    struct Node* end = NULL; 
    struct Node* next_end = NULL;
    struct Node* current = head;
    int i = 1;
    
    if(m == n)return head;
    
    while(current && i <= n){
        if(i < m)prev_start = current;
        if(i == m){
            start = current;
        }
        if(i == n){
            end = current;
            next_end = current->next;
        }
        current = current->next;
        i++;
    }
    end->next = NULL;
    end = reverseList(start);
    if(prev_start){
        prev_start->next = end;
    }
    else{
        head = end;
    }
    start->next = next_end;
    return head;
}

void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = new Node; 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  
int main() 
{ 
    struct Node* head = NULL; 
    push(&head, 70); 
    push(&head, 60); 
    push(&head, 50); 
    push(&head, 40); 
    push(&head, 30); 
    push(&head, 20); 
    push(&head, 10); 
    reverseSubList(head, 3, 6); 
    printLL(head); 
    return 0; 
} 
