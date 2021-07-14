// To implement equal sum partition problem using top down approach

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int equalPartitionRec(int sum,int *arr,int n)
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
  return dp[n][sum]=equalPartitionRec(sum-arr[n-1],arr,n-1) || equalPartitionRec(sum,arr,n-1);
 else
  return dp[n][sum]=equalPartitionRec(sum,arr,n-1);
}

// Function to check if array can be divided into two partitions of equal sum
int equalPartition(int n, int arr[])
{
 int sum=0;
 for(int i=0;i<n;i++)
  sum+=arr[i];
 if(sum%2!=0)
  return 0;
 else
 {
  sum/=2;
  memset(dp,-1,sizeof dp);
  return equalPartitionRec(sum,arr,n);
 }
}

int main() 
{ 
 int arr[]={1,5,5,11};  
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<equalPartition(n,arr); 
 return 0; 
}
