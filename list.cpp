// To implement list and its associated functions.

#include<bits/stdc++.h> 
using namespace std; 

//Function for printing the elements in a list. 
void showlist(list <int> g) 
{ 
  list <int> :: iterator it; 
  for(it=g.begin();it!=g.end();++it) 
   cout<<*it<<" "; 
  cout<<'\n'; 
} 

int main() 
{ 
  list<int> gqlist1, gqlist2; 
  for(int i=0;i<10;++i) 
  { 
   gqlist1.push_back(i * 2); 
   gqlist2.push_front(i * 3); 
  } 
  cout<<"List 1 (gqlist1) is : \n"; 
  showlist(gqlist1); 
  cout<<"List 2 (gqlist2) is : \n"; 
  showlist(gqlist2); 
  cout<<"gqlist1.front() : \n"<<gqlist1.front()<<'\n'; 
  cout<<"gqlist1.back() : \n"<<gqlist1.back()<<'\n'; 
  cout<<"gqlist1.pop_front() : \n"; 
  gqlist1.pop_front(); 
  showlist(gqlist1); 
  cout<<"gqlist2.pop_back() : \n"; 
  gqlist2.pop_back(); 
  showlist(gqlist2); 
  cout<<"gqlist1.reverse() : \n"; 
  gqlist1.reverse(); 
  showlist(gqlist1); 
  cout<<"gqlist2.sort(): \n"; 
  gqlist2.sort(); 
  showlist(gqlist2); 
  return 0; 
} 

