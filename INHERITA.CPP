// Program using Inheritance.
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class person
{
 char name[20];
 char address[20];
 public:
	// Default Constructor.
	person()
	{
	 name[0]='\0';
	 address[0]='\0';
	}
	// Parametrized Constructor.
	person(char n[],char a[])
	{
	 strcpy(name,n);
	 strcpy(address,a);
	}
	void IN()
	{
	 cout<<"Enter the name\n";
	 gets(name);
	 cout<<"Enter the address\n";
	 gets(address);
	}
	void OUT()
	{
	 cout<<"\n\n\n";
	 cout<<"The name is            :"<<name<<'\n';
	 cout<<"The address is         :"<<address<<'\n';
	}
};
// Derived class.
class STUDENT:public person
{
 protected:
	   int admno;
	   char cl[5];
	   char sec[2];
	   float marks[3];
 public:
	//To call base class constructor explicitly as they are not inherited.
	STUDENT():person()
	{
	 admno=0;
	 cl[0]='\0';
	 sec[0]='\0';
	 marks[0]=0;
	 marks[1]=0;
	 marks[2]=0;
	}
	STUDENT(char n[],char a[],int ad,char c[],char s[]):person(n,a)
	{
	 admno=ad;
	 strcpy(cl,c);
	 strcpy(sec,s);
	}
	void IN();
	void OUT();
};
void STUDENT::IN()
{
 person::IN(); // Function overriding.
 cout<<"Enter the admission number\n";
 cin>>admno;
 cout<<"Enter the class\n";
 gets(cl);
 cout<<"Enter the section\n";
 gets(sec);
 cout<<"Enter the marks of three subjects\n";
 for(int i=0;i<3;i++)
  cin>>marks[i];
}
void STUDENT::OUT()
{
 person::OUT();// Function overriding.
 cout<<"The admission number is:"<<admno<<'\n';
 cout<<"The class is           :"<<cl<<'\n';
 cout<<"The section is         :"<<sec<<'\n';
 cout<<"The marks are          :";
 for(int i=0;i<3;i++)
  cout<<marks[i]<<'\t';
 cout<<'\n';
}
class result:public STUDENT
{
 float per;
 char res[10];
 public:
	result():STUDENT()
	{
	 per=0;
	 res[0]='\0';
	}
	void IN();
	void OUT();
};
void result::IN()
{
 STUDENT::IN();  // Function overriding.
 per=0.20*marks[0]+0.30*marks[1]+0.50*marks[2];
 if(per>=33)
  strcpy(res,"PASSED");
 else
  strcpy(res,"FAILED");
}
void result::OUT()
{
 STUDENT::OUT(); // Function overriding.
 cout<<"The percentage is      :"<<per<<'\n';
 cout<<"The result is          :"<<res<<'\n';
}
void main()
{
 clrscr();
 result r;
 r.IN();
 clrscr();
 r.OUT();
 getch();
}