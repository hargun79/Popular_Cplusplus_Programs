// To implement Prim's algorithm (To find the minimum spanning tree (MST connects all the vertices together, without any cycles and with the minimum possible total edge weight)) 

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
typedef pair<long long,int> PII;
bool marked[MAX];
vector <PII> adj[MAX];

// Function to implement Prim's algorithm
long long prim(int x)
{
 priority_queue<PII,vector<PII>,greater<PII>> Q;
 int y;
 long long minimumCost=0;
 PII p;
 Q.push(make_pair(0,x));
 while(!Q.empty())
 {
  p=Q.top();
  Q.pop();
  x=p.second;
  if(marked[x]==true)
   continue;
  minimumCost+=p.first;
  marked[x]=true;
  for(int i = 0;i < adj[x].size();++i)
  {
   y=adj[x][i].second;
   if(marked[y]==false)
    Q.push(adj[x][i]);
  }
 }
 return minimumCost;
}

int main()
{
 int nodes,edges,x,y;
 long long weight,minimumCost;
 cin>>nodes>>edges;
 for(int i=0;i<edges;i++)
 {
  cin>>x>>y>>weight;
  adj[x].push_back(make_pair(weight, y));
  adj[y].push_back(make_pair(weight, x));
 }
 minimumCost=prim(1);
 cout<<minimumCost<<'\n';
 return 0;
}
