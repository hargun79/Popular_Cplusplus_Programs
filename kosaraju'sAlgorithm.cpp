// To implement Kosaraju's algorithm (i.e. find all the strongly connected components in O(V+E) time)

/*A directed graph is strongly connected if there is a path between all pairs of vertices. A strongly connected component (SCC) of a directed graph is a maximal strongly 
connected subgraph.*/

#include<bits/stdc++.h>
using namespace std; 

class Graph 
{ 
 int V;  
 list<int> *adj;  
 void fillOrder(int v,bool visited[],stack<int> &Stack); 
 void DFSUtil(int v,bool visited[]); 
 public:Graph(int V); 
	    void addEdge(int v, int w); 
        void printSCCs(); 
        Graph getTranspose(); 
}; 

Graph::Graph(int V) 
{ 
 this->V=V; 
 adj=new list<int>[V]; 
} 

// Function to print according to DFS 
void Graph::DFSUtil(int v,bool visited[]) 
{ 
 visited[v]=true; 
 cout<<v<<" "; 
 list<int>::iterator i; 
 for(i=adj[v].begin();i!=adj[v].end();i++) 
  if(!visited[*i]) 
   DFSUtil(*i,visited); 
} 

// Function to get the transpose graph
Graph Graph::getTranspose() 
{ 
 Graph g(V); 
 for(int v=0;v<V;v++) 
 { 
  list<int>::iterator i; 
  for(i=adj[v].begin();i!=adj[v].end();i++) 
   g.adj[*i].push_back(v);  
 } 
 return g; 
} 

// FUnction to add an edge
void Graph::addEdge(int v,int w) 
{ 
 adj[v].push_back(w);  
} 

// Function to build the stack by performing DFS
void Graph::fillOrder(int v,bool visited[],stack<int> &Stack) 
{ 
 visited[v]=true; 
 list<int>::iterator i; 
 for(i=adj[v].begin();i!=adj[v].end();i++) 
  if(!visited[*i]) 
   fillOrder(*i,visited,Stack); 
 Stack.push(v); 
} 

// Function to implement Kosaraju's algorithm 
void Graph::printSCCs() 
{ 
 stack<int> Stack; 
 bool *visited=new bool[V]; 
 for(int i=0;i<V;i++) 
  visited[i]=false; 
 for(int i=0;i<V;i++) 
  if(visited[i]==false) 
   fillOrder(i, visited, Stack); 
 Graph gr=getTranspose(); 
 for(int i=0;i<V;i++) 
  visited[i]=false; 
 while(Stack.empty()==false) 
 { 
  int v=Stack.top(); 
  Stack.pop(); 
  if(visited[v]==false) 
  { 
   gr.DFSUtil(v,visited); 
   cout<<'\n'; 
  } 
 } 
} 

int main() 
{ 
 int v,e;
 cin>>v>>e;
 Graph g(v);
 int src,dest;
 for(int i=0;i<e;i++)
 {
  cin>>src>>dest;
  g.addEdge(src,dest);
 }
 g.printSCCs();
 return 0; 
} 
