// To implement knapsack problem and find the weights included
 
#include <bits/stdc++.h> 
using namespace std;

// Function to implement knapsack problem 
void printknapSack(int cap,int wt[],int val[],int n) 
{ 
 int i,w; 
 int K[n+1][cap+1]; 
 for(i=0;i<=n;i++) 
 { 
  for(w=0;w<=cap;w++) 
  { 
   if(i==0 || w==0) 
	K[i][w]=0; 
   else 
    if(wt[i-1]<=w) 
	 K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]); 
   else
    K[i][w]=K[i-1][w]; 
  } 
 } 
 int res=K[n][cap];	 
 cout<<res<<'\n'; 
 w=cap; 
 for(i=n;i>0 && res>0;i--) 
 { 
  if(res==K[i-1][w]) 
   continue;		 
  else 
  { 
   cout<<wt[i-1]<<" "; 
   res=res-val[i-1]; 
   w=w-wt[i-1]; 
  } 
 } 
} 

int main() 
{ 
 int val[]={60,100,120}; 
 int wt[]={10,20,30}; 
 int cap=50; 
 int n=sizeof(val)/sizeof(val[0]); 
 printknapSack(cap,wt,val,n); 
 return 0; 
} 
