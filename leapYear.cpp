// To find number of leap years between 1990 to 2008.

#include<iostream>
using namespace std;

int main()
{
  cout<<"The leap years between 1990 and 2008 are: \n";
  for(int i=1990;i<=2008;i++)
   if(i%4==0 && i%100!=0 || i%400==0)
    cout<<i<<'\n';
  return 0;
}
