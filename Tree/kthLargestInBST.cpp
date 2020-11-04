// To find kth largest element in a BST.

#include<bits/stdc++.h>
using namespace std;

int c=0;

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
 struct node* temp=new node();
 temp->data=n;
 temp->left=temp->right=NULL;
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

// Function to find the kth largest element.
void kthLargest(node *root, int k, int &c) 
{ 
 if(root==NULL || c>=k) 
  return; 
 kthLargest(root->right, k, c); 
 c++; 
 if(c==k) 
 { 
  cout<<"K'th largest element is: "<<root->data; 
  return; 
 } 
 kthLargest(root->left, k, c); 
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
 kthLargest(root,k,c);
 return 0;
}
