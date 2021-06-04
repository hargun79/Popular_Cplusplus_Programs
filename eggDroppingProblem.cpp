// To implement egg dropping problem

#include <bits/stdc++.h> 
using namespace std; 

// Function to find maximum of two numbers
int max(int a,int b) 
{ 
 return(a>b)?a:b; 
} 

// Function to get minimum number of trials needed in worst case with n eggs and k floors 
int eggDrop(int n, int k) 
{ 
 if(k==1 || k==0) 
  return k; 
 if(n==1) 
  return k; 
 int min=INT_MAX,x,res; 
 for(x=1;x<=k;x++)
 { 
  res=max(eggDrop(n-1,x-1),eggDrop(n,k-x)); 
  if(res<min) 
   min=res; 
 } 
 return min+1; 
} 

int main() 
{ 
 int n=2,k=10; 
 int ans=eggDrop(n,k);
 cout<<ans;
 return 0; 
} 