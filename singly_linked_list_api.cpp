//singly linked list  insert and delete api - reusable functions
//https://ide.geeksforgeeks.org/M1lUVBCMaT

#include<bits/stdc++.h>
using namespace std;

//Singly Linked List Template
struct Node{
    int data;
    struct Node* next;
};
struct Node* head;

//createNode
struct Node* createNode(int data){
    struct Node* tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

//printLL
void printLL(struct Node* head){
    if(head == NULL) return;
    while(head != NULL){
        cout<<head->data<<"\t";
        head = head->next;
    }
    cout<<"\n";
}

//insertAtBegin 
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

//insertAtEnd
void insertAtEnd(int data){
    struct Node* newNode = createNode(data);
    struct Node* travel = head; //traverse till head->next is NULL and then insert
    if(head == NULL){
        newNode->next = NULL;
        head = newNode;
        return;
    }
    while(travel->next != NULL) travel = travel->next;
    //as soon as list is empty
    travel->next = newNode;
    newNode->next = NULL;
}

//insertAfterNode
void insertAfterNode(int key, int data){
    struct Node* newNode = createNode(data);
    struct Node* travel = head;
    
    if(travel->next == NULL){
        travel->next = newNode;
        newNode->next = NULL;
        return;
    }
    
    while(travel->data != key){
        if(travel == NULL){
            cout<<"No node with key: "<<key<<" exists!\n";
            return;
        }
        travel = travel->next;
    }
    newNode->next = travel->next;
    travel->next = newNode;
}

void insertBeforeNode(int key, int data){
    struct Node* newNode = createNode(data);
    struct Node* travel = head;
    
    if(head == NULL){
        cout<<"Error!"<<'\n';
        return;
    }
    
    if(travel->next == NULL){
        travel->next = newNode;
        newNode->next = NULL;
        return;
    }
    
    while(travel->next->data != key){
        if(travel == NULL){
            cout<<"No node with key: "<<key<<" exists!\n";
            return;
        }
        travel = travel->next;
    }
    newNode->next = travel->next;
    travel->next = newNode;
}

int calculateLength(struct Node* head){
    if(head == NULL)return 0;
    int cnt = 0;
    while(head != NULL){
        cnt ++;
        head = head->next;
    }
    return cnt;
}

struct Node* deleteAtBegin(){
    if(head == NULL) return NULL;
    
    struct Node* temp = head;
    
    if(temp->next == NULL){
        free(temp);
        return NULL;
    }
    
    else{
        head = temp->next;
        free(temp);
        return head;
    }
}

void deleteAtEnd(){
    if(head == NULL) return;
    
    struct Node* traverse = head;
    
    while(traverse->next->next != NULL){
        traverse = traverse->next;
    }
    free(traverse->next);
    traverse->next = NULL;
}

void deleteNodeByKey(int key){
    if(head == NULL) return;
    
    struct Node* traverse = head;
    struct Node* temp;
    struct Node* prevTemp;
    
    if(traverse->data == key){
        head = traverse->next;
        free(traverse);
        return;
    }
    else{
        temp = traverse; prevTemp = traverse;
        
        while(temp->data != key){
            prevTemp = temp;
            temp = temp->next;
        }
        prevTemp->next = temp->next;
        free(temp);
        return;
    }
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
    
    insertBeforeNode(40, 30);
    printLL(head);
    
    cout<<"Length of LL: "<<calculateLength(head)<<"\n";
    
    head = deleteAtBegin();
    
    deleteAtEnd();
    
    printLL(head);
    cout<<"Length of LL: "<<calculateLength(head)<<"\n";
    
    deleteNodeByKey(40);
    printLL(head);
    
}
