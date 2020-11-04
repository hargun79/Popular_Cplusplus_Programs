// To implement Dinic's algorithm (given two vertices source ‘s’ and sink ‘t’ in the graph, find the maximum possible flow from s to t)
 
#include<bits/stdc++.h> 
using namespace std; 

struct Edge 
{ 
 int v; 
 int flow;  
 int C;  
 int rev ;  
}; 

class Graph 
{ 
 int V; 
 int *level; 
 vector<Edge> *adj; 
 public:Graph(int V) 
	{ 
	 adj=new vector<Edge>[V]; 
	 this->V=V; 
	 level=new int[V]; 
	} 
        //Function to add edge to the graph 
	void addEdge(int u,int v,int C) 
	{ 
	 Edge a{v,0,C,adj[v].size()}; 
         Edge b{u,0,0,adj[u].size()}; 
         adj[u].push_back(a); 
	 adj[v].push_back(b); 
	} 
        bool BFS(int s,int t); 
	int sendFlow(int s,int flow,int t,int ptr[]); 
	int DinicMaxflow(int s,int t); 
}; 

// Function to assign levels and check if more flow can be sent 
bool Graph::BFS(int s,int t) 
{ 
 for(int i=0;i<V;i++) 
  level[i]=-1; 
 level[s]=0; 
 list<int> q; 
 q.push_back(s); 
 vector<Edge>::iterator i; 
 while(!q.empty()) 
 { 
  int u=q.front(); 
  q.pop_front(); 
  for(i=adj[u].begin();i!=adj[u].end();i++) 
  { 
   Edge &e=*i; 
   if(level[e.v]<0 && e.flow<e.C) 
   { 
    level[e.v]=level[u]+1; 
    q.push_back(e.v); 
   } 
  } 
 } 
 return level[t]<0?false:true; 
} 

// Function to send the flow after BFS has founded the flow
int Graph::sendFlow(int u,int flow,int t,int start[]) 
{ 
 if(u==t) 
  return flow; 
 for(;start[u]<adj[u].size();start[u]++) 
 { 
  Edge &e=adj[u][start[u]]; 
  if(level[e.v]==level[u]+1 && e.flow<e.C) 
  { 
   int curr_flow=min(flow,e.C-e.flow); 
   int temp_flow=sendFlow(e.v,curr_flow,t,start); 
   if(temp_flow>0) 
   { 
    e.flow+=temp_flow; 
    adj[e.v][e.rev].flow-=temp_flow; 
    return temp_flow; 
   } 
  } 
 } 
 return 0; 
} 

// Function to return the maximum flow 
int Graph::DinicMaxflow(int s,int t) 
{ 
 if(s==t) 
  return -1; 
 int total=0;  
 while(BFS(s,t)==true) 
 { 
  int *start=new int[V+1]; 
  while(int flow=sendFlow(s,INT_MAX,t,start)) 
   total+=flow; 
 } 
 return total; 
} 

int main() 
{ 
 int v,e;
 cin>>v>>e;
 Graph g(v);
 int src,dest,capacity;
 for(int i=0;i<e;i++)
 {
  cin>>src>>dest>>capacity;
  g.addEdge(src,dest,capacity);
 }
 int s,t;
 cin>>s>>t;
 int max_flow=g.DinicMaxflow(s,t);
 cout<<max_flow;
 return 0; 
} 
