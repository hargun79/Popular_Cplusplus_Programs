// To find maximum cost from root node to leaf node in a weighted generic tree

#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> mp;
int maxi=0;

void dfs(int i,list<int> adj[],int vis[],int counter)
{
 vis[i]=1;
 maxi=max(maxi,counter);
 for(int u:adj[i])
  if(!vis[u])
   dfs(u,adj,vis,counter+mp[{i,u}]);
}

int main()
{
 int n;
 cin>>n;
 int src,dest,wt;
 list<int> adj[n+1];
 for(int i=0;i<n-1;i++)
 {
  cin>>src>>dest>>wt;
  mp[{src,dest}]=wt;
  mp[{dest,src}]=wt;
  adj[src].push_back(dest);
  adj[dest].push_back(src);
 }
 int counter=0;
 int vis[n]={0};
 dfs(0,adj,vis,counter);
 cout<<maxi<<'\n';
 return 0;
}
