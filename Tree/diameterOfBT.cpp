// To find diameter of a binary tree

#include<bits/stdc++.h>
using namespace std;

int m;

struct node
{
 int val,lh,rh;
 struct node *left,*right;
};

// Allocates new nodes.
node *getNode(int val)
{
 node *ret = (node*)calloc(1, sizeof(node));
 ret->val=val;
 return ret;
}  

// Function to calculate the diameter
int diameter(node *ptr)
{
 if(ptr)
 {
  ptr->lh=diameter(ptr->left);
  ptr->rh=diameter(ptr->right);
  if(ptr->lh+ptr->rh+1>m)
   m=ptr->lh+ptr->rh+1;
  return (ptr->lh>ptr->rh?ptr->lh:ptr->rh)+1;
 }
 else
  return 0;
}

int main()
{
 m=INT_MIN;
 node *root=NULL,*ptr;
 int n,x,i;
 cin>>n>>x;
 root=getNode(x);
 string str;
 while(--n)
 {
  cin>>str;
  i=0;
  ptr=root;
  while(str[i] && ptr)
  {
   if(str[i]=='L')
   {
    if(ptr->left==NULL)
     ptr->left=getNode(0);
    ptr=ptr->left;
   }
   else
   {
    if(ptr->right==NULL)
     ptr->right=getNode(0);
    ptr=ptr->right;
   }
   i++;
  }
  cin>>x;
  ptr->val=x;
 }
 diameter(root);
 cout<<m;
 return 0;
}
