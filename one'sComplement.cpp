// To find 1's complement of a number

#include<bits/stdc++.h>
using namespace std;

int main()
{
 long long int n;
 cin>>n;
 int nob=(log2(n))+1;
 int oc=((1<<nob)-1)^n;
 cout<<oc;
 return 0;
}
