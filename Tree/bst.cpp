// Searching, insertion and deletion in a binary search tree.

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct node
{
 int data;
 node* left;
 node* right;
};

bool c=0;
node* root=NULL;

// Function to search an element in a binary search tree.
bool search(node* root,int n)
{
 if(root==NULL) 
  return 0;
 else 
  if(root->data==n) 
   return 1;
 else 
  if(n<root->data) 
   return search(root->left,n);
 else 
  if(n>root->data)
   return search(root->right,n);
}

// Function to insert an element in a binary search tree.
node* insert(node* root,int n)
{
 node* temp=new node;
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

//  Function to find minimum.
node* minimum(node* root)
{
 while(root->left!=NULL)
  root=root->left;
 return root;
}

// Function to delete an element in a binary search tree.
node* del(node* root,int data)
{
 c=search(root, data);
 if(root==NULL)
  return root;
 if(data<root->data)
  root->left=del(root->left,data);
 else 
  if(data>root->data)
   root->right=del(root->right,data);
 else 
 { 
  if(root->left==NULL && root->right==NULL)
  {
   free(root);
   root=NULL;
   return root;
  }
  else
   if(root->left==NULL)
   {
    node* temp=root;
    root=root->right;
    free(temp);
    return NULL;
   }
  else 
   if(root->right==NULL)
   {
    node* temp=root;
    root=root->left;
    free(temp);
    return NULL;
   }
  else
  {
   node* temp=minimum(root->right);
   root->data=temp->data;
   root->right=del(root->right,temp->data);
  }
 }
 return root;
}

// Function for inorder traversal in a binary tree.
void inOrder(node* temp)
{
 if(temp==NULL)
  return; 	
 inOrder(temp->left);
 cout<<temp->data<<" ";
 inOrder(temp->right);
}

int main ()
{
 int ch,num,s;
 do
 {
  system("cls");
  cout<<"Binary search tree operations menu: \n";
  cout<<"1. Insert an element in a binary search tree \n";
  cout<<"2. Delete an element in a binary search tree \n";
  cout<<"3. Search an element in a binary search tree \n";
  cout<<"4. Display a binary search tree \n";
  cout<<"5. Quit \n";
  cout<<"Enter your choice: \n";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"Enter the number to be inserted: \n";
	      cin>>num;
		  root=insert(root, num);
		  cout<<"The binary search tree after insertion is: \n";
		  inOrder(root);
		  Sleep(2000);
		  break;
   case 2:cout<<"Enter the number to be deleted: \n";	
	      cin>>num;
		  del(root, num);
		  if(c)
           cout<<"The element was deleted \n";
		  else
		   cout<<"Element not found \n";  	
		  Sleep(2000);
		  break; 
   case 3:cout<<"Enter the element to be searched: \n";
  	      cin>>num;
  	      s=search(root,num);
  	      if(s==1)
  	       cout<<"Search was successful \n";
  	      else
		   cout<<"Search was unsuccessful \n";
		  Sleep(2000);
		  break;	
   case 4:cout<<"The binary search tree is: \n";
	      inOrder(root);
	      Sleep(2000);
		  break;
   case 5:exit(0);		 		 	 
  }
 }while(ch!=5);
 return 0; 
}
