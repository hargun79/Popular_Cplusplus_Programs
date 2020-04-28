// Function overloading.

#include<bits/stdc++.h>
using namespace std;

class Addition 
{
 public:int sum(int num1,int num2) 
        {
         return num1+num2;
        }
        int sum(int num1,int num2, int num3) 
		{
         return num1+num2+num3;
        }
};

int main() 
{
 Addition obj;
 cout<<obj.sum(1,2)<<'\n';
 cout<<obj.sum(3,4,5);
 return 0;
}
