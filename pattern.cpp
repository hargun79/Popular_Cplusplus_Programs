// To print a pattern.

#include<iostream>
using namespace std;

int main()
{
  for(int i=1;i<7;i+=2)
  {
   cout<<'\n';
   for(int k=(5-i);k>0;k--)
    cout<<" ";
   for(int j=0;j<i;j++)
    cout<<"*"<<" ";
  }
  for(int i=5;i>0;i-=2)
  {
   cout<<'\n';
   for(int k=0;k<(5-i);k++)
    cout<<" ";
   for(int j=i;j>0;j--)
    cout<<"*"<<" ";
  }
  return 0;  
}

