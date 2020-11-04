// To implement depth first search using recursion (To obtain lexicographically smallest DFS sort the edges of each vertex in ascending order)

#include<bits/stdc++.h>
using namespace std;

const int maxn=2e6+10;
int n,m;
vector<int> vc[maxn];
bool mark[maxn];

// Function to implement depth first search
void dfs(int v)
{
 cout<<v<<'\n';
 mark[v]=1;
 for(int u: vc[v])
  if(!mark[u])
   dfs(u);
}

int main()
{
 cin>>n>>m;
 for(int u,v,i=0;i<m;i++)
 {
  cin>>u>>v;
  u--; 
  v--;
  vc[u].push_back(v);
  vc[v].push_back(u);
 }
 int cnt=0;
 for(int i=0;i<n;i++)
  if(!mark[i])
   dfs(i);
 return 0;  
}
