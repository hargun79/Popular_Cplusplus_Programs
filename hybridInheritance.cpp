// To implement hybrid inheritance.

#include<bits/stdc++.h> 
using namespace std; 

class Person 
{ 
 public:Person(int x) 
        { 
         cout << "Constructor called from Person class \n"; 
        } 
 	    Person()
		{ 
		 cout << "Constructor called from Person class \n"; 
		} 
}; 

class Faculty : virtual public Person 
{ 
 public:Faculty(int x):Person(x) 
        { 
	     cout<<"Constructor called from Faculty class \n"; 
	    } 
}; 

class Student : virtual public Person 
{ 
 public:Student(int x):Person(x) 
        { 
		 cout<<"Constructor called from Student class \n"; 
	    } 
}; 

class College : public Faculty, public Student 
{ 
 public:College(int x):Student(x), Faculty(x) 
        { 
		 cout<<"Constructor called from College class \n"; 
	    } 
}; 

int main() 
{ 
 College c(30);
 return 0; 
} 
