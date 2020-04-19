// To add two complex numbers using friend function.

#include<bits/stdc++.h>
using namespace std;

class complexNumber
{
 int real,imag;
 public:
        void set()
        { 
         cout<<"Enter real and imaginary part: \n";
         cin>>real>>imag;
        }
        friend complexNumber sum(complexNumber,complexNumber);
        void display()
        {
         cout<<"The sum of complex number is: "<<real<<"+"<<imag<<"i"<<'\n';
        }

};

// Friend function
complexNumber sum(complexNumber a,complexNumber b)
{
 complexNumber t;
 t.real=a.real+b.real;
 t.imag=a.imag+b.imag;
 return t;
}

int main()
{
 complexNumber a,b,c;
 a.set();
 b.set();
 c=sum(a,b);
 c.display();
 return 0;
}
