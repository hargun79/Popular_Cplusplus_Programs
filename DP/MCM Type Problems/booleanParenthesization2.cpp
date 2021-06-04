// To implement boolean parenthesization problem i.e. find the number of ways in which expression evaluates to true

#include <bits/stdc++.h>
using namespace std;

int dp[201][201][2];

int countUtil(int i,int j,string S,int istrue) 
{
 if(i>j)
  return dp[i][j][istrue]=0;
 if(i==j) 
 {
  if(istrue==1)
   return dp[i][j][istrue]=(S[i]=='T')?1:0;
  else
   return dp[i][j][istrue]=(S[i]=='F')?1:0;
 }
 if(dp[i][j][istrue]!=-1)
  return dp[i][j][istrue];
 int ans=0;
 for(int k=i+1;k<j;k+=2) 
 {
  int lt=dp[i][k-1][1];
  int rt=dp[k+1][j][1];
  int lf=dp[i][k-1][0];
  int rf=dp[k+1][j][0];
  if(lt==-1) 
  {
   lt=countUtil(i,k-1,S,1);
   dp[i][k-1][1]=lt;
  }
  if(rt==-1) 
  {
   rt=countUtil(k+1,j,S,1);
   dp[k+1][j][1]=rt;   
  }
  if(lf==-1) 
  {
   lf=countUtil(i,k-1,S,0);
   dp[i][k-1][0]=lf; 
  }
  if(rf==-1) 
  {
   rf=countUtil(k+1,j,S,0);
   dp[k+1][j][0]=rf;
  }
  if(S[k]=='|') 
  {
   if(istrue==1)
    ans+=lt*rt+lt*rf+rt*lf ;
   else
    ans+=lf*rf;
  }
  else 
   if(S[k]=='&') 
   {
    if(istrue==1)
     ans+=lt*rt;
    else
     ans+=lt*rf+rt*lf+lf*rf;
   }
  else 
   if(S[k]=='^') 
   {
    if(istrue==1)
     ans+=lt*rf+rt*lf;
    else
     ans+=lt*rt+lf*rf;
   }
 }
 return dp[i][j][istrue]=ans;
}

int main() 
{
 string X; 
 cin >> X;
 memset(dp, -1, sizeof(dp));
 cout<<countUtil(0,X.length()-1,X,true)<<'\n';
 return 0;
}