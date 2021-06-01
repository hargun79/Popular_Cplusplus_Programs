// To implement Subset Sum problem

#include<bits/stdc++.h>
using namespace std;

// Function to check if a subset can be made from the given array that has a given sum 
bool subsetSum(int sum,int arr[],int n) 
{  
 bool dp[n+1][sum+1]; 
 for(int i=0;i<=n;i++) 
 { 
  for(int j=0;j<=sum;j++) 
  { 
   if(i==0 || j==0)
   { 
    dp[i][j]=false;
    if(j==0)
     dp[i][j]=true;
   }
   else
    if(arr[i-1]<=j) 
	 dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j]; 
    else
	 dp[i][j]=dp[i-1][j]; 
  } 
 } 
 return dp[n][sum]; 
} 

int main() 
{ 
 int arr[]={3,34,4,12,5,2};  
 int sum=9; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<subsetSum(sum,arr,n); 
 return 0; 
}