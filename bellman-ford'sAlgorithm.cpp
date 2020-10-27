// To implement Bellman-Ford's algorithm (Same as Djikstra's algo but works also for negative weights). 

#include <bits/stdc++.h> 
using namespace std;

struct Edge 
{ 
 int src,dest,weight; 
}; 

struct Graph 
{ 
 int V,E; 
 struct Edge* edge; 
}; 

struct Graph* createGraph(int V,int E) 
{ 
 struct Graph* graph=new Graph; 
 graph->V=V; 
 graph->E=E; 
 graph->edge=new Edge[E]; 
 return graph; 
} 

// Function to print the distance 
void printArr(int dist[],int n) 
{ 
 printf("Vertex Distance from Source\n"); 
 for(int i=0;i<n;i++) 
  cout<<i<<" "<<dist[i]<<'\n'; 
} 

// Function to implement Bellman-Ford's algorithm
void BellmanFord(struct Graph* graph,int src) 
{ 
 int V=graph->V; 
 int E=graph->E; 
 int dist[V]; 
 for(int i=0;i<V;i++) 
  dist[i]=INT_MAX; 
 dist[src]=0; 
 for(int i=1;i<=V-1;i++)
 { 
  for(int j=0;j<E;j++) 
  { 
   int u=graph->edge[j].src; 
   int v=graph->edge[j].dest; 
   int weight=graph->edge[j].weight; 
   if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]) 
    dist[v]=dist[u]+weight; 
  } 
 } 
 for(int i=0;i<E;i++) 
 { 
  int u=graph->edge[i].src; 
  int v=graph->edge[i].dest; 
  int weight=graph->edge[i].weight; 
  if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]) 
  { 
   cout<<"Graph contains negative weight cycle"; 
   return; 
  } 
 } 
 printArr(dist,V); 
 return; 
} 

int main() 
{ 
 int V,E;
 cin>>V>>E;  
 struct Graph* graph=createGraph(V,E); 
 graph->edge[0].src=0; 
 for(int i=0;i<E;i++)
  cin>>graph->edge[i].src>>graph->edge[i].dest>>graph->edge[i].weight; 
 BellmanFord(graph,0); 
 return 0; 
} 
