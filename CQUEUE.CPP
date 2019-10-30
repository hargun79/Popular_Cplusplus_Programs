// Static implementation of circular queue.
#include<iostream.h>
#include<conio.h>
#include<process.h>
#define max 100
class cqueue
{
 float a[max];
 int front,rear;
 public:
	cqueue()
	{
	 front=0;
	 rear=0;
	}
	void add(float);
	float deletion();
	void display();
};
void cqueue::add(float no)
{
 if((rear+1)%max==front)
  cout<<"Overflow error\n";
 else
  {
   rear=(rear+1)%max;
   a[rear]=no;
   cout<<"Element is added\n";
  }
}
float cqueue::deletion()
{
 float no=-999;
 if(front==rear)
  cout<<"Underflow error\n";
 else
  {
   front=(front+1)%max;
   no=a[front];
  }
 return(no);
}
void cqueue::display()
{
 if(front==rear)
  cout<<"Queue is empty\n";
 else
  {
   int i=front;
   cout<<"The elements are:\n";
   do
    {
     i=(i+1)%100;
     cout<<a[i]<<'\n';
    }
   while(i!=rear);
  }
}
void main()
{
 int ch;
 float no;
 cqueue c;
 do
  {
   clrscr();
   cout<<"Circular queue operations :\n";
   cout<<"1. ADD\n";
   cout<<"2. DELETION\n";
   cout<<"3. DISPLAY\n";
   cout<<"4. Quit\n";
   cout<<"Enter your choice\n";
   cin>>ch;
   switch(ch)
    {
     case 1:cout<<"Enter the number to be inserted in the queue\n";
	    cin>>no;
	    c.add(no);
	    break;
     case 2:no=c.deletion();
	    if(no!=-999)
	     cout<<"The deleted no is :\t"<<no;
	    break;
     case 3:c.display();
	    break;
     case 4:exit(0);
     default:cout<<"Wrong choice\n";
    }
   getch();
  }
 while(ch!=4);
}