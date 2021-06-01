// To implement coin change problem i.e. find the minimum number of coins out of given denominations to pay the bill

#include<bits/stdc++.h>
using namespace std;

// Function to find the minimum number of coins required
int coinChangeProblem(int bill,int den[],int n) 
{ 
 int dp[n+1][bill+1]; 
 for(int i=0;i<=n;i++) 
 { 
  for(int j=0;j<=bill;j++) 
  { 
   if(i==0 || j==0) 
   {
    dp[i][j]=INT_MAX-1;
    if(j==0)
     dp[i][j]=0; 
   }
   else
    if(den[i-1]<=j) 
	 dp[i][j]=min(1+dp[i][j-den[i-1]],dp[i-1][j]); 
    else
	 dp[i][j]=dp[i-1][j]; 
  } 
 } 
 if(dp[n][bill]!=INT_MAX && dp[n][bill]!=(INT_MAX-1))
  return dp[n][bill];
 else
  return -1; 
} 

int main() 
{ 
 int den[]={1,2,3};  
 int bill=5; 
 int n=sizeof(den)/sizeof(den[0]); 
 cout<<coinChangeProblem(bill,den,n); 
 return 0; 
}