// To find inorder successor in a binary search tree.

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct node
{
 int data;
 node* left;
 node* right;
};

node* root=NULL;

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

//Function to find some data in the tree
node* Find(node*root,int data) 
{
 if(root==NULL)
  return NULL;
 else 
  if(root->data==data) 
   return root;
 else 
  if(root->data<data) 
   return Find(root->right,data);
 else 
  return Find(root->left,data);
}

//Function to find Node with minimum value in a BST
node* FindMin(node* root)
{
 if(root==NULL) 
  return NULL;
 while(root->left!=NULL)
  root=root->left;
 return root;
}

//Function to find Inorder Successor in a BST
node* Getsuccessor(node* root,int data) 
{
 node* current=Find(root,data);
 if(current==NULL)
  return NULL;
 if(current->right!=NULL) 
  return FindMin(current->right); 
 else 
 { 
  node* successor=NULL;
  node* ancestor=root;
  while(ancestor!=current) 
  {
   if(current->data<ancestor->data) 
   {
    successor=ancestor; 
	ancestor=ancestor->left;
   }
   else
	ancestor=ancestor->right;
  }
  return successor;
 }
}

int main()
{
 int ch,num,s,min,max;
 do
 {
  system("cls");
  cout<<"1. Insert an element in the binary search tree \n";
  cout<<"2. Inorder successor of an element in binary search tree \n";
  cout<<"3. Quit \n";
  cout<<"Enter your choice: \n";
  cin>>ch;
  switch(ch)
  {
   case 1:
   {
	cout<<"Enter the number to be inserted: \n";
	cin>>num;
	root=insert(root,num);
	cout<<"The element has been inserted \n";
	Sleep(2000);
	break;
   }
   case 2:
   {
	cout<<"Enter the number whose inorder successor is to be found: \n";
	cin>>num;
	node* successor=Getsuccessor(root,num);
	if(successor!=NULL)
	 cout<<"The inorder successor of the entered number is: "<<successor->data<<"\n";
	else
	 cout<<"Entered number is not in binary search tree \n"; 
	Sleep(2000);
	break;
   } 	
   case 3:exit(0);		 		 	 
  }
 }while(ch!=3);
 return 0; 
}
