// To implement topological sorting in a directed acyclic graph (It is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering)
 
#include<bits/stdc++.h> 
using namespace std; 

typedef pair<int,int> iPair;

#define NIL -1

// Function to add an edge
void addEdge(int v, int w,list<int> adj[]) 
{ 
 adj[v].push_back(w); 
}

// Function to implement DFS 
void topologicalSortUtil(int v,bool visited[],stack<int>& Stack,list<int> adj[]) 
{  
 visited[v]=true; 
 list<int>::iterator i; 
 for(i=adj[v].begin();i!=adj[v].end();i++) 
  if(!visited[*i]) 
   topologicalSortUtil(*i,visited,Stack,adj); 
 Stack.push(v); 
} 

// Function to do topological sorting
void topologicalSort(int v,list<int> adj[]) 
{ 
 stack<int> Stack; 
 bool* visited=new bool[v]; 
 for(int i=0;i<v;i++) 
  visited[i]=false; 
 for(int i=0;i<v;i++) 
  if(visited[i]==false) 
   topologicalSortUtil(i,visited,Stack,adj); 
 while(Stack.empty()==false) 
 { 
  cout<<Stack.top()<<" "; 
  Stack.pop(); 
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
 topologicalSort(v,adj);
 return 0; 
} 
