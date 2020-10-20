// To implement knapsack problem

#include<bits/stdc++.h>
using namespace std;

// Function to return the maximum value that can be put in a knapsack of capacity W 
int knapSack(int cap, int wt[], int val[], int n) 
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
	 K[i][w]=max(val[i-1]+K[i-1][w-wt[i-1]], K[i-1][w]); 
    else
	 K[i][w]=K[i-1][w]; 
  } 
 } 
 return K[n][cap]; 
} 

int main() 
{ 
 int val[]={60,100,120}; 
 int wt[]={10,20,30}; 
 int cap=50; 
 int n=sizeof(val)/sizeof(val[0]); 
 cout<<knapSack(cap,wt,val,n); 
 return 0; 
} 
