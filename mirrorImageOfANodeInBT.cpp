// To find the mirror image of a node in binary tree

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

// Recursive function to find mirror of node 
int findMirrorRec(int target,Node* left,Node* right) 
{ 
 if(left==NULL || right==NULL) 
  return 0; 
 if(left->key==target) 
  return right->key; 
 if(right->key==target) 
  return left->key; 
 int mirror_val=findMirrorRec(target,left->left,right->right); 
 if(mirror_val) 
  return mirror_val; 
 findMirrorRec(target,left->right,right->left); 
} 

// Function for mirror search 
int findMirror(Node* root,int target) 
{ 
 if(root==NULL) 
  return 0; 
 if(root->key==target) 
  return target; 
 return findMirrorRec(target,root->left,root->right); 
} 

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
 
int main() 
{ 
 Node* root=newNode(1); 
 int x,y,a,b;
 cin>>x>>y;
 char c;
 for(int i=0;i<x-1;i++)
 {
  cin>>a>>b>>c;
  if(c=='L')
   ifNodeExists(root,a)->left=newNode(b);
  else
   ifNodeExists(root,a)->right=newNode(b);   
 }
 int target;
 for(int i=0;i<y;i++)
 {
  cin>>target; 
  int mirror=findMirror(root,target); 
  if(mirror) 
   cout<<mirror<<'\n'; 
  else
   cout<<-1<<'\n'; 
 }
 return 0; 
} 
