// To find sum of numbers upto n having 2 set bits

#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
#define m 1000000007

int main()
{
 ll n,sum=0;
 cin>>n;
 for(ll i=2;i<n;i*=2)
  for(ll j=1;j<i;j*=2)
   if((i+j)<=n)
    sum=(sum+i+j)%m;
 cout<<(sum%m);
 return 0;
}
