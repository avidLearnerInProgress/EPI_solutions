//Circular Doubly linked list  insert and delete api - reusable functions
// This isn't tested

#include<bits/stdc++.h>
using namespace std;

//Circular Doubly Linked List Template
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

//createNode
struct Node* createNode(int data){
    struct Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

//printLL
void printLL(struct Node* head){
    if(head == NULL) return;
    struct Node* temp = head->next;
    while(temp != head){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

//insertAtBegin 
void insertAtBegin(int data){
    struct Node* newNode = createNode(data);
    struct Node* traverse = head;
    if(traverse == NULL){
        newNode->next = traverse;
        newNode->prev = traverse;
        head = newNode;
        return;
    }
    else{
        struct Node* last = traverse->prev;
        newNode = traverse->prev;
        newNode->next = traverse;
        newNode->prev = last;
        last->next = newNode;
        head = newNode;
        return;
    }
}

//insertAtEnd
void insertAtEnd(int data){
    struct Node* newNode = createNode(data);
    struct Node* traverse = head; //traverse till head->next is NULL and then insert
    if(head == NULL){
        newNode->next = traverse;
        newNode->prev = traverse;
        head = newNode;
        return;
    }
    struct Node* last = traverse->prev;
    //struct Node* lastlast = traverse->prev->prev;
    last->next = newNode;
    newNode->next = traverse;
    newNode->prev = last;
    last->prev = newNode;
    return;
}

//insertAfterNode
void insertAfterNode(int key, int data){
    struct Node* newNode = createNode(data);
    struct Node* travel = head;
    
    while(travel->data != key){
        travel = travel->next;
    }
    struct Node* aft = travel->next;
    travel->next = newNode;
    newNode->next = aft;
    newNode->prev = travel;
    aft->prev = newNode;
    return;
}

//deleteAtBegin
void deleteAtBegin(){
    if(head == NULL) return;
    
    struct Node* temp = head;
    
    if(temp->next == NULL){
        free(temp);
        return;
    }
    
    else{
        
        struct Node* temp = head;
        struct Node* last = temp->prev;
        last->next = temp->next;
        temp->next->prev = last;
        head = temp->next;
        free(temp);
        return;
    }
}


void deleteNodeByKey(int key){
    if(head == NULL) return;
    
    struct Node* traverse = head;
    struct Node* temp;
    struct Node* prevTemp = NULL;
    temp = traverse; prevTemp = traverse;
    while(temp->data != key){
        prevTemp = temp;
        temp = temp->next;
    }
    if(temp->next == traverse && prevTemp == NULL){
        traverse = NULL;
        free(temp);
        return;
    }
    
    prevTemp->next = temp->next;
    temp->next->prev = prevTemp;
    free(temp);
    return;
}


int main(){
    
    head = NULL;
    int n; cin>>n;
    
    for(int k=0; k<n; k++){
        int current; cin>>current;
        insertAtBegin(current);
    }
    
    printLL(head);
    
    insertAtEnd(80);
    printLL(head);
    
    insertAfterNode(40, 50);
    printLL(head);
    printLL(head);
    
    deleteAtBegin();
    
    printLL(head);
    
    deleteNodeByKey(40);
    printLL(head);
    
}


