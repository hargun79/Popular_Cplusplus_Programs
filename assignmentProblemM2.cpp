// To implement assignment problem

#include<bits/stdc++.h>
using namespace std;

int n,a[200][200],min1=INT_MAX,id[200];

int call(int per,int cur)
{
 int ans,newans,i;
 ans=INT_MAX;
 if(per==n-1)
  return a[per][cur];
 for(i=0;i<n;i++)
  if(id[i]!=1)
  {
   id[i]=1;
   newans=a[per][cur]+call(per+1,i);
   ans=min(newans,ans);
   id[i]=0;
  }
 return ans;
}

int main()
{
 cin>>n;
 int i,j;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++)
   cin>>a[i][j];
 for(i=0;i<n;i++)
  id[i]=0;
 for(i=0;i<n;i++)
 {
  id[i]=1;
  min1=min(min1,call(0,i));
  id[i]=0;
 }
 cout<<min1;
}
