bool flag=false;
    
void dfs(vector<int> adj[],bool *vis,int v,int p)
{
 vis[v]=true;
 for(auto u:adj[v])
  if(!vis[u])
   dfs(adj,vis,u,v);
  else
  {
   if(u!=p)
    flag=true;
  }
}
    
//Function to detect cycle in an undirected graph.
bool isCycle(int V, vector<int>adj[])
{
 flag=false;
 bool vis[V];
 memset(vis,false,sizeof vis);
 for(int i=0;i<V;i++)
  if(!vis[i])
   dfs(adj,vis,i,-1);
 return flag;
}
