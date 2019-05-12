//compute binary tree in order of increasing depth --> print in reverse order
//https://ide.geeksforgeeks.org/bRiTPdCuJz

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};


Node *newNode(int data){
    Node *root = new Node();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void levelOrder(Node* root)
{
  if(!root) return;
  queue<Node*> q;
  stack<int> s;
  q.push(root);
  q.push(NULL);
  
  while(q.size()!=1) {
      root = q.front();
      q.pop();
      if(root!=NULL)
      	s.push(root->data);
          
      else if(root==NULL) {
          q.push(NULL);
          s.push(INT_MAX);
          continue;
      }
      
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
  }

	while(!s.empty()){
		if(s.top() == INT_MAX) cout<<"\n";
		else cout<<s.top()<<" ";
		s.pop();	
	}
}


int main() 
{ 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->right = newNode(6); 
    levelOrder(root); 
    return 0; 
} 
