// To count the total number of divisors of p and q in the array for t queries

#include<bits/stdc++.h>
using namespace std;

#define lli long long int

lli *ans=NULL;

void countSieve(lli arr[],lli n) 
{ 
 lli MAX = 200000; 
 lli cnt[MAX + 1]; 
 ans=new lli[MAX + 1]; 
 memset(cnt,0,sizeof(cnt)); 
 memset(ans,0,(MAX+1)*sizeof(int)); 
 for(lli i=0;i<n;++i) 
  ++cnt[arr[i]]; 
 for(lli i=1;i<=MAX;++i) 
  for(lli j=i;j<=MAX;j+=i) 
   ans[i]+=cnt[j]; 
 return; 
}

int main()
{
 lli n;
 cin>>n;
 lli arr[n];
 for(lli i=0;i<n;i++)
  cin>>arr[i];
 countSieve(arr,n); 
 lli t;
 cin>>t;
 lli p,q;
 for(lli i=0;i<t;i++)
 {
  cin>>p>>q;
  if(p==1 || q==1)
  {
   cout<<n<<'\n';
   continue;
  }
  lli mul=p*q;
  lli gcd=__gcd(p,q);
  lli lcm=mul/gcd;
  if(lcm<=200000)
   cout<<ans[p]+ans[q]-ans[lcm]<<'\n';
  else
   cout<<ans[p]+ans[q]<<'\n'; 
 } 
 return 0;
}
