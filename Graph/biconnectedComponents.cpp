/* To find biconnected components in a given graph (A biconnected component of a graph is a maximally connected subgraph that cannot be broken into disconnected 
pieces by deleting any single node)*/
 
#include<bits/stdc++.h>
using namespace std;

#define NIL -1 

int c=0; 

// Function to add an edge
void addEdge(int v, int w,list<int> adj[]) 
{ 
 adj[v].push_back(w); 
 adj[w].push_back(v); 
}

// Function to find the biconnected components
void BCCUtil(int u,int disc[],int low[],list<pair<int,int>>* st,int parent[],list<int> adj[]) 
{ 
 static int time=0; 
 disc[u]=low[u]=++time; 
 int children=0; 
 list<int>::iterator i; 
 for(i=adj[u].begin();i!=adj[u].end();i++)
 { 
  int v=*i;  
  if(disc[v]==-1)
  {  
   children++; 
   parent[v]=u; 
   st->push_back({u,v}); 
   BCCUtil(v,disc,low,st,parent,adj); 
   low[u]=min(low[u],low[v]); 
   if((disc[u]==1 && children>1) || (disc[u]>1 && low[v]>=disc[u])) 
   { 
    while(st->back().first!=u || st->back().second!=v)
	{ 
	 cout<<st->back().first<<"--"<<st->back().second<<" "; 
     st->pop_back(); 
	} 
	cout<<st->back().first<<"--"<<st->back().second; 
    st->pop_back(); 
	cout<<'\n'; 
	c++; 
   } 
  } 
  else 
   if(v!=parent[u]) 
   { 
    low[u]=min(low[u],disc[v]); 
    if(disc[v]<disc[u]) 
	 st->push_back({u,v}); 
   } 
 } 
} 

// Function to implement DFS 
void BCC(int V,int E,list<int> adj[]) 
{ 
 int* disc=new int[V]; 
 int* low=new int[V]; 
 int* parent=new int[V]; 
 list<pair<int,int>>* st=new list<pair<int,int>>[E]; 
 for(int i=0;i<V;i++) 
 { 
  disc[i]=NIL; 
  low[i]=NIL; 
  parent[i] = NIL; 
 } 
 for(int i=0;i<V;i++) 
 { 
  if(disc[i]==NIL) 
   BCCUtil(i,disc,low,st,parent,adj); 
  int j=0; 
  while(st->size()>0) 
  { 
   j=1; 
   cout<<st->back().first<<"--"<<st->back().second<<" "; 
   st->pop_back(); 
  } 
  if(j==1) 
  { 
   cout<<'\n'; 
   c++; 
  } 
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
 BCC(v,e,adj);
 cout<<"No of biconnected components are: "<<c;
 return 0; 
}
