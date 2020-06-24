// To implement 0-1 BFS

#include<bits/stdc++.h> 
using namespace std; 
   
struct node 
{ 
 int to,weight; 
};  
  
// Function to implement 0-1 BFS
void zeroOneBFS(int src,int n,vector<node> edges[]) 
{ 
 int dist[n]; 
 for(int i=0;i<n;i++) 
  dist[i]=INT_MAX; 
 deque<int> Q; 
 dist[src]=0; 
 Q.push_back(src); 
 while(!Q.empty()) 
 { 
  int v=Q.front(); 
  Q.pop_front(); 
  for(int i=0;i<edges[v].size();i++) 
  { 
   if(dist[edges[v][i].to]>dist[v]+edges[v][i].weight) 
   { 
    dist[edges[v][i].to]=dist[v]+edges[v][i].weight; 
    if(edges[v][i].weight==0) 
     Q.push_front(edges[v][i].to); 
    else
     Q.push_back(edges[v][i].to); 
   } 
  } 
 } 
 for(int i=0;i<n;i++) 
  cout<<dist[i]<<" "; 
} 
  
// Function to add a edge to the graph
void addEdge(int u, int v, int wt, vector<node> edges[]) 
{ 
 edges[u].push_back({v, wt}); 
 edges[v].push_back({u, wt}); 
} 
  
int main() 
{ 
 int n,m,x,y;
 cin>>n>>m;
 vector<node> edges[n];
 for(int i=0;i<m;i++)
 {
  cin>>x>>y;
  x--;
  y--;
  addEdge(x,y,1,edges);
 }  
 zeroOneBFS(0,n,edges); 
 return 0; 
}
