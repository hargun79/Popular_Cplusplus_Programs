// To implement breadth first search in a generic tree

#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void levelOrderTraversal(int i,list<int> adj[]) 
 {   
  queue<int> q;
  q.push(1);
  while(!q.empty()) 
  { 
   int p=q.front(); 
   q.pop(); 
   v.push_back(p); 
   for(list<int>::iterator itr=adj[p].begin();itr!=adj[p].end();itr++) 
    q.push(*itr);  
  }
 }

int main()
{
 int n,a,ans=0;
 cin>>n;
 int arr[n+1]={0};
 list<int> adj[n+1];
 for(int i=0;i<n;i++)
 {
  cin>>a;
  if(i==0)
   continue;
  adj[a].push_back(i+1);
 }
 levelOrderTraversal(1,adj);
 for(int i=0;i<v.size();i++)
  cout<<v[i]<<" ";
 return 0;
}
