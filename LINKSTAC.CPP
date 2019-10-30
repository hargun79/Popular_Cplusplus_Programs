// Implementation of linked stack class containing multiple information.
#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
struct node
{
 int rno;        // For register number.
 char rname[20]; // For register's manufacturer number.
 float rprice;   // For register price.
 node *next;
};
class stack
{
 node *top;
 public:
	stack()
	{
	 top=NULL;
	}
	void PUSH();
	void POP();
	void display();
};
void stack::PUSH()
{
 node *temp=new node;
 cout<<"Enter the information:\n";
 cout<<"Enter the register number\n";
 cin>>temp->rno;
 cout<<"Enter the register name\n";
 gets(temp->rname);
 cout<<"Enter the register price\n";
 cin>>temp->rprice;
 temp->next=NULL;
 if(top==NULL)
  top=temp;
 else
  {
   temp->next=top;
   top=temp;
  }
}
void stack::POP()
{
 node *temp;
 if(top==NULL)
  cout<<"Stack is empty\n";
 else
  {
   temp=top;
   top=top->next;
   temp->next=NULL;
   cout<<"The popped information is:\n";
   cout<<temp->rno<<'\t'<<temp->rname<<'\t'<<temp->rprice;
   delete(temp);
  }
}
void stack::display()
{
 if(top==NULL)
  cout<<"\nStack is empty\n";
 else
  {
   cout<<"\nStack is:\n";
   for(node *temp=top;temp!=NULL;temp=temp->next)
    {
     cout<<"\nThe information is:\n";
     cout<<temp->rno<<'\t'<<temp->rname<<'\t'<<temp->rprice;
    }
  }
}
void main()
{
 stack s;
 int ch;
 do
 {
  clrscr();
  cout<<"Linked stack operation menu:\n";
  cout<<"1. PUSH\n";
  cout<<"2. POP\n";
  cout<<"3. Display\n";
  cout<<"4. Quit\n";
  cout<<"Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:s.PUSH();
	  s.display();
	  break;
   case 2:s.POP();
	  s.display();
	  break;
   case 3:s.display();
	  break;
   case 4:exit(0);
   default:cout<<"Wrong choice\n";
  }
  getch();
 }
 while(ch!=4);
}
