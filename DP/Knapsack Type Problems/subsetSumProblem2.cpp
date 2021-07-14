// To implement Subset Sum problem using top down approach

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

// Function to check if a subset can be made from the given array that has a given sum 
int subsetSumRec(int sum,int arr[],int n) 
{  
 if(n==0 || sum==0)
 { 
  if(sum==0)
   return dp[n][sum]=1;
  return dp[n][sum]=0;
 }
 if(dp[n][sum]!=-1)
  return dp[n][sum];
 if(arr[n-1]<=sum) 
  return dp[n][sum]=subsetSumRec(sum-arr[n-1],arr,n-1) || subsetSumRec(sum,arr,n-1);
 else
  return dp[n][sum]=subsetSumRec(sum,arr,n-1);  
} 

int subsetSum(int sum,int *arr,int n)
{
 memset(dp,-1,sizeof dp);
 return subsetSumRec(sum,arr,n);
}

int main() 
{ 
 int arr[]={3,34,4,12,5,2};  
 int sum=9; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<subsetSum(sum,arr,n); 
 return 0; 
}
