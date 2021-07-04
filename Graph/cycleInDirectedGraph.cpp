// To check if a cycle is present in a graph or not

bool flag=false;
    
void dfs(vector<int> adj[],bool *vis,int V,int v,bool *vis2)
{
 vis[v]=true;
 vis2[v]=true;
 for(auto u:adj[v])
  if(!vis[u])
   dfs(adj,vis,V,u,vis2);
  else
   if(vis2[u])
    flag=true;
 vis2[v]=false;  
}
    
//Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) 
{
 flag=false;
 bool vis[V],vis2[V];
 memset(vis,false,sizeof vis);
 memset(vis2,false,sizeof vis2);
 for(int i=0;i<V;i++)
  if(!vis[i])
   dfs(adj,vis,V,i,vis2);
 return flag;  
}
