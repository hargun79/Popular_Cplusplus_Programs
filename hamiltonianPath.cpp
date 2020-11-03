/* To find all the Hamiltonian paths in the given graph (It is a graph path between two vertices of a graph that visits each vertex exactly once. If a Hamiltonian path exists 
whose endpoints are adjacent, then the resulting graph cycle is called a Hamiltonian cycle) */

#include<bits/stdc++.h> 
using namespace std;

typedef pair<int,int> iPair;

int c=0;

#define NIL -1

// Function to add an edge
void addEdge(int v, int w,list<int> adj[]) 
{ 
 adj[v].push_back(w); 
 adj[w].push_back(v); 
}

// Function to find the Hamiltonian paths
void printAllHamiltonianPaths(int v,vector<bool> visited,vector<int> &path,int N,list<int> adj[])
{
 if(path.size()==N)
 {
  c++;
  for(int i:path)
   cout<<i<<" ";
  cout<<'\n';
  return;
 }
 for(int w:adj[v])
 {
  if(!visited[w])
  {
   visited[w]=true;
   path.push_back(w);
   printAllHamiltonianPaths(w,visited,path,N,adj);
   visited[w]=false;
   path.pop_back();
  }
 }
}

int main()
{
 int v,e;
 cin>>v>>e;
 list<int> adj[v];
 vector<bool> visited(v);
 visited[0]=true;
 vector<int> path;
 path.push_back(0);
 int src,dest;
 for(int i=0;i<e;i++)
 {
  cin>>src>>dest;
  addEdge(src,dest,adj);
 }
 printAllHamiltonianPaths(0,visited,path,v,adj);
 if(c==0)
  cout<<"No Hamiltonian path exist";
 return 0;
}
