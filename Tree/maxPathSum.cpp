// To find maximum path sum between two leaves of a binary tree

#include<bits/stdc++.h>
using namespace std;

struct Node
{
 int data;
 struct Node* left,*right;
};

// Function to allocate memory for a new node
Node* newNode(int data)
{
 Node* node=new Node;
 node->data=data;
 node->left=node->right=NULL;
 return (node);
}

// Function to find maximum of two integers
int max(int a,int b)
{ 
 return (a>=b)?a:b; 
}

// Function to find the maximum sum between any two leaves
int maxPathSumUtil(Node *root,int &res)
{
 if(root==NULL) 
  return 0;
 if(!root->left && !root->right) 
  return root->data;
 int ls=maxPathSumUtil(root->left,res);
 int rs=maxPathSumUtil(root->right,res);
 if(root->left && root->right)
 {
  res=max(res,ls+rs+root->data);
  return max(ls,rs)+root->data;
 }
 return (!root->left)?rs+root->data:ls+root->data;
}

// Function which returns sum of the maximum sum path between two leaves
int maxPathSum(Node *root)
{
 int res=INT_MIN;
 int val=maxPathSumUtil(root,res);
 if(res==INT_MIN)
  return val;
 return res;
}

int main()
{
 Node *root=newNode(-15);
 root->left=newNode(5);
 root->right=newNode(6);
 root->left->left=newNode(-8);
 root->left->right=newNode(1);
 root->left->left->left=newNode(2);
 root->left->left->right=newNode(6);
 root->right->left=newNode(3);
 root->right->right=newNode(9);
 root->right->right->right=newNode(0);
 root->right->right->right->left=newNode(4);
 root->right->right->right->right=newNode(-1);
 root->right->right->right->right->left=newNode(10);
 cout<<"Max pathSum of the given binary tree is "<<maxPathSum(root);
 return 0;
}
