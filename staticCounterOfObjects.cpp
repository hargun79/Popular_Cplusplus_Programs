// To count the number of objects created in the program using static counter.

#include<bits/stdc++.h>
using namespace std;

class counter
{
 static int count;
 int a;
 public:
 	    counter()
 	    {
 	     count++;
		 a=10;
		 cout<<"The number of objects created till now are: "<<count<<'\n'; 	
		}
		~counter()
		{}
};

int counter::count;

int main()
{
 counter c1,c2,c3;
 return 0;
}
