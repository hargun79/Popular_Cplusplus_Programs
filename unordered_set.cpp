// To use unordered_set and its functions.

#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
  unordered_set<int> s1;
  for(int i=0; i<5; i++) 
   s1.insert(i+10);
  s1.erase(12);
  cout<<"elements after deleting  12: \n";
  for(auto it= s1.begin(); it!=s1.end(); it++)
   cout<<*it<<" ";
  cout<<'\n';
  unordered_set<int> s2;
  for(int i=0;i<4;i++) 
   s2.insert(i);
  cout<<"unordered_set 1 elements before swapping: \n";
  for(auto it=s1.begin();it!=s1.end();it++) 
   cout<<*it<<" ";
  cout<<'\n';
  cout<<"unordered_set 2 elements before swapping \n";
  for(auto it=s2.begin();it!=s2.end();it++) 
   cout<<*it<<" ";
  cout<<'\n';
  s1.swap(s2); 
  cout<<"unordered_set 1 elements after swapping \n";
  for(auto it=s1.begin();it!=s1.end();it++) 
   cout<<*it<<" ";
  cout<<'\n';
  cout<<"unordered_set 2 elements after swapping \n";
  for(auto it=s2.begin();it!=s2.end();it++) 
   cout<<*it<<" ";
  cout<<'\n';
  s1.clear();
  cout<<"Performing clear() operation on unordered_set1......"<<'\n';
  s1.empty()?cout<<"Unordered_set is empty"<<'\n':cout<<"unordered_set is not empty"<<'\n'; 
  return 0;
}
