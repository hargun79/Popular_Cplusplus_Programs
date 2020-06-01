// To find kth smallest element in a BST.

#include<bits/stdc++.h>
using namespace std;

struct node
{
 int data;
 struct node* left;
 struct node* right;
};

struct node* root=NULL;

// Function to insert an element in a binary search tree.
struct node* insert(struct node* root , int n)
{
  struct node* temp = new node();
  temp->data = n;
  temp->left = temp->right = NULL;
  if(root==NULL)
   root=temp;
  else 
   if(n<root->data)
    root->left=insert(root->left,n);
  else
   if(n>root->data)
    root->right=insert(root->right,n); 
  return root;
}

// Function to store the the nodes.
void storeBSTNodes(struct node* root,vector<struct node*> &nodes) 
{ 
 if(root==NULL) 
  return; 
 storeBSTNodes(root->left,nodes); 
 nodes.push_back(root); 
 storeBSTNodes(root->right,nodes); 
} 
  
// Function to find the kth smallest element
int findKthMinimumElement(struct node* root,int k) 
{ 
 vector<struct node*> nodes; 
 storeBSTNodes(root,nodes); 
 return nodes[k-1]->data;
}

int main()
{
 root=insert(root,1); 
 insert(root,2); 
 insert(root,3); 
 insert(root,4); 
 insert(root,5); 
 insert(root,6);
 int k=2;
 int no=findKthMinimumElement(root,k);
 cout<<no;
 return 0;
}
