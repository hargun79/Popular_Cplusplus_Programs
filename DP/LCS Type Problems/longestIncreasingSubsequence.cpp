// To find longest increasing subsequence using bottom up approach

#include<bits/stdc++.h> 
using namespace std; 

// Function to find the longest increasing subsequence
int lis(string str1,string str2,int m,int n) 
{ 
 int L[m+1][n+1]; 
 for(int i=0;i<=m;i++) 
 { 
  for(int j=0;j<=n;j++) 
  { 
   if(i==0 || j==0) 
	 L[i][j]=0; 
   else 
    if(str1[i-1]==str2[j-1]) 
	  L[i][j]=L[i-1][j-1]+1; 
   else
    L[i][j]=max(L[i-1][j],L[i][j-1]); 
  } 
 } 
 return L[m][n]; 
} 

int main() 
{ 
 string str1;
 cin>>str1;
 string str2=str1;
 sort(str2.begin(),str2.end());  
 cout<<"Length of LIS is: "<<lis(str1,str2,str1.length(),str2.length()); 
 return 0; 
} 