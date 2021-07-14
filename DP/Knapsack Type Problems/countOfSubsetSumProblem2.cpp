// To implement count of subset sum problem using top down approach

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

// Function to check if a subset can be made from the given array that has a given sum 
int countOfSubsetSumRec(int sum,int arr[],int n) 
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
  return dp[n][sum]=countOfSubsetSumRec(sum-arr[n-1],arr,n-1) + countOfSubsetSumRec(sum,arr,n-1);
 else
  return dp[n][sum]=countOfSubsetSumRec(sum,arr,n-1);  
} 

int countOfSubsetSum(int sum,int *arr,int n)
{
 memset(dp,-1,sizeof dp);
 return countOfSubsetSumRec(sum,arr,n);
}

int main() 
{ 
 int arr[]={1,1,1,1};  
 int sum=1; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<countOfSubsetSum(sum,arr,n); 
 return 0; 
}
