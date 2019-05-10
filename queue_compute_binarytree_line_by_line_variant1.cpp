//https://ide.geeksforgeeks.org/cIUegw22Bn

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node *createNode(int data){
	Node *root = new Node();
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root; 
}

int height(Node *root){
    if(!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

void printLevel(Node *root, int i, bool flag){
    if(!root) return;
    if(i == 1){ //root
        cout<<root->data<<" ";
    }
    else if(i > 1){
        if(flag){
            printLevel(root->left, i - 1, flag);
            printLevel(root->right, i - 1, flag);
        }
        else{
            printLevel(root->right, i - 1, flag);
            printLevel(root->left, i - 1, flag);
        }
    }
}

void printSpiral(Node *root)
{
     //Your code here
     if(!root) return;
     int h = height(root); 
     bool flag = 0;
     
     for(int i=1; i<=h; i++){
         printLevel(root, i, flag);
         flag = !flag;
     }
     
}

void printSpiralv1(Node *root){
	if(!root) return;
	stack<Node *> s1; //right to left;
	stack<Node *> s2; //left to right;
	
	s1.push(root);
	
	while(!s1.empty() || !s2.empty()){
		
		while(!s1.empty()){
			Node *curr = s1.top();
			cout<<curr->data<<" ";
			s1.pop();
			if(curr->right)
			    s2.push(curr->right);
			if(curr->left)
			    s2.push(curr->left);
		}
		
		while(!s2.empty()){
			Node *curr = s2.top();
			cout<<curr->data<<" ";
			s2.pop();
			if(curr->left)
				s1.push(curr->left);
			if(curr->right)
			    s1.push(curr->right);
		}
	}
}

void printSpiralv2(Node *root){
    if(!root) return;
    
    stack<int> s;
    queue<Node *> q;
    
    bool var = true;
    q.push(root);
    
    while(!q.empty()){
        int size = q.size();
        while(size>0){
            //int x = y.size()
            Node *curr = q.front();
            q.pop();
            if(var) //if right to left 
                s.push(curr->data);
            else //when normal left to right
                cout<<curr->data<<" ";
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            size--;
        }
    
        if(var){
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        var = !var;
    }
    
    
    
}

int main(){
	
	Node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	printSpiral(root);
	cout<<"\n";
	printSpiralv1(root);
	cout<<"\n";
	printSpiralv2(root);
}
