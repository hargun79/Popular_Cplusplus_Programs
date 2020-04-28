// Unary operator overloading.

#include<bits/stdc++.h>
using namespace std;
 
class Distance 
{
 private:int feet;             
         int inches;           
 public:Distance() 
        {
         feet=0;
         inches=0;
        }
        Distance(int f, int i) 
		{
         feet=f;
         inches=i;
        }
        void displayDistance() 
		{
         cout<<"F: "<<feet<<" I: "<<inches;
        }
        Distance operator- () 
		{
         feet=-feet;
         inches=-inches;
         return Distance(feet, inches);
        }
};

int main() 
{
 Distance D1(5, 8);
 -D1; 
 D1.displayDistance();
 return 0;
}
