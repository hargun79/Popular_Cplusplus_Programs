#include <bits/stdc++.h> 
using namespace std; 

// Function to add an edge to the graph 
void addEdge(int src,int dest,list<int> adj[]) 
{ 
 adj[src].push_back(dest); 
} 

// Function to print the required topological sort of the given graph 
void topologicalSort(int V,list<int> adj[]) 
{ 
 vector<int> in_degree(V,0); 
 for(int u=0;u<V;u++) 
 { 
  list<int>::iterator itr; 
  for(itr=adj[u].begin();itr!=adj[u].end();itr++) 
   in_degree[*itr]++; 
 } 
 multiset<int> s; 
 for(int i=0;i<V;i++) 
  if(in_degree[i]==0) 
   s.insert(i); 
 int cnt=0; 
 vector<int> top_order; 
 while(!s.empty()) 
 { 
  int u=*s.begin(); 
  s.erase(s.begin()); 
  top_order.push_back(u); 
  list<int>::iterator itr; 
  for(itr=adj[u].begin();itr!=adj[u].end();itr++) 
   if(--in_degree[*itr]==0) 
    s.insert(*itr); 
  cnt++; 
 } 
 if(cnt!=V) 
 { 
  cout<<-1; 
  return; 
 } 
 for(int i=0;i<top_order.size();i++)  
  cout<<top_order[i]+1<<" "; 
} 

int main() 
{ 
 int v,e,src,dest;
 cin>>v>>e;
 list<int> adj[v]; 
 for(int i=0;i<e;i++)
 {
  cin>>src>>dest;
  src--;
  dest--;
  addEdge(src,dest,adj);
 }
 topologicalSort(v,adj); 
 return 0; 
}
