// To implement disjoint set union.(For reference see 277A)

#include<bits/stdc++.h>
using namespace std;
 
vector<int> parent;
 
int find_set(int a)
{
 if(parent[a]<0) 
  return a;
 return parent[a]=find_set(parent[a]);
}
 
void union_set(int a,int b)
{
 int p1=find_set(a);
 int p2=find_set(b);
 if(p1==p2)
  return;
 if(parent[p1]>parent[p2]) 
  swap(p1, p2);
 parent[p1]+=parent[p2];
 parent[p2]=p1;
}
 
int main()
{
 int n,m,a,k,peopleWithZeroLang=0,langWhichAreParents=0;
 cin>>n>>m;
 parent=vector<int>(m,-1);
 vector<bool> isLangUsed(m,false);
 for(int i=0;i<n;i++)
 {
  cin>>k;
  if(k==0)
  {
   peopleWithZeroLang++;
   continue;
  }
  vector<int> v(k);
  for(int j=0;j<k;j++)
  {
   cin>>v[j];
   isLangUsed[v[j]-1]=true;
  }
  for(int j=1;j<v.size();j++)
   union_set(v[j]-1,v[j-1]-1);
 }
 for(int i=0;i<m;i++)
  if(parent[i]<0 && isLangUsed[i])
   langWhichAreParents++;
 if(langWhichAreParents==0) 
  langWhichAreParents++;
 cout<<langWhichAreParents-1+peopleWithZeroLang;  
 return 0;
}
