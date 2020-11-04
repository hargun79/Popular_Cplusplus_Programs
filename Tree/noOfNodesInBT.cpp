// To find number of nodes in a binary tree.

#include<bits/stdc++.h>
using namespace std;

struct node
{
  int data;
  struct node* left;
  struct node* right;
};

struct node *root = NULL;

// Fuction to create a binary tree.
struct node* create()
{
  struct node *temp;
  int x;
  scanf("%d",&x);
  if(x==-1)
   return NULL; 
  temp=new node();
  temp->data=x;
  cout<<"Enter left child of "<<x<<"(-1 for no data): \n";
  temp->left=create();
  cout<<"Enter right child of "<<x<<"(-1 for no data): \n";
  temp->right=create();
  return temp;
}

// Function to count the number of nodes.
int countNodes(node* root)
{
 if(root==NULL)
  return 0;
 int count=1; 
 if(root->left!=NULL)
  count+=countNodes(root->left);
 if(root->right!=NULL)
  count+=countNodes(root->right);
 return count;
}

int main()
{
 struct node* root=create();
 int count=countNodes(root);
 cout<<count;
 return 0;
}
