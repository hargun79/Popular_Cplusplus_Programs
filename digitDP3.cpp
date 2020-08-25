// To implement digit DP to find total number of numbers in a range whose sum of digits is divisible by a given number

#include<bits/stdc++.h>
using namespace std; 

#define ull unsigned long long int

ull dp[20][180][2],ks; 

// Function to implement digit DP 
ull digitSum(ull idx,ull sum,ull tight,string &digit) 
{ 
 if(idx==-1)
 { 
  if(sum%ks==0)
   return 1;
  else
   return 0;  
 }
 if(dp[idx][sum][tight]!=-1 && tight!=1) 
  return dp[idx][sum][tight]; 
 ull ret=0; 
 ull k=(tight)?(digit[idx]-'0'):9; 
 for(ull i=0;i<=k;i++) 
 { 
  ull newTight=((digit[idx]-'0')==i)?tight:0; 
  ret+=digitSum(idx-1,sum+i,newTight,digit); 
 } 
 if(!tight) 
  dp[idx][sum][tight]=ret; 
 return ret; 
} 

// Function to claculate the total number of numbers having sum of their digits divisible by a number
int rangeDigitSum(string a,string b) 
{ 
 memset(dp,-1,sizeof(dp)); 
 reverse(a.begin(),a.end());
 ull ans1=digitSum(a.size()-1,0,1,a); 
 reverse(b.begin(),b.end());
 ull ans2=digitSum(b.size()-1,0,1,b); 
 return (ans2-ans1); 
} 

int main() 
{ 
 string a,b; 
 cin>>a>>b>>ks;
 cout<<rangeDigitSum(a,b)<<'\n'; 
 return 0; 
}
