// Implementation of a static queue class containing single information.
#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 100
class queue
{
 float a[max];
 int front,rear;
 public:
	queue() // Default constructor.
	{
	 front=-1;
	 rear=-1;
	}
	void add();
	void deletion();
	void display();
};
void queue::add()
{
 float no;
 if(rear==max-1)
  cout<<"Overflow error\n";
 else
  {
   cout<<"Enter the number to be added\n";
   cin>>no;
   a[++rear]=no;
  }
}
void queue::deletion()
{
 float no;
 if(rear==front)
  cout<<"Underflow error\n";
 else
  {
   no=a[++front];
   cout<<"The number deleted is :"<<no<<'\n';
  }
}
void queue::display()
{
 if(front==rear)
  cout<<"Queue is empty\n";
 else
  {
   cout<<"Queue is:\n";
   for(int i=front+1;i<=rear;i++)
    cout<<a[i]<<'\n';
  }
}
void main()
{
 int ch;
 queue q;
 do
 {
  clrscr();
  cout<<"Queue operation menu :\n";
  cout<<"1. Add\n";
  cout<<"2. Delete\n";
  cout<<"3. Display\n";
  cout<<"4. Quit\n";
  cout<<"Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:q.add();
	  q.display();
	  break;
   case 2:q.deletion();
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