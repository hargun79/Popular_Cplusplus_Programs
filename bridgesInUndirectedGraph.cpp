// To find bridges in an undirected graph (A bridge is defined as an edge which, when removed, makes the graph disconnected)
 
#include<bits/stdc++.h> 
using namespace std;

typedef pair<int,int> iPair;

#define NIL -1

// Function to add an edge
void addEdge(int v, int w,list<int> adj[]) 
{ 
 adj[v].push_back(w); 
 adj[w].push_back(v); 
}  

// Function to find the bridges
void bridgeUtil(int u,bool visited[],int disc[],int low[],int parent[],list<int> adj[]) 
{ 
 static int time=0; 
 visited[u]=true; 
 disc[u]=low[u]=++time; 
 list<int>::iterator i; 
 for(i=adj[u].begin();i!=adj[u].end();i++) 
 { 
  int v=*i; 
  if(!visited[v]) 
  {  
   parent[v]=u; 
   bridgeUtil(v,visited,disc,low,parent,adj); 
   low[u]=min(low[u],low[v]); 
   if(low[v]>disc[u]) 
	cout<<u<<" "<<v<<'\n'; 
  } 
  else 
   if(v!=parent[u]) 
	low[u]=min(low[u],disc[v]); 
 } 
} 

// Function for initialization and dfs
void bridge(int V,list<int> adj[]) 
{ 
 bool *visited=new bool[V]; 
 int *disc=new int[V]; 
 int *low=new int[V]; 
 int *parent=new int[V]; 
 for(int i=0;i<V;i++) 
 { 
  parent[i]=NIL; 
  visited[i] = false; 
 } 
 for(int i=0;i<V;i++) 
  if(visited[i]==false) 
   bridgeUtil(i,visited,disc,low,parent,adj); 
} 

int main() 
{ 
 int v,e;
 cin>>v>>e;
 list<int> adj[v];
 int src,dest;
 for(int i=0;i<e;i++)
 {
  cin>>src>>dest;
  addEdge(src,dest,adj);
 }
 bridge(v,adj);
 return 0; 
}
