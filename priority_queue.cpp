// To use priority_queue and its functions.

#include<bits/stdc++.h>
using namespace std; 

// Function to show the priority queue.
void show(priority_queue <int> pq) 
{ 
  priority_queue<int> p=pq; 
  while(!p.empty()) 
  { 
   cout<<p.top()<<" "; 
   p.pop(); 
  } 
  cout<<'\n'; 
} 

int main () 
{ 
  priority_queue <int> pq; 
  pq.push(10); 
  pq.push(30); 
  pq.push(20); 
  pq.push(5); 
  pq.push(1); 
  cout<<"The priority queue pq is : \n"; 
  show(pq); 
  cout<<"pq.size() : "<<pq.size()<<'\n'; 
  cout<<"pq.top() : "<<pq.top()<<'\n'; 
  cout<<"After popping : "<<'\n'; 
  pq.pop(); 
  show(pq); 
  return 0; 
} 

