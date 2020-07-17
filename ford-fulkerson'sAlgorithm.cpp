// To implement Ford-Fulkerson algorithm to find the maximum flow
 
#include<bits/stdc++.h> 
using namespace std; 

// Function to find a path between source to sink
bool bfs(int rGraph[][100],int s,int t,int parent[],int ver) 
{ 
 bool visited[ver]; 
 memset(visited, 0, sizeof(visited)); 
 queue <int> q; 
 q.push(s); 
 visited[s]=true; 
 parent[s]=-1; 
 while(!q.empty()) 
 { 
  int u=q.front(); 
  q.pop(); 
  for(int v=0;v<ver;v++) 
  { 
   if(visited[v]==false && rGraph[u][v]>0) 
   { 
    q.push(v); 
	parent[v]=u; 
	visited[v]=true; 
   } 
  } 
 } 
 return(visited[t]==true); 
} 

// Function to implement Ford-Fulkerson algorithm 
int fordFulkerson(int graph[][100],int s,int t,int ver) 
{ 
 int u,v; 
 int rGraph[100][100];  
 for(u=0;u<ver;u++) 
  for(v=0;v<ver;v++) 
   rGraph[u][v]=graph[u][v]; 
 int parent[ver]; 
 int max_flow=0;  
 while(bfs(rGraph,s,t,parent,ver)) 
 { 
  int path_flow=INT_MAX; 
  for(v=t;v!=s;v=parent[v]) 
  { 
   u=parent[v]; 
   path_flow=min(path_flow,rGraph[u][v]); 
  } 
  for(v=t;v!=s;v=parent[v]) 
  { 
   u=parent[v]; 
   rGraph[u][v]-=path_flow; 
   rGraph[v][u]+=path_flow; 
  } 
  max_flow+=path_flow; 
 } 
 return max_flow; 
} 

int main() 
{ 
 int v,e;
 cin>>v>>e;
 int graph[100][100]={0};
 int src,dest,weight;
 for(int i=0;i<e;i++)
 {
  cin>>src>>dest>>weight;
  graph[src][dest]=weight;
 }
 int s,t;
 cin>>s>>t;
 int max_flow=fordFulkerson(graph,s,t,v);
 cout<<max_flow;
 return 0; 
} 
