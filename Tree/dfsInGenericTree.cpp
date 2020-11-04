// To implement dfs in a generic tree

#include<bits/stdc++.h>
using namespace std;

void dfs(int v,vector<vector<int>> &adj)
{
 cout<<v<<" ";
 for(int i=0;i<adj[v].size();i++)
  dfs(adj[v][i],adj);
}

int main()
{
 int n,p;
 cin>>n;
 vector<vector<int>> adj(n+1); 
 for(int i=0;i<n-1;i++)
 {
  cin>>p;
  adj[p].push_back(i+2);
 }
 dfs(1,adj); 
 return 0;
}
