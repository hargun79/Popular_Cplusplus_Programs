// To implement Sieve of Eratosthenes.

#include <bits/stdc++.h>
using namespace std;

long long int arr[1000001] = {0};
long long int k=0; 

void SieveOfEratosthenes(long long int n) 
{ 
 bool prime[n+1]; 
 memset(prime, true, sizeof(prime)); 
 for(long long int p=2;p*p<=n;p++) 
 { 
  if(prime[p]==true) 
  { 
   for(long long int i=p*p;i<=n;i+=p) 
    prime[i]=false; 
  } 
 }
 for(long long int p=2;p<=n;p++) 
  if(prime[p])
   arr[k++]=p;  
}
 
int main()
{
 long long int n;
 cout<<"Enter the number upto which the prime numbers have to be generated: \n";
 cin>>n;
 SieveOfEratosthenes(n);
 for(int i=0;i<k;i++)
  cout<<arr[i]<<" ";
 return 0; 
}
