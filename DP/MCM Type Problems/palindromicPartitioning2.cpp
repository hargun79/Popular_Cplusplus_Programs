// To implement palindrome partitionong problem in O(n^2) time

#include<bits/stdc++.h>
using namespace std;

int t[500][500];

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

// Recursive function to implement palindromic partitioning
int PP(string str,int i,int j)
{
 if(t[i][j]!=-1)
  return t[i][j];
 if(i>=j || isPallindrome(str,i,j))
 {
  t[i][j]=0;
  return 0;
 }
 int ans=INT_MAX,temp;
 for(int k=i;k<j;k++)
 {
  if(isPallindrome(str,i,k))
  {
   temp=1+PP(str,k+1,j);
   ans=min(ans,temp);
  }
 }
 return t[i][j]=ans;
}

// Function to implement palindromic partitioning
int palindromicPartition(string str)
{
 memset(t,-1,sizeof(t));
 return PP(str,0,str.length()-1);
}

int main()
{
 string str="ababbbabbababa";
 cout<<palindromicPartition(str);
 return 0;
}