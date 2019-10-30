//Implementation of static stack class containing multiple information.
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
struct medicine
{
 int mno;       // For medicine number.
 char mname[20];// For medicine name.
 int mq;        // For medicine quantity.
 char comp[20]; // For company name.
 int price;     // For medicine price.
};
const int max=100;
char msg[][20]={"Underflow error","Overflow error"};
class stack
{
 medicine m[max];
 int top;
 public:
	stack()
	{
	 top=-1;
	}
	void push(medicine md);
	medicine pop();
	void display();
};
void stack::push(medicine md)
{
 if(top==max-1)
  cout<<msg[1];
 else
  {
   top++;
   m[top]=md;
   cout<<"Element is pushed\n";
  }
}
medicine stack::pop()
{
 medicine md={-999};
 if(top==-1)
  cout<<msg[0];
 else
  md=m[top--];
 return(md);
}
void stack::display()
{
 if(top==-1)
  cout<<msg[0];
 else
  {
   cout<<"Stack is:\n";
   for(int i=top;i>=0;i--)
    {
     cout<<'\n'<<"The medicine number is  :"<<m[i].mno;
     cout<<'\n'<<"The medicine name is    :"<<m[i].mname;
     cout<<'\n'<<"The medicine quantity is:"<<m[i].mq;
     cout<<'\n'<<"The company name is     :"<<m[i].comp;
     cout<<'\n'<<"The price is            :"<<m[i].price;
    }
  }
}
void main()
{
 stack s;
 medicine m1;
 int ch;
 do
 {
  clrscr();
  cout<<"Stack operation menu:\n";
  cout<<"1. PUSH\n";
  cout<<"2. POP\n";
  cout<<"3. Display\n";
  cout<<"4. Quit\n";
  cout<<"Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:cout<<"Enter information of the medicine to be pushed in stack\n";
	  cout<<"Enter medicine number\n";
	  cin>>m1.mno;
	  cout<<"Enter medicine name\n";
	  gets(m1.mname);
	  cout<<"Enter medicine quantity\n";
	  cin>>m1.mq;
	  cout<<"Enter company name\n";
	  gets(m1.comp);
	  cout<<"Enter the price per piece\n";
	  cin>>m1.price;
	  s.push(m1);
	  break;
   case 2:m1=s.pop();
	  if(m1.mno!=-999)
	   {
	    cout<<"Element is popped\n";
	   }
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