// To demonstrate friend class.

#include<bits/stdc++.h>
using namespace std;  
  
class A  
{  
 int x=10;  
 friend class B;        
}; 
 
class B  
{  
 public:void display(A &a)  
        {  
         cout<<"value of x is : "<<a.x;  
        }  
};  

int main()  
{  
 A a;  
 B b;  
 b.display(a);  
 return 0;  
}
