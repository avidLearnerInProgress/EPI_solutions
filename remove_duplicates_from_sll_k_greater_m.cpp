//Remove kth last node from LinkedList
//https://ide.geeksforgeeks.org/6E3r0ocog8

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

//if k > m remove all nodes having key k
void removeDuplicateNodes(Node *head, int k, int m){
    Node *first = head;
    int cnt = 0;
    while(first){
        if(first->data == k)
            cnt++;
        first = first->next;
    }
    cout<<"cnt: "<<cnt<<"\n";
    if(cnt>m){
        first = head;
        while(first){
            Node* second = first->next;
                while(second && second->data == k){
                    second = second->next;
            }
            first->next = second;
            first = second;
        }
        printLL(head);
    }
}

int main() 
{ 

	Node* head1 = newNode(1); 
	head1->next = newNode(2); 
	head1->next->next = newNode(3); 
	head1->next->next->next = newNode(4);
	head1->next->next->next->next = newNode(4); 
	head1->next->next->next->next->next = newNode(4); 
	head1->next->next->next->next->next->next = newNode(5);
    printLL(head1);
    cout<<"\n\n";
    int m = 2, k = 4; //occurences, key
    removeDuplicateNodes(head1, k, m);
    
    Node* head2 = newNode(1); 
	head2->next = newNode(2); 
	head2->next->next = newNode(3); 
	head2->next->next->next = newNode(4);
	head2->next->next->next->next = newNode(4); 
	head2->next->next->next->next->next = newNode(5);
	cout<<"\n\n";
    removeDuplicateNodes(head2, k, m);
    return 0; 
} 
