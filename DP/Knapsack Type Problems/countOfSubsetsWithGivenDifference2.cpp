// To implement count of subsets with given difference problem using top down approach
// This problem can be modified to target sum problem in which we have to insert plus and minus in the elements of array to achieve a particular sum

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

// Function to check if a subset can be made from the given array that has a given sum 
int countOfSubsetSumWithGivenDiffRec(int sum,int arr[],int n) 
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
  return dp[n][sum]=countOfSubsetSumWithGivenDiffRec(sum-arr[n-1],arr,n-1)+countOfSubsetSumWithGivenDiffRec(sum,arr,n-1);
 else
  return dp[n][sum]=countOfSubsetSumWithGivenDiffRec(sum,arr,n-1);  
} 

int countOfSubsetSumWithGivenDiff(int diff,int *arr,int n)
{
 memset(dp,-1,sizeof dp);
 int sum=0;
 for(int i=0;i<n;i++)
  sum+=arr[i];
 int rSum=(diff+sum)/2;
 return countOfSubsetSumWithGivenDiffRec(rSum,arr,n);
}

int main() 
{ 
 int arr[]={1,2,3};  
 int diff=2; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<countOfSubsetSumWithGivenDiff(diff,arr,n); 
 return 0; 
}
