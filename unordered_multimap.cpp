// To use unordered_multimap and its functions.

#include <bits/stdc++.h> 
using namespace std; 

typedef unordered_multimap<string, int>::iterator umit; 

// Function to print unordered_multimap. 
void printUmm(unordered_multimap<string, int> umm) 
{ 
  umit it=umm.begin(); 
  for(;it!=umm.end();it++) 
   cout<<" "<<it->first<<" "<<it->second;
  cout<<'\n'; 
} 

int main() 
{ 
  unordered_multimap<string, int> umm1; 
  unordered_multimap<string, int> umm2 ({{"apple", 1}, 
										{"ball", 2}, 
										{"apple", 10}, 
										{"cat", 7}, 
										{"dog", 9}, 
										{"cat", 6}, 
										{"apple", 1}}); 

  umm1=umm2; 
  printUmm(umm1); 
  if(umm2.empty()) 
   cout<<"unordered multimap 2 is empty\n"; 
  else
   cout<<"unordered multimap 2 is not empty\n"; 
  cout<<"Size of unordered multimap 1 is: "<<umm1.size()<<'\n'; 
  string key="apple"; 
  umit it=umm1.find(key); 
  if(it!=umm1.end()) 
  { 
   cout<<"key "<<key<<" is there in unordered multimap 1\n"; 
   cout<<"one of the value associated with "<<key<<" is "<<it->second<<'\n'; 
  } 
  else
   cout<<"key "<<key<<"is not there in unordered multimap 1\n"; 
  int cnt=umm1.count(key); 
  cout<<"total values associated with "<<key<<"are "<<cnt<<"\n"; 
  printUmm(umm2); 
  umm2.insert(make_pair("dog", 11)); 
  umm2.insert({{"alpha", 12}, {"beta", 33}}); 
  cout<<"After insertion of <apple, 12> and <beta, 33>\n"; 
  printUmm(umm2); 
  umm2.erase("apple"); 
  cout<<"After deletion of apple\n"; 
  printUmm(umm2); 
  umm1.clear(); 
  umm2.clear(); 
  if(umm2.empty()) 
   cout<<"unordered multimap 2 is empty\n"; 
  else
   cout<<"unordered multimap 2 is not empty\n"; 
  return 0; 
} 

