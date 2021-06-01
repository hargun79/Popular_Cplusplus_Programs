// To implement rod cutting problem

#include<bits/stdc++.h>
using namespace std;

// Function to find maximum profit 
int rodCutting(int len,int price[])
{ 
 int dp[len+1][len+1]; 
 for(int i=0;i<=len;i++) 
 { 
  for(int j=0;j<=len;j++) 
  { 
   if(i==0 || j==0) 
    dp[i][j]=0; 
   else
    if(i<=j) 
	 dp[i][j]=max(price[i-1]+dp[i][j-i], dp[i-1][j]); 
    else
	 dp[i][j]=dp[i-1][j]; 
  } 
 } 
 return dp[len][len]; 
} 

int main() 
{ 
 int price[]={1,5,8,9,10,17,17,20}; 
 int len=sizeof(price)/sizeof(price[0]); 
 cout<<rodCutting(len,price); 
 return 0; 
} 