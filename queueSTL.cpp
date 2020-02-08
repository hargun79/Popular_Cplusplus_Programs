// To use queue and its functions.

#include<bits/stdc++.h>
using namespace std; 

// Function to print the queue.
void showq(queue <int> q) 
{ 
  queue <int> g = q; 
  while (!g.empty()) 
  { 
   cout<<g.front()<<" "; 
   g.pop(); 
  } 
  cout<<'\n'; 
} 

int main() 
{ 
  queue <int> q; 
  q.push(10); 
  q.push(20); 
  q.push(30); 
  cout << "The queue q is : "; 
  showq(q); 
  cout<<"q.size() : "<<q.size()<<'\n'; 
  cout<<"q.front() : "<<q.front()<<'\n'; 
  cout<<"q.back() : "<<q.back()<<'\n'; 
  cout << "After popping: \n"; 
  q.pop(); 
  showq(q); 
  return 0; 
} 

