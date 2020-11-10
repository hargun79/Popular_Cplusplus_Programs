// To implement Bellman-Ford's Algorithm

#include<bits/stdc++.h> 
using namespace std;

// Function to print the distance 
void printArr(int dist[],int n) 
{ 
 printf("Vertex Distance from Source\n"); 
 for(int i=0;i<n;i++) 
  cout<<i<<" "<<dist[i]<<'\n'; 
} 

// Function to implement Bellman-Ford's algorithm
void BellmanFord(pair<int,pair<int,int>> p[],int src,int V,int E) 
{  
 int dist[V]; 
 for(int i=0;i<V;i++) 
  dist[i]=INT_MAX; 
 dist[src]=0; 
 for(int i=1;i<=V-1;i++)
 { 
  for(int j=0;j<E;j++) 
  { 
   int u=p[j].first; 
   int v=p[j].second.first; 
   int weight=p[j].second.second; 
   if(dist[u]!=INT_MAX && dist[u]+weight<dist[v]) 
    dist[v]=dist[u]+weight; 
  } 
 } 
 for(int i=0;i<E;i++) 
 { 
  int u=p[i].first; 
  int v=p[i].second.first; 
  int weight=p[i].second.second; 
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
 int V,E,src,dest,weight;
 cin>>V>>E;  
 pair<int,pair<int,int>> p[E]; 
 for(int i=0;i<E;i++)
 {
  cin>>src>>dest>>weight;
  src--;
  dest--;
  p[i]=make_pair(src,make_pair(dest,weight));
 }
 BellmanFord(p,2,V,E); 
 return 0; 
}
