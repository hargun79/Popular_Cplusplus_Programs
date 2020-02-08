// To use stack and its functions.
 
#include <bits/stdc++.h> 
using namespace std; 

// Function to show a stack.
void showstack(stack <int> s) 
{ 
  while (!s.empty()) 
  { 
   cout<<s.top()<<" "; 
   s.pop(); 
  } 
  cout<<'\n'; 
} 

int main () 
{ 
  stack <int> s; 
  s.push(10); 
  s.push(30); 
  s.push(20); 
  s.push(5); 
  s.push(1); 
  cout<<"The stack is : \n"; 
  showstack(s); 
  cout<<"s.size() : "<<s.size()<<'\n'; 
  cout<<"s.top() : "<<s.top()<<'\n'; 
  cout<<"After popping: "<<'\n'; 
  s.pop(); 
  showstack(s); 
  return 0; 
} 
