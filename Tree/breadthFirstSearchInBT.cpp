// Breadth first or level order traversal of a binary tree.

#include<bits/stdc++.h>
using namespace std;

struct node
{
 int data;
 struct node* left;
 struct node* right;
};

node *root=NULL;

// Fuction to create a binary tree.
node* create()
{
 node *temp;
 int x;
 cin>>x;
 if(x==-1)
  return NULL; 
 temp=new node;
 temp->data=x;
 cout<<"Enter left child of "<<x<<" (-1 for no data): \n";
 temp->left=create();
 cout<<"Enter right child of "<<x<<" (-1 for no data): \n";
 temp->right=create();
 return temp;
}

// Function to find the height of the tree.
int height(node* node) 
{ 
 if(node==NULL) 
  return 0; 
 else
 { 
  int lheight=height(node->left); 
  int rheight=height(node->right); 
  if(lheight>rheight) 
   return(lheight+1); 
  else
   return(rheight+1); 
 } 
} 

// Function to print nodes at a given level.
void givenLevel(node* root, int level) 
{ 
 if(root==NULL) 
  return; 
 if(level==1) 
  cout<<root->data; 
 else
  if(level>1) 
  { 
   givenLevel(root->left, level-1); 
   givenLevel(root->right, level-1); 
  } 
} 

// Function to print level order traversal of a tree.
void levelOrder(node* root) 
{ 
 int h=height(root); 
 int i; 
 for(i=1;i<=h;i++) 
  givenLevel(root,i); 
} 
  
int main()
{
 int ch;
 cout<<"Enter the root node of the binary tree (-1 for no data): \n";
 root=create();
 cout<<"The level order traversal of the binary tree is: \n";
 levelOrder(root);
 return 0;
}
