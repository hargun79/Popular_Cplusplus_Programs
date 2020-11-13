// To find diameter of binary/generic tree

#include <bits/stdc++.h>
using namespace std;
 
const int N=1E5+5;
bool vis[N];
vector<int> tree[N];
 
int leaf=-1;
int total=0;
 
void dfs(int src,int len) 
{
 vis[src]=true;
 if(len>total) 
 {
  total=len;
  leaf=src;
 }
 for(auto i:tree[src]) 
  if(!vis[i])
   dfs(i,len+1);
}
 
int main() 
{
 int n;
 cin>>n;
 int a,b;
 for(int i=0;i<n;i++) 
 {
  cin>>a>>b;
  tree[a].push_back(b);
  tree[b].push_back(a);
 }
 dfs(1,1);
 cout<<leaf<<' ';
 total=0;
 memset(vis,false,sizeof vis);
 dfs(leaf,1);
 cout<<leaf;
 return 0;
}
