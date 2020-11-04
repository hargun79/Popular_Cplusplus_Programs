// To find the index of the level of the tree having the maximum sum

#include<bits/stdc++.h>
using namespace std;

struct Node 
{ 
 int val; 
 struct Node* left,*right; 
};

// Function to initialize a new node 
Node* newNode(int key) 
{ 
 Node *n=new Node; 
 n->val=key; 
 n->left=NULL; 
 n->right=NULL; 
 return n;
}

// Function to check if node exists or not
Node* ifNodeExists(Node* node, int key) 
{ 
 if(node==NULL) 
  return node; 
 if(node->val==key) 
  return node; 
 Node* res1=ifNodeExists(node->left,key); 
 if(res1) 
  return res1;
 Node* res2=ifNodeExists(node->right,key); 
 return res2; 
}

// Function to get the height of the tree
int getHeight(Node* root)
{
 if(root==NULL)
  return 0;
 int l=getHeight(root->left);
 int r=getHeight(root->right);
 if(l>r)
  return l+1;
 else 
  return r+1;
}
    
// Function to perform level order traversal
void levelOrderTraversal(Node* root,int level,vector<int>& v)
{
 if(root==NULL)
  return;
 v[level]+=root->val;
 levelOrderTraversal(root->right,level+1,v);
 levelOrderTraversal(root->left,level+1,v);
}

// Function to find the maximum level sum
int maxLevelSum(Node* root) 
{
 int height=getHeight(root);
 vector<int> v(height);
 levelOrderTraversal(root,0,v);
 int index=0;
 for(int i=0;i<v.size();i++)
  if(v[i]>v[index])
   index=i;
 return index+1;
}

int main()
{
 Node* root=newNode(1); 
 int x,a,b;
 cin>>x;
 char c;
 for(int i=0;i<x-1;i++)
 {
  cin>>a>>b>>c;
  if(c=='L')
   ifNodeExists(root,a)->left=newNode(b);
  else
   ifNodeExists(root,a)->right=newNode(b);   
 }
 cout<<maxLevelSum(root);
 return 0;
}
