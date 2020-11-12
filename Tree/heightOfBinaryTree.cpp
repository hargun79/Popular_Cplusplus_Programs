// To find height of a binary tree.

#include<bits/stdc++.h>
using namespace std;

struct node
{
 int data;
 node* left;
 node* right;
};

node* root = NULL;

// Fuction to create a binary tree.
node* create()
{
 node* temp;
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
  return -1; 
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

int main()
{
 int ch,h;
 cout<<"Enter the root node of the binary tree (-1 for no data): \n";
 root=create();
 h=height(root);
 cout<<"The height of the binary tree is: "<<h;
 return 0;
}
