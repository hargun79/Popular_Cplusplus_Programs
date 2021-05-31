/* Start DP from here:-
How to recognize that the question will be done from DP:
1. It is optimization problem(max,min,etc.)
2. It offers choice like either we can take element or cant take it.
Now, first make recursive solution
Recursive consists of two parts:
1. Base condition: It is the smallest valid value/
2. Choice tree: One recursive call for checking if it can be taken or not and two recursive calls for choice for either taking it or not taking it.
Then memoize the recursive solution to make it a dp solution
How to know what constraints to take in the array:
The constraints which are decreasing there value in recursive calls
Initialize the matrix with -1
Only 4-5 statements will be added after adding memoization
One base condition will be added so that stored values do not make recursive calls again.

The above approach is called top down approach or memoization approach. */


// To implement the 0-1 knapsack problem

#include <bits/stdc++.h> 
using namespace std; 

// Returns the value of maximum profit 
int knapSackRec(int cap,int wt[],int val[],int i,int** dp) 
{ 
 if(i<0) 
  return 0; 
 if(dp[i][cap]!=-1) 
  return dp[i][cap]; 
 if(wt[i]>cap) 
 { 
  dp[i][cap]=knapSackRec(cap,wt,val,i-1,dp); 
  return dp[i][cap]; 
 } 
 else 
 { 
  dp[i][cap]=max(val[i]+knapSackRec(cap-wt[i],wt,val,i-1,dp),knapSackRec(cap,wt,val,i-1,dp)); 
  return dp[i][cap]; 
 } 
} 

int knapSack(int cap, int wt[], int val[], int n) 
{ 
 int** dp; 
 dp=new int*[n]; 
 for(int i=0;i<n;i++) 
  dp[i]=new int[cap+1]; 
 for(int i=0;i<n;i++) 
  for(int j=0;j<cap+1;j++) 
   dp[i][j]=-1; 
 return knapSackRec(cap,wt,val,n-1,dp); 
} 

int main() 
{ 
 int val[]={10,20,30}; 
 int wt[]={1,1,1}; 
 int cap=2; 
 int n=sizeof(val)/sizeof(val[0]); 
 cout<<knapSack(cap,wt,val,n); 
 return 0; 
} 
