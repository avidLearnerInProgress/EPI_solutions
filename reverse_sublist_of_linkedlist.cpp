//reverse sublist of list
//
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

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

void insertAtBegin(int data){
    
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

struct Node* reverseList(){
    if(head == NULL) return NULL;
    
    struct Node *curr = head;
    struct Node *prev = NULL;
    struct Node *next;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

struct Node* reverseSubList(int m, int n){
    struct Node* start = NULL, prev_start = NULL, end = NULL, next_end = NULL;
    struct Node* current = head;
    int i = 1;
    
    if(m == n)return head;
    
    while(current && i < n){
        if(i < m)prev_start = current;
        if(i == m){
            start = current;
        }
        if(i == n){
            end = current;
            next_end = current->next;
        }
        i++;
        current = current->next;
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


int main(){
    
    head = NULL;
    int n; cin>>n;
    
    for(int k=0; k<n; k++){
        int current; cin>>current;
        insertAtBegin(current);
    }
    
    printLL(head);
    head = reverseSubList();
    printLL(head);
    
}
