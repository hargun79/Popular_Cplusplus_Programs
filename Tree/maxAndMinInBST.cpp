// To find maximum and minimum in a binary search tree.

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct node
{
 int data;
 node* left;
 node* right;
};

node* root = NULL;

// Function to insert an element in a binary search tree.
node* insert(node* root , int n)
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

// Function to find minimum in a binary search tree.
int findMin(node* root)
{
 if(root==NULL)
 {
  cout<<"Tree is empty \n";
  return NULL;
 }
 while(root->left!=NULL)
  root=root->left;
 return root->data; 
}

// Function to find maximum in a binary search tree.
int findMax(node* root)
{
 if(root==NULL)
 {
  cout<<"Tree is empty \n";
  return NULL;
 }
 while(root->right!=NULL)
  root=root->right;
 return root->data; 
}

int main ()
{
 int ch,num,s,min,max;
 do
 {
  system("cls");
  cout<<"1. Insert an element in the binary search tree \n";
  cout<<"2. Minimum element in the binary search tree \n";
  cout<<"3. Maximum element in the binary search tree \n";
  cout<<"4. Quit \n";
  cout<<"Enter your choice: \n";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"Enter the number to be inserted: \n";
	      cin>>num;
		  root=insert(root,num);
		  cout<<"The element has been inserted \n";
		  Sleep(2000);
		  break;
   case 2:min=findMin(root);
	      cout<<"The minimum element in the binary search tree is: "<<min<<'\n';  	
		  Sleep(2000);
		  break; 
   case 3:max=findMax(root);
	      cout<<"The maximum element in the binary search tree is: "<<max<<'\n';  	
	      Sleep(2000);
		  break;	
   case 4:exit(0);		 		 	 
  }
 }while(ch!=4);
 return 0; 
}
