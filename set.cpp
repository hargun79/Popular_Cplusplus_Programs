// To use set and its functions.

#include<bits/stdc++.h>
using namespace std;

int main()
{
  set<int> set1;
  set1.insert(20);
  set1.insert(202);
  set1.insert(230);
  set1.insert(240);
  set1.insert(250);
  cout<<"Elements after insertion: \n";
  for(auto iterator=set1.begin();iterator!=set1.end();++iterator)
   cout<<*iterator<<" ";
  cout<<'\n'; 
  set1.erase(20);
  set1.erase(202);
  cout<<"Element after deletion : \n";
  for(auto iterator=set1.begin();iterator!=set1.end();++iterator)
   cout<<*iterator<<" ";
  cout<<'\n'; 
  set<int,greater<int>> set2;
  set2.insert(5);
  set2.insert(50);
  set2.insert(20);
  cout<<"The set elements using greater() function is: \n";
  for(auto iterator=set2.begin();iterator!=set2.end();++iterator)
   cout<<*iterator<<" ";
  return 0;
}
