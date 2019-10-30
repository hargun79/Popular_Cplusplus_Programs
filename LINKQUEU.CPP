// Implementation of linked queue class containing multiple information.
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
struct node
{
 int vno;        // For voter number.
 char vname[20]; // For voter name.
 int vage;       // For voter age.
 node *next;
};
class queue
{
 node *front,*rear;
 public:
	queue()
	{
	 front=NULL;
	 rear=NULL;
	}
	void ADD(int vn,char vm[],int va)
	{
	 node *temp=new node;
	 temp->vno=vn;
	 strcpy(temp->vname,vm);
	 temp->vage=va;
	 temp->next=NULL;
	 if(rear==NULL)
	 {
	  front=temp;
	  rear=temp;
	 }
	 else
	 {
	  rear->next=temp;
	  rear=temp;
	 }
	}
	void DELETE()
	{
	 node *temp;
	 if(front==NULL)
	  cout<<"Queue is empty\n";
	 else
	 {
	  temp=front;
	  front=front->next;
	  temp->next=NULL;
	  cout<<"The deleted information is:\n";
	  cout<<temp->vno<<'\t'<<temp->vname<<'\t'<<temp->vage<<'\n';
	  delete(temp);
	  if(front==NULL)
	   rear=NULL;
	 }
	}
	void display();
};
void queue::display()
{
 if(front==NULL)
  cout<<"Queue is empty\n";
 else
 {
  cout<<"Queue is:\n";
  for(node *temp=front;temp!=NULL;temp=temp->next)
   cout<<temp->vno<<'\t'<<temp->vname<<'\t'<<temp->vage<<'\n';
 }
}
void main()
{
 queue q;
 int ch,vn,vag;
 char vnm[20];
 do
 {
  clrscr();
  cout<<"Queue implementation menu is:\n";
  cout<<"1. ADD\n";
  cout<<"2. DELETE\n";
  cout<<"3. Display\n";
  cout<<"4. Quit\n";
  cout<<"Enter your chioce\n";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"Enter the data to be added\n";
	  cout<<"Enter the voter number\n";
	  cin>>vn;
	  cout<<"Enter the voter name\n";
	  gets(vnm);
	  cout<<"Enter the voter age\n";
	  cin>>vag;
	  q.ADD(vn,vnm,vag);
	  q.display();
	  break;
   case 2:q.DELETE();
	  q.display();
	  break;
   case 3:q.display();
	  break;
   case 4:exit(0);
   default:cout<<"Wrong choice\n";
  }
  getch();
 }
 while(ch!=4);
}