// To find kth smallest element using Morris traversal.

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

// Function to find the kth smallest element.
int KSmallestUsingMorris(node *root, int k) 
{ 
 int count=0; 
 int ksmall=INT_MIN;  
 node *curr=root; 
 while(curr!=NULL) 
 { 
  if(curr->left==NULL) 
  { 
   count++; 
   if(count==k) 
    ksmall=curr->data; 
   curr=curr->right; 
  } 
  else
  { 
   node *pre=curr->left; 
   while(pre->right!=NULL && pre->right!=curr) 
    pre=pre->right; 
   if(pre->right==NULL) 
   { 
    pre->right = curr; 
    curr=curr->left; 
   } 
   else
   { 
    pre->right=NULL; 
    count++; 
    if(count==k) 
     ksmall=curr->data; 
    curr=curr->right; 
   } 
  } 
 } 
 return ksmall;  
}

int main()
{
 root=insert(root,1); 
 insert(root,2); 
 insert(root,3); 
 insert(root,4); 
 insert(root,5); 
 insert(root,6);
 int k=3;
 int no=KSmallestUsingMorris(root,k);
 cout<<no;
 return 0;
}

