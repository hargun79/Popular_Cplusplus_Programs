// To implement count of subsets with given difference problem
// This problem can be modified to target sum problem in which we have to insert plus and minus in the elements of array to achieve a particular sum

#include<bits/stdc++.h>
using namespace std;

// Function to count the number of subsets with given difference
int countOfSubsetSumWithGivenDiff(int diff,int arr[],int n) 
{  
 int sum=0;
 for(int i=0;i<n;i++)
  sum+=arr[i];
 int rSum=(diff+sum)/2; 
 int dp[n+1][rSum+1]; 
 for(int i=0;i<=n;i++) 
 { 
  for(int j=0;j<=rSum;j++) 
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
 return dp[n][rSum]; 
} 

int main() 
{ 
 int arr[]={1,2,3};  
 int diff=2; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<countOfSubsetSumWithGivenDiff(diff,arr,n); 
 return 0; 
}