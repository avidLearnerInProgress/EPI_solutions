//circular singly linked list  insert and delete api - reusable functions
//https://ide.geeksforgeeks.org/vuM1aeRF6T

#include<bits/stdc++.h>
using namespace std;

//Circular Singly Linked List Template
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
    struct Node* temp = head;
    while(temp->next != head){
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<temp->data;
    cout<<"\n";
}

//insertAtBegin 
void insertAtBegin(int data){
    
    struct Node* newNode = createNode(data);
    struct Node* travel = head;
    
    if(travel == NULL){
        head = newNode;
        newNode->next = head;
        return;
    }
    else{
        while(travel->next != head) 
            travel = travel->next;
        
        travel->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}


//insertByKey
void insertAfterNode(int key, int data){
    struct Node* newNode = createNode(data);
    struct Node* travel = head;
    
    while(travel->data != key)
        travel = travel->next;
    
    newNode->next = travel->next;
    travel->next = newNode;
    return;
}


void deleteAtBegin(){
    if(head == NULL) return;
    
    struct Node* temp = head;
    struct Node* nextTemp = head->next;
	if(temp->next==head)
	{
		head=NULL;
		free(temp);
		return;	
	}

    
    while(nextTemp != head){
        temp = nextTemp;
        nextTemp = nextTemp->next;
    }
    
    temp->next = nextTemp->next;
    head = nextTemp->next;
    free(nextTemp);
    return;
}


void deleteNodeByKey(int key){
    if(head == NULL) return;
    
    struct Node* traverse = head;
    struct Node* temp;
    struct Node* prevTemp;
    
    temp = traverse; prevTemp = traverse;
        
    while(temp->data != key){
        prevTemp = temp;
        temp = temp->next;
    }
    
    if(temp->next==head)
	{
		prevTemp->next=head;
		free(temp);
		return;
    }
    
    else{
        prevTemp->next = temp->next;
        free(temp);
        return;
    }
}


int main(){
    
    head = NULL;
    int n; cin>>n;
    
    for(int i=0; i<n; i++){
        int x; cin>>x;
        insertAtBegin(x);    
    }
    printLL(head);

    insertAfterNode(40, 50);
    printLL(head);
    
    deleteAtBegin();
    printLL(head);
    
    deleteNodeByKey(40);
    printLL(head);
    
}
