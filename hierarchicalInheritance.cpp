// To implement hierarchical inheritance.

#include<bits/stdc++.h>
using namespace std;

class A
{
 public:int x,y;
 	    void getdata()
 	    {
   	     cout<<"Enter value of x and y: \n";
	     cin>>x>>y;
 	    }
};

class B: public A 
{
 public:void product()
 	    {
 	     cout<<"Product = " <<x*y<<'\n';
 	    }
};

class C: public A 
{
 public:void sum()
 	    {
         cout<<"Sum = "<<x+y;
 	    }
};

int main()
{
 B obj1;         
 C obj2;         
 obj1.getdata();
 obj1.product();
 obj2.getdata();
 obj2.sum();
 return 0;
}
