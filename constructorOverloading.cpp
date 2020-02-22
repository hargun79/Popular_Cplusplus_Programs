// Constructor overloading.

#include<bits/stdc++.h>
using namespace std;

class student
{
  int rno;
  char name[30];
  int marks[5];
  float percentage;
  public:
         // Default constructor.
		 student()
         {
          cout<<"\nDefaut Constructor called \n";
          rno=0;
          strcpy(name," ");
          for(int i=0;i<5;i++)
           marks[i]=0;
         }
         // Parametrized constructor.
         student(int r,char n[], int m[])
         {
          cout<<"\nParametrized constructor called \n";
          rno=r;
          strcpy(name,n);
          for(int i=0;i<5;i++)
           marks[i]=m[i];
         } 
         // Copy constructor.
         student(student &s)
         {
          cout<<"\nCopy constructor called \n";
          rno=s.rno;
          strcpy(name,s.name);
          for(int i=0;i<5;i++)
           marks[i]=s.marks[i];
         }
         // Destructor.
         ~student()
         {
          cout<<"\nDestructor called \n";
		 }
         void input();
         void compute();
         void output();
};

// Function to input the values
void student::input()
{
 cout<<"Enter the roll number: \n";
 cin>>rno;
 cout<<"Enter the name: \n";
 cin>>name;
 cout<<"Enter the marks: \n";
 for(int i=0;i<5;i++)
  cin>>marks[i];
}

// Function to compute the percentage.
void student::compute()
{
 for(int i=0;i<5;i++)
  percentage+=marks[i];
 percentage/=5;
}

// Function to output the percentage
void student::output()
{
 cout<<"\nThe roll number is: "<<rno<<'\n';
 cout<<"The name is: "<<name<<'\n';
 cout<<"The marks are: \n";
 for(int i=0;i<5;i++)
  cout<<marks[i]<<'\t';
 cout<<'\n';
 cout<<"The percentage is: "<<percentage;
}

int main()
{
 student s;
 s.input();
 s.compute();
 s.output();
 student s1=s;
 s1.compute();
 s1.output();
 return 0;
}


