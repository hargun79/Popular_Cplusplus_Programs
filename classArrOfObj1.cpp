// To make a class student and display the data of a student of a class having 30 students.

#include<iostream>
using namespace std;

class student
{
  int rno;
  char name[30];
  int marks[5];
  float percentage;
  public:
  	     void readData();
  	     void displayData();
  	     void computeData();
};

// Function to input credentials of student.
void student::readData()
{
  cout<<"Enter the details: \n";
  cout<<"Enter the roll number: \n";
  cin>>rno;
  cout<<"Enter the name: "<<endl;
  cin>>name;
  cout<<"Enter marks of 5 subjects: \n";
  for(int i=0;i<5;i++)
   cin>>marks[i];
}

// Function to display credentials of student.
void student::displayData()
{
  cout<<"The details are: \n";
  cout<<"The roll number is: \n";
  cout<<rno<<'\n';
  cout<<"The name is: \n";
  cout<<name<<'\n';
  cout<<"The marks of 5 subjects are: \n";
  for(int i=0;i<5;i++)
   cout<<marks[i]<<'\t';
  cout<<'\n';
  cout<<"The Percentage is: \n";
  cout<<percentage<<"%"<<'\n';
}

// Function to calculate the percentage based on marks.
void student::computeData()
{
  int sum=0;
  for(int i=0;i<5;i++)
   sum+=marks[i];
  percentage=sum/5;
}

int main()
{
  student s[30];
  int n;
  cout<<"Enter the number of students: \n";
  cin>>n;
  for(int i=0;i<n;i++)
  {
   s[i].readData();
   s[i].computeData();
  }
  for(int i=0;i<n;i++)
   s[i].displayData();
  return 0;
}
