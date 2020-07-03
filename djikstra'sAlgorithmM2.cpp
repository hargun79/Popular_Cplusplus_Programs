// To implement Djikstra's algorithm
 
#include<bits/stdc++.h> 
using namespace std;
 
# define INF 0x3f3f3f3f 

typedef pair<int, int> iPair; 

class Graph 
{ 
 int V;
 list<pair<int, int>> *adj; 
 public:Graph(int V); 
        void addEdge(int u,int v,int w); 
        void shortestPath(int s); 
}; 

// Function to initialize the graph
Graph::Graph(int V) 
{ 
 this->V=V; 
 adj=new list<iPair>[V]; 
} 

// Function to add an edge
void Graph::addEdge(int u,int v,int w) 
{ 
 adj[u].push_back(make_pair(v,w)); 
 adj[v].push_back(make_pair(u,w)); 
} 

// Function to implement Djikstra's algorithm
void Graph::shortestPath(int src) 
{ 
 priority_queue<iPair,vector<iPair>,greater<iPair>> pq; 
 vector<int> dist(V,INF); 
 pq.push(make_pair(0,src)); 
 dist[src]=0; 
 while(!pq.empty()) 
 { 
  int u=pq.top().second; 
  pq.pop(); 
  list<pair<int,int>>::iterator i; 
  for(i=adj[u].begin();i!=adj[u].end();i++) 
  { 
   int v=(*i).first; 
   int weight=(*i).second; 
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
 Graph g(V);
 int u,v,weight;
 for(int i=0;i<E;i++)
 {
  cin>>u>>v>>weight;
  g.addEdge(u,v,weight);
 }  
 g.shortestPath(0); 
 return 0; 
} 
