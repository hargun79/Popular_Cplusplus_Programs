// To implement minimum subset sum difference problem i.e. make two partitions of the array such that the difference between the two partitions is minimum.

#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002];

// Function to check if a subset can be made from the given array that has a given sum 
int subsetSumRec(int arr[],int sum,int n,int curSum) 
{  
 if(n==0) 
  return abs(sum-(2*curSum));
 if(dp[n][curSum]!=-1)
  return dp[n][curSum];
 return dp[n][curSum]=min(subsetSumRec(arr,sum,n-1,curSum),subsetSumRec(arr,sum,n-1,curSum+arr[n-1])); 
} 

int subsetSum(int *arr,int n)
{
 int sum=0;
 for(int i=0;i<n;i++)
  sum+=arr[i];
 memset(dp,-1,sizeof dp);
 return subsetSumRec(arr,sum,n-1,0);
}

int main() 
{ 
 int arr[]={20,19,18,20,16};  
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<subsetSum(arr,n); 
 return 0; 
}
