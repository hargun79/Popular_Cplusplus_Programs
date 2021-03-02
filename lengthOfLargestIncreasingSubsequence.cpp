// To find the length of the largest increasing subsequence

#include<bits/stdc++.h> 
using namespace std; 
	
// Function to find the length of the largest increasing subsequence
int lis(int arr[],int n) 
{ 
 int lis[n]; 
 lis[0]=1; 
 for(int i=1;i<n;i++) 
 { 
  lis[i]=1; 
  for(int j=0;j<i;j++) 
   if(arr[i]>arr[j] && lis[i]<lis[j]+1) 
	lis[i]=lis[j]+1; 
 } 
 return *max_element(lis,lis+n); 
} 
	
int main() 
{ 
 int arr[]={10,22,9,33,21,50,41,60}; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 cout<<"Length of largest increasing subsequence is: "<<lis(arr,n ); 
 return 0; 
}

/* Maximum sum LIS
int maxSumIS(int arr[], int n)  
{  
 vector<int> dp(arr,arr+n);
 for(int i=1;i<n;i++) 
  for(int j=0;j<i;j++)
   if(arr[j]<arr[i])
    dp[i]=max(dp[i],arr[i]+dp[j]);
 return *max_element(dp.begin(),dp.end());
}
*/	
