// To count the number of 1's in a binary number.

#include<bits/stdc++.h>
using namespace std;

int main()
{
 long long int count=0;
 long long int n;
 cin>>n;
 while(n)
 {
  n=n&(n-1);
  count++;
 }
 cout<<count;
 return 0;
}
