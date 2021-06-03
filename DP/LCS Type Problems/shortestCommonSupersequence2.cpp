// To print the shortest common supersequence

#include<bits/stdc++.h>
using namespace std; 

// Function to print the shortest common supersequence
void scs(char *X,char *Y,int m,int n) 
{ 
 int L[m+1][n+1]; 
 for(int i=0;i<=m;i++) 
 { 
  for(int j=0;j<=n;j++) 
  { 
   if(i==0 || j==0) 
    L[i][j]=0; 
   else 
    if(X[i-1]==Y[j-1]) 
     L[i][j]=L[i-1][j-1]+1; 
   else
	L[i][j]=max(L[i-1][j],L[i][j-1]); 
  } 
 } 
 int index=L[m][n]; 
 string scs;  
 int i=m,j=n; 
 while(i>0 && j>0) 
 {  
  if(X[i-1]==Y[j-1]) 
  { 
   scs.push_back(X[i-1]);
   i--; 
   j--; 	  
  } 
  else 
   if(L[i-1][j]>L[i][j-1])
   { 
	scs.push_back(X[i-1]);
    i--;
   } 
  else
  {
   scs.push_back(Y[j-1]);
   j--;
  } 
 } 
 while(i>0)
 {
  scs.push_back(X[i-1]);
  i--;
 }
 while(j>0)
 {
  scs.push_back(Y[j-1]);
  j--;
 }
 reverse(scs.begin(),scs.end());
 cout<<"SCS is: "<<scs; 
} 

int main() 
{ 
 char X[]="HELLO"; 
 char Y[]="GEEK"; 
 int m=strlen(X); 
 int n=strlen(Y); 
 scs(X,Y,m,n); 
 return 0; 
} 