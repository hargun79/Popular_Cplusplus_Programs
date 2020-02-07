// To print greatest number using ternary operator.

#include<iostream>
using namespace std;

int main()
{
  int a,b,c;
  cout<<"Enter three numbers: \n";
  cin>>a>>b>>c;
  int lar=(a>b)?(a>c?a:c):(b>c?b:c);
  cout<<"The largest among the three numbers is: \n"<<lar;
  return 0;
}

