// To implement count of subsets sum problem i.e. to find number of subsets with a given sum

#include<bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with given sum 
int countOfSubsetSum(int sum,int arr[],int n) 
{  
 int dp[n+1][sum+1]; 
 for(int i=0;i<=n;i++) 
 { 
  for(int j=0;j<=sum;j++) 
  { 
   if(i==0 || j==0)
   { 
    dp[i][j]=0;
    if(j==0)
     dp[i][j]=1;
   }
   else
    if(arr[i-1]<=j) 
	 dp[i][j]=dp[i-1][j-arr[i-1]] + dp[i-1][j]; 
    else
	 dp[i][j]=dp[i-1][j]; 
  } 
 } 
 return dp[n][sum]; 
} 

int main() 
{ 
 int arr[]={2,3,5,6,8,10};  
 int sum=10; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<countOfSubsetSum(sum,arr,n); 
 return 0; 
}