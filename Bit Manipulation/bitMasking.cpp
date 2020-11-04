// To find sum of every subsequence of the array.

#include<bits/stdc++.h>
using namespace std;

int a[10000];
 
int main()
{
 int c=0;
 int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++) 
  cin>>arr[i];
 int totalSubsets=1<<n;
 for(int subset=0;subset<totalSubsets;subset++)
 {
  int sum=0;
  for(int mask=0;mask<n;mask++)
   if(subset&(1<<mask)) 
    sum+=arr[mask];
  a[c++]=sum;
 }
 for(int i=0;i<c;i++)
  cout<<a[i]<<" ";
 return 0;
}
