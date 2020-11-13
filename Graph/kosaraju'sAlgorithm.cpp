// To implement Kosaraju's algorithm (i.e. find all the strongly connected components in O(V+E) time)

/*A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly 
connected subgraph.*/

#include<bits/stdc++.h>
using namespace std; 

// Function to print according to DFS 
void DFSUtil(int v,bool visited[],list<int> adj[]) 
{ 
 visited[v]=true; 
 cout<<v<<" "; 
 list<int>::iterator i; 
 for(i=adj[v].begin();i!=adj[v].end();i++) 
  if(!visited[*i]) 
   DFSUtil(*i,visited,adj); 
} 

// Function to get the transpose graph
void getTranspose(list<int> adj[],int V,list<int> adj2[]) 
{  
 for(int v=0;v<V;v++) 
 { 
  list<int>::iterator i; 
  for(i=adj[v].begin();i!=adj[v].end();i++) 
   adj2[*i].push_back(v);  
 }  
} 

// FUnction to add an edge
void addEdge(int v,int w,list<int> adj[]) 
{ 
 adj[v].push_back(w);  
} 

// Function to build the stack by performing DFS
void fillOrder(int v,bool visited[],stack<int> &Stack,list<int> adj[]) 
{ 
 visited[v]=true; 
 list<int>::iterator i; 
 for(i=adj[v].begin();i!=adj[v].end();i++) 
  if(!visited[*i]) 
   fillOrder(*i,visited,Stack,adj); 
 Stack.push(v); 
} 

// Function to implement Kosaraju's algorithm 
void printSCCs(list<int> adj[],int V) 
{ 
 stack<int> Stack; 
 bool *visited=new bool[V]; 
 for(int i=0;i<V;i++) 
  visited[i]=false; 
 for(int i=0;i<V;i++) 
  if(visited[i]==false) 
   fillOrder(i,visited,Stack,adj); 
 list<int> adj2[V];
 getTranspose(adj,V,adj2); 
 for(int i=0;i<V;i++) 
  visited[i]=false; 
 while(Stack.empty()==false) 
 { 
  int v=Stack.top(); 
  Stack.pop(); 
  if(visited[v]==false) 
  { 
   DFSUtil(v,visited,adj2); 
   cout<<'\n'; 
  } 
 } 
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
 printSCCs(adj,v);
 return 0; 
}
