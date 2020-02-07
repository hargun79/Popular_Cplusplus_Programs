// To find roots of linear equation using bisection method.

#include<iostream> 
using namespace std; 

#define EPSILON 0.01 

double a,b,c;

// To calculate f(x)
double func(double n) 
{ 
 return a*n*n + b*n + c; 
} 

// To find roots using bisection method.
void bisection(double x, double y) 
{ 
	/*if(func(x)*func(y)>=0) 
	{ 
	 cout << "You have not assumed right a and b \n"; 
	 return; 
	} */
    double z=x; 
	while((y-x)>=EPSILON) 
	{ 
     z=(x+y)/2; 
     if(func(z) == 0.0) 
	  break; 
     else 
	  if(func(z)*func(x)<0) 
	   y=z; 
	 else
	  x=z; 
	} 
	cout<<"The value of root is: "<<z; 
} 

int main() 
{ 
 double x,y; 
 cout<<"Enter the value of a and b: \n";
 cin>>x>>y;
 cout<<"Enter the coeffecients of the quadratic equation: \n";
 cin>>a>>b>>c;
 bisection(x,y); 
 return 0; 
} 

