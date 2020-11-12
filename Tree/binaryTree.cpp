#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

struct node
{
 int data;
 struct node* left;
 struct node* right;
};

node* root=NULL;

// Fuction to create a binary tree.
node* create()
{
 node* temp;
 int x;
 cin>>x;
 if(x==-1)
  return NULL; 
 temp=new node;
 temp->data=x;
 cout<<"Enter left child of "<<x<<" (-1 for no data): \n";
 temp->left=create();
 cout<<"Enter right child of "<<x<<" (-1 for no data): \n";
 temp->right=create();
 return temp;
}

// Function for post order traversing in a binary tree.
void postOrder(node* temp) 
{ 
 if(temp==NULL) 
  return; 
 postOrder(temp->left); 
 postOrder(temp->right); 
 cout<<temp->data<<" "; 
} 
  
// Function for in order traversing in a binary tree.
void inOrder(node* temp) 
{ 
 if(temp==NULL) 
  return; 
 inOrder(temp->left); 
 cout<<temp->data<<" ";   
 inOrder(temp->right); 
} 
  
// Function for pre order traversing in a binary tree.
void preOrder(node* temp) 
{ 
 if(temp==NULL) 
  return; 
 cout<<temp->data<<" ";   
 preOrder(temp->left);   
 preOrder(temp->right); 
}  

int main()
{
 int ch;
 cout<<"Enter the root node of the binary tree (-1 for no data): \n";
 root=create();
 do
 {
  system("cls");
  cout<<"Binary tree operations menu: \n";
  cout<<"1. Preorder traversal of a binary tree \n";  	
  cout<<"2. Inorder traversal of a binary tree \n"; 
  cout<<"3. Postorder traversal of a binary tree \n"; 
  cout<<"4. Quit \n";
  cout<<"Enter your choice: \n";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"Preorder traversal is: \n";
	      preOrder(root);
	      Sleep(2000);
	      break;
   case 2:cout<<"Inorder traversal is: \n";
          inOrder(root);
	      Sleep(2000);
		  break;
   case 3:cout<<"Postorder traversal is: \n";
	      postOrder(root);
	      Sleep(2000);
		  break;
   case 4:exit(0); 		 		         
  }
 }while(ch!=4);
 return 0;	
}
