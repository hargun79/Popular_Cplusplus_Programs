// To implement segment tree with lazy propagation with multiple update queries

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pb push_back
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)

ll M=pow(10,9)+7;
ll sum[4*100010];
ll k[4*100010];
ll d[4*100010];
ll arr[100010];

void cal()
{
 for(ll i=0;i<4*100010;++i)
 {
  sum[i]=0;
  d[i]=0;
  k[i]=1;
 }
}

void build_tree(ll node,ll a,ll b)
{
 if(a>b)
  return; 
 if(a==b)
 {
  sum[node]=arr[a]%M;
  return ;
 }
 build_tree(2*node,a,(a+b)/2);
 build_tree(2*node+1,(a+b)/2+1,b);
 sum[node]=(sum[2*node]+sum[2*node+1])%M;
}

void update(ll node,ll a,ll b,ll i,ll j,ll v,ll f)
{
 if((k[node]!=1)||(d[node]!=0))
 {
  sum[node]=( (sum[node]*k[node])%M + ((b-a+1)*d[node])%M )%M;
  if(a!=b)
  {
   k[2*node]=(k[node]*k[2*node])%M;
   k[2*node+1]=(k[node]*k[2*node+1])%M;
   d[2*node]=((k[node]*d[2*node])%M+d[node])%M;
   d[2*node+1]=((k[node]*d[2*node+1])%M+d[node])%M;
  }
  k[node]=1;
  d[node]=0;
 }
 if(i>b||j<a||a>b)
  return;
 if(a>=i&&b<=j)
 {
  if(f==1)
  {
   sum[node]=(sum[node]+(v*(b-a+1))%M)%M;
   if(a!=b)
   {
    d[2*node]=(d[2*node]+v)%M;
	d[2*node+1]=(d[2*node+1]+v)%M;
   }
  }
  else 
   if(f==2)
  {
   sum[node]=(v*sum[node])%M;
   if(a!=b)
   {
    k[2*node]=(v*k[2*node])%M;
	k[2*node+1]=(v*k[2*node+1])%M;
	d[2*node]=(v*d[2*node])%M;
	d[2*node+1]=(v*d[2*node+1])%M;
   }
  }
  else 
   if(f==3)
   {
    sum[node]=(v*(b-a+1))%M;
	if(a!=b)
	{
	 k[2*node]=0;
	 k[2*node+1]=0;
	 d[2*node]=v;
	 d[2*node+1]=v;
    }
   }
  return;
 }
 update(2*node,a,(a+b)/2,i,j,v,f);
 update(2*node+1,(a+b)/2+1,b,i,j,v,f);
 sum[node]=(sum[2*node]+sum[node*2+1])%M;
}

ll query(ll node,ll a,ll b,ll i,ll j)
{
 if(i>b||j<a||a>b)
  return 0;
 if((k[node]!=1)||(d[node]!=0))
 {
  sum[node]=( (sum[node]*k[node])%M + ((b-a+1)*d[node])%M )%M;
  if(a!=b)
  {
   k[2*node]=(k[node]*k[2*node])%M;
   k[2*node+1]=(k[node]*k[2*node+1])%M;
   d[2*node]=((k[node]*d[2*node])%M+d[node])%M;
   d[2*node+1]=((k[node]*d[2*node+1])%M+d[node])%M;
  }
  k[node]=1;
  d[node]=0;
 }
 if(a>=i&&b<=j)
  return sum[node];
 return (query(2*node,a,(a+b)/2,i,j)+query(2*node+1,(a+b)/2+1,b,i,j))%M;
}

int main()
{
 cal();
 ll n,q;
 cin>>n>>q;
 for(ll i=1;i<=n;++i)
  cin>>arr[i];
 build_tree(1,1,n);
 while(q--)
 {
  ll i,x,y,v;
  cin>>i>>x>>y;
  if(i!=4)
  {
   cin>>v;
   update(1,1,n,x,y,v,i);
  }
  else
  {
   ll ans=(query(1,1,n,x,y)+M)%M;
   cout<<ans<<'\n';	
  }
 }
 return 0;
}
