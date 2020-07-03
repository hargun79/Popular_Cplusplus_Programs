// To implement Djikstra's Algorithm
 
#include<bits/stdc++.h> 
using namespace std;
 
#define INF 0x3f3f3f3f 

typedef pair<int,int> iPair; 

// Function to add an edge 
void addEdge(vector <pair<int,int>> adj[],int u,int v,int wt) 
{ 
 adj[u].push_back(make_pair(v,wt)); 
 adj[v].push_back(make_pair(u,wt)); 
} 


// Function to implement Djikstra's algorithm 
void shortestPath(vector<pair<int,int> > adj[],int V,int src) 
{ 
 priority_queue<iPair,vector <iPair>,greater<iPair>> pq; 
 vector<int> dist(V,INF); 
 pq.push(make_pair(0,src)); 
 dist[src]=0; 
 while(!pq.empty()) 
 { 
  int u=pq.top().second; 
  pq.pop(); 
  for(auto x:adj[u]) 
  { 
   int v=x.first; 
   int weight=x.second; 
   if(dist[v]>dist[u]+weight) 
   { 
    dist[v]=dist[u]+weight; 
    pq.push(make_pair(dist[v],v)); 
   } 
  } 
 } 
 cout<<"Vertex Distance from Source\n"; 
 for(int i=0;i<V;i++) 
  cout<<i<<'\t'<<dist[i]<<'\n'; 
} 

int main() 
{ 
 int V,E;
 cin>>V>>E; 
 vector<iPair> adj[V];
 int u,v,weight;
 for(int i=0;i<E;i++)
 {
  cin>>u>>v>>weight;
  addEdge(adj,u,v,weight);
 }  
 shortestPath(adj,V,0); 
 return 0; 
} 
