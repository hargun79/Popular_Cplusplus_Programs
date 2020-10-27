// To find articulation points in an undirected graph (An articulation point (or cut vertex) is defined as a vertex which, when removed along with associated edges, makes the graph disconnected (or more precisely, increases the number of connected components in the graph).)
 
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

// Function to find articulation points
void APUtil(int u,bool visited[],int disc[],int low[],int parent[],bool ap[],list<int> adj[]) 
{ 
 static int time=0; 
 int children=0; 
 visited[u]=true; 
 disc[u]=low[u]=++time; 
 list<int>::iterator i; 
 for(i=adj[u].begin();i!=adj[u].end();i++) 
 { 
  int v=*i; 
  if(!visited[v]) 
  { 
   children++; 
   parent[v]=u; 
   APUtil(v,visited,disc,low,parent,ap,adj); 
   low[u]=min(low[u],low[v]); 
   if(parent[u]==NIL && children>1) 
    ap[u]=true; 
   if(parent[u]!=NIL && low[v]>=disc[u]) 
	ap[u]=true; 
  } 
  else 
   if(v!=parent[u]) 
    low[u]=min(low[u],disc[v]); 
 } 
} 

// Function to implement DFS
void AP(int V,list<int> adj[]) 
{ 
 bool *visited=new bool[V]; 
 int *disc=new int[V]; 
 int *low=new int[V]; 
 int *parent=new int[V]; 
 bool *ap=new bool[V];  
 for(int i=0;i<V;i++) 
 { 
  parent[i]=NIL; 
  visited[i]=false; 
  ap[i]=false; 
 } 
 for(int i=0;i<V;i++) 
  if(visited[i]==false) 
   APUtil(i,visited,disc,low,parent,ap,adj); 
 for(int i=0;i<V;i++) 
  if(ap[i]==true) 
   cout<<i<<" "; 
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
 AP(v,adj);
 return 0; 
} 
