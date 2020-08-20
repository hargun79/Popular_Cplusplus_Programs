// To find all the paths between any two nodes in a graph

#include<bits/stdc++.h> 
using namespace std; 
  
// Function for printing all the paths 
void printpath(vector<int>& path) 
{ 
 int size=path.size(); 
 for(int i=0;i<size;i++)  
  cout<<path[i]+1<<" ";     
 cout<<'\n'; 
} 
  
// Function to check if current vertex is already present in path 
int isNotVisited(int x,vector<int>& path) 
{ 
 int size=path.size(); 
 for(int i=0;i<size;i++)  
  if(path[i]==x)  
   return 0;  
 return 1; 
} 
  
// Function for finding paths in graph from source to destination 
void findpaths(vector<vector<int> >&g,int src,int dst,int v) 
{ 
 queue<vector<int>> q; 
 vector<int> path; 
 path.push_back(src); 
 q.push(path); 
 while(!q.empty()) 
 { 
  path=q.front(); 
  q.pop(); 
  int last=path[path.size()-1]; 
  if(last==dst)  
   printpath(path);         
  for(int i=0;i<g[last].size();i++) 
  { 
   if(isNotVisited(g[last][i],path)) 
   { 
    vector<int> newpath(path); 
    newpath.push_back(g[last][i]); 
    q.push(newpath); 
   } 
  } 
 } 
} 
  
int main() 
{ 
 vector<vector<int>> g;
 int v,e,src,dest;
 cin>>v>>e; 
 g.resize(v); 
 for(int i=0;i<e;i++)
 {
  cin>>src>>dest;
  src--;
  dest--;
  g[src].push_back(dest);
  g[dest].push_back(src);
 }
 cin>>src>>dest;
 src--;
 dest--;
 findpaths(g,src,dest,v); 
 return 0; 
}
