// To implement minimum subset sum difference problem i.e. make two partitions of the array such that the difference between the two partitions is minimum.

#include<bits/stdc++.h>
using namespace std;

// Function to find the minimum difference between two partitions. 
int subsetSum(int arr[],int n) 
{  
 int range=0;
 for(int i=0;i<n;i++)
  range+=arr[i]; 
 bool dp[n+1][range/2+1]; 
 for(int i=0;i<=n;i++) 
 { 
  for(int j=0;j<=range/2;j++) 
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
 vector<int> v;
 for(int i=0;i<=range/2;i++)
  if(dp[n][i])
   v.push_back(i);
 int mn=INT_MAX;
 for(int i=0;i<v.size();i++)
  mn=min(mn,range-2*v[i]);  
 return mn; 
} 

int main() 
{ 
 int arr[]={1,6,11,5};  
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<subsetSum(arr,n); 
 return 0; 
}