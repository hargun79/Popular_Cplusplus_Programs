// To find diameter of a binary tree

#include <bits/stdc++.h>
using namespace std;
 
struct node 
{
 int data;
 node *left,*right;
};
 
// Function to create a new node of tree and returns pointer
node* newNode(int data)
{
 node* n=new node;
 n->data=data;
 n->left=NULL;
 n->right=NULL;
 return n;
}
 
// Function to Compute height of a tree.
int height(node* node)
{
 if(node==NULL)
  return 0;
 return 1+max(height(node->left),height(node->right));
}
 
// Function to get diameter of a binary tree
int diameter(node* tree)
{
 if(tree==NULL)
  return 0;
 int lheight=height(tree->left);
 int rheight=height(tree->right);
 int ldiameter=diameter(tree->left);
 int rdiameter=diameter(tree->right);
 return max(lheight+rheight+1,max(ldiameter,rdiameter));
}
 
int main()
{
 node* root=newNode(1);
 root->left=newNode(2);
 root->right=newNode(3);
 root->left->left=newNode(4);
 root->left->right=newNode(5);
 cout<<"Diameter of the given binary tree is "<<diameter(root);
 return 0;
}
