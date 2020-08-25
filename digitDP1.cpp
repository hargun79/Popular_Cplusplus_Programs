// To implement digit DP to find the sum of all the digits of all numbers in a certain range

#include<bits/stdc++.h>
using namespace std; 

#define ull unsigned long long int

ull dp[20][180][2]; 

// Function to store all the digits of a number 
ull getDigits(ull x,vector<ull> &digit) 
{ 
 while(x) 
 { 
  digit.push_back(x%10); 
  x/=10; 
 } 
} 

// Function to implement digit DP 
ull digitSum(ull idx,ull sum,ull tight,vector<ull> &digit) 
{ 
 if(idx==-1) 
  return sum; 
 if(dp[idx][sum][tight]!=-1 && tight!=1) 
  return dp[idx][sum][tight]; 
 ull ret=0; 
 ull k=(tight)?digit[idx]:9; 
 for(ull i=0;i<=k;i++) 
 { 
  ull newTight=(digit[idx]==i)?tight:0; 
  ret+=digitSum(idx-1,sum+i,newTight,digit); 
 } 
 if(!tight) 
  dp[idx][sum][tight]=ret; 
 return ret; 
} 

// Function to claculate the sum 
int rangeDigitSum(ull a,ull b) 
{ 
 memset(dp,-1,sizeof(dp)); 
 vector<ull> digitA; 
 getDigits(a-1,digitA); 
 ull ans1=digitSum(digitA.size()-1,0,1,digitA); 
 vector<ull> digitB;  
 getDigits(b,digitB); 
 ull ans2=digitSum(digitB.size()-1,0,1,digitB); 
 return (ans2-ans1); 
} 

int main() 
{ 
 ull a,b; 
 cin>>a>>b;
 cout<<rangeDigitSum(a,b)<<'\n'; 
 return 0; 
} 
