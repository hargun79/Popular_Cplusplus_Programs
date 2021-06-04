// To implement palindrome partitionong problem

#include<bits/stdc++.h>
using namespace std;

int dp[500][500];

// Function to check if a given string is palindrome or not
int isPallindrome(string s,int i,int j)
{
 while(i<=j)
 {
  if(s[i]!=s[j])
   return 0;
  i++;
  j--;
 }
 return 1;
}

// Function to implement palindromic partitioning
int palindromicPartition(string str,int i,int j)
{
 if(i>=j)
  return 0;
 if(dp[i][j]!=-1)
  return dp[i][j];
 if(isPallindrome(str,i,j))
  return 0;
 int mn=INT_MAX;
 for(int k=i;k<j;k++)
 {
  int cost=1+palindromicPartition(str,i,k)+palindromicPartition(str,k+1,j);
  mn=min(mn,cost);
 }   
 dp[i][j]=mn;
 return dp[i][j];
}

int main()
{
 string str="ababbbabbababa";
 memset(dp,-1,sizeof(dp));
 cout<<palindromicPartition(str,0,str.length()-1);
 return 0;
}