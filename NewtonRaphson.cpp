// To find roots of equation using Newton-Raphson method.

#include<iostream>
#include<math.h>
using namespace std;

#define EPSILON 0.0001

double a,b,c;

// To calculate f(x).
double func(double  n)
{
  return a*n*n + b*n + c;
}

// To calculate derivative of f(x).
double derFunc(double n)
{
  return (2*a*n)+(b);
}

// To find root using Newton-Raphson method
double funcNewRap(double x)
{
  double h=func(x)/derFunc(x); 
  while(abs(h)>=EPSILON) 
  { 
    h=func(x)/derFunc(x); 
    x=x-h; 
  } 
  cout<<"The value of the root is : " << x<<'\n'; 
} 


int main()
{
  cout<<"Enter the coeffecients of the quadratic equation: \n";
  cin>>a>>b>>c;
  funcNewRap(100);
  return 0;  
}

