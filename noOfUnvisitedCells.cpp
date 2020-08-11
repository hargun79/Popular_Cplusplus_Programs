// To find number of unvisited cells in a matrix

#include<bits/stdc++.h>
using namespace std;

int main()
{
 int n,k,l,r;
 cin>>n>>k;
 set<int> row,col;
 for(int i=0;i<k;i++)
 {
  cin>>l>>r;
  row.insert(l);
  col.insert(r);
  cout<<(n-row.size())*(n-col.size())<<" ";
 }
 return 0;
}
