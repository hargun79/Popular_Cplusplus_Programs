// To find all the substrings of a string in O(N^2)

#include<bits/stdc++.h>
using namespace std; 

int main()
{
 string str;
 cin>>str;
 for(int i=0;i<str.length();i++) 
  for(int j=1;j<=str.length()-i;j++) 
   cout<<str.substr(i,j)<<'\n';
}
