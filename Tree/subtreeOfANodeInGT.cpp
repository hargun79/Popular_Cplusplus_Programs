// To find subtree of all nodes
 
#include<bits/stdc++.h> 
using namespace std; 

int start[100001]; 
int endd[100001]; 
vector<int>dfs_order; 
vector<int>adj[100001]; 
int visited[100001]; 

// Function to implement dfs
void dfs(int a,int &b) 
{ 
 visited[a]=1; 
 b++; 
 start[a]=b; 
 dfs_order.push_back(a); 
 for(vector<int>::iterator it=adj[a].begin();it!=adj[a].end();it++) 
  if(!visited[*it]) 
   dfs(*it,b); 
 endd[a]=b; 
} 

// Function to print the subtree nodes 
void Print(int n) 
{ 
 for(int i=0;i<n;i++) 
 { 
  if(start[i]!=endd[i]) 
  { 
   cout<<"subtree of node "<<i<<" is "; 
   for(int j=start[i]+1;j<=endd[i];j++) 
    cout<<dfs_order[j-1]<<" "; 
   cout<<'\n'; 
  } 
 } 
} 

int main() 
{ 
 int n,src,dest,c=0;
 cin>>n;
 for(int i=0;i<n-1;i++)
 {
  cin>>src>>dest;
  src--;
  dest--;
  adj[src].push_back(dest);
 }
 dfs(0,c);
 Print(n); 
 return 0; 
} 
