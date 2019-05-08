//compute binary tree in order of increasing depth
//https://ide.geeksforgeeks.org/JGmq5jDWP0

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
  q.push(root);
  q.push(NULL);
  while(q.size()!=1) {
      root = q.front();
      q.pop();
      if(root!=NULL)
          cout<<root->data<<" ";
      else if(root==NULL) {
          cout<<"$"<<" ";
          q.push(NULL);
          continue;
      }
      
        if(root->left)
            q.push(root->left);
        if(root->right)
            q.push(root->right);
  }
    cout<<"$"<<" ";
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
