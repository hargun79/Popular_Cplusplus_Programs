// To find the number of connected components using DFS.

#include<bits/stdc++.h>
using namespace std;

vector <int> adj[100000];
bool visited[100000];

// Function to implement DFS
void dfs(int s) 
{
 visited[s]=true;
 for(int i=0;i<adj[s].size();i++)
  if(visited[adj[s][i]]==false)
   dfs(adj[s][i]);
}

// Function to initialize array
void initialize() 
{
 for(int i=0;i<100000;i++)
  visited[i]=false;
}

int main() 
{
 int nodes,edges,x,y,connectedComponents=0;
 cin>>nodes;                       
 cin>>edges;                       
 for(int i=0;i<edges;i++)
 {
  cin>>x>>y;     
  adj[x].push_back(y);                   
  adj[y].push_back(x);                   
 }
 initialize();                           
 for(int i=1;i<=nodes;i++)
 {
  if(visited[i]==false)     
  {
   dfs(i);
   connectedComponents++;
  }
 }
 cout<<"Number of connected components: "<<connectedComponents;
 return 0;
}
