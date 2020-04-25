// To implement multiple inheritance.

#include<bits/stdc++.h>
using namespace std;

class Mammal 
{
 public:Mammal()
        {
         cout << "Mammals can give direct birth \n";
        }
};

class WingedAnimal 
{
 public:WingedAnimal()
        {
         cout << "Winged animal can flap \n";
        }
};

class Bat: public Mammal, public WingedAnimal 
{
 public:Bat()
        {
         cout<<"Bat is both a mammal and winged animal \n";
		}
};

int main()
{
 Bat b1;
 return 0;
}
