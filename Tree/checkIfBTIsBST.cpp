// To check if given binary tree is binary search tree or not.

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

int isBSTUtil(node* node,int min,int max)  
{  
 if(node==NULL)  
  return 1; 
 if(node->data<min || node->data>max)  
  return 0;  
 return isBSTUtil(node->left,min,node->data-1) && isBSTUtil(node->right,node->data+1,max);  
}  

// Function to check if given binary tree is binary search tree or not.
int isBST(node* node)  
{  
 return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  

int main()
{
 int ch,v;
 cout<<"Enter the root node of the binary tree (-1 for no data): \n";
 root=create();
 v=isBST(root);
 if(v==1)
  cout<<"The given binary tree is binary search tree \n";
 else
  cout<<"The given binary tree is not binary search tree \n";
 return 0;
}
