// To implement egg dropping problem using binary search

#include <bits/stdc++.h> 
using namespace std; 

// Function to find sum of binomial coefficients xCi  
int binomialCoeff(int x, int n) 
{ 
 int sum=0,term=1; 
 for(int i=1;i<=n;++i)
 { 
  term*=x-i+1; 
  term/=i; 
  sum+=term; 
 } 
 return sum; 
} 

// Function to do binary search to find minimum number of trials in worst case. 
int minTrials(int n, int k) 
{ 
 int low=1,high=k; 
 while(low<high)
 { 
  int mid=(low+high)/2; 
  if(binomialCoeff(mid,n)<k) 
   low=mid+1; 
  else
   high=mid; 
 } 
 return low; 
} 

int main() 
{ 
 int n=2,k=10;
 int ans=minTrials(n,k);
 cout<<ans; 
 return 0; 
} 
