// To find ancestors of a node

#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
 int key; 
 struct Node* left,*right; 
}; 

// Function to initialize a new node 
Node* newNode(int key) 
{ 
 Node *n=new Node; 
 n->key=key; 
 n->left=NULL; 
 n->right=NULL; 
 return n;
} 

// Function to find the parent
Node* ifNodeExists(Node* node, int key) 
{ 
 if(node==NULL) 
  return node; 
 if(node->key==key) 
  return node; 
 Node* res1=ifNodeExists(node->left,key); 
 if(res1) 
  return res1;
 Node* res2=ifNodeExists(node->right,key); 
 return res2; 
}

// Function to print the ancestors
bool ancestors(Node *node, int target) 
{ 
 if(node==NULL) 
  return false; 
 if(node->key==target) 
  return true; 
 if(ancestors(node->left,target) || ancestors(node->right,target)) 
 { 
  cout<<node->key<<" ";
  return true; 
 } 
 return false; 
}
 
int main() 
{ 
 Node *root=newNode(1); 
 int x,a;
 cin>>x;
 for(int i=0;i<x-1;i++)
 {
  cin>>a;
  Node *ptr=ifNodeExists(root,a);
  if(ptr->left==NULL)
   ptr->left=newNode(i+2);
  else
   ptr->right=newNode(i+2);   
 }
 for(int i=1;i<=x;i++)
 {
  cout<<i<<": ";
  ancestors(root,i);
  cout<<'\n'; 
 }
 return 0; 
} 
