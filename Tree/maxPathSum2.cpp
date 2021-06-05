// To find maximum path sum in Binary Tree

#include<bits/stdc++.h>
using namespace std;

struct Node
{
 int data;
 struct Node* left,*right;
};

// Function to allocate a new node
Node* newNode(int data)
{
 Node* newNode=new Node;
 newNode->data=data;
 newNode->left=newNode->right=NULL;
 return (newNode);
}

// Recursive function to find the maximum path sun
int findMaxUtil(Node* root,int &res)
{
 if(root==NULL)
  return 0;
 int l=findMaxUtil(root->left,res);
 int r=findMaxUtil(root->right,res);
 int max_single=max(max(l,r)+root->data,root->data);
 int max_top=max(max_single,l+r+root->data);
 res=max(res,max_top); 
 return max_single;
}

// Function to find the maximum path sum
int findMaxSum(Node *root)
{
 int res=INT_MIN;
 findMaxUtil(root,res);
 return res;
}

int main()
{
 Node *root=newNode(10);
 root->left=newNode(2);
 root->right=newNode(10);
 root->left->left=newNode(20);
 root->left->right=newNode(1);
 root->right->right=newNode(-25);
 root->right->right->left=newNode(3);
 root->right->right->right=newNode(4);
 cout<<"Max path sum is "<<findMaxSum(root);
 return 0;
}
