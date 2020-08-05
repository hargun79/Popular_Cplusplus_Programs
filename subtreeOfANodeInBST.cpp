// To find subtree of a node in BST

#include<bits/stdc++.h>
using namespace std;

vector<long long int> v;

struct node
{
 long long int data;
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

void preorder(struct node* root)
{
 if(root)
 {
  v.push_back(root->data); 
  preorder(root->left);    
  preorder(root->right);   
 }
}

node * find(node *ptr, long long int key)
{
 if(ptr)
 {
  if(ptr->data==key)
   return ptr;
  else 
   if(ptr->data>key)
    return find(ptr->left, key);
  else
   return find(ptr->right, key);   
 }
 else
  return NULL;
}

int main()
{
 root=insert(root,1);
 long long int n,a,b;
 cin>>n;
 for(long long int i=0;i<n;i++)
 {
  cin>>a;
  if(i==0)
   root=insert(root,a);
  else
   insert(root,a); 	
 } 
 cin>>b;
 node* ptr=find(root,b);
 preorder(ptr);
 for(long long int i=0;i<v.size();i++)
  cout<<v[i]<<'\n';
 return 0;
}
