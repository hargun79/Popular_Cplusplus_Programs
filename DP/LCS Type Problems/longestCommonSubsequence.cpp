// To find longest common subsequence using top down approach

#include<bits/stdc++.h> 
using namespace std; 

int dp[1001][1001];

// Function to find the longest common subsequence
int lcs(string str1,string str2,int m,int n) 
{ 
  if(n==0 || m==0)
   return 0;
  if(dp[m][n]!=-1)
   return dp[m][n];
  if(str1[m-1]==str2[n-1])
   return dp[m][n]=1+lcs(str1,str2,m-1,n-1);
  else
   return dp[m][n]=max(lcs(str1,str2,m-1,n),lcs(str1,str2,m,n-1));    
} 

int main() 
{ 
 string str1,str2;
 cin>>str1>>str2;
 memset(dp,-1,sizeof(dp));  
 cout<<"Length of LCS is: "<<lcs(str1,str2,str1.length(),str2.length()); 
 return 0; 
} 