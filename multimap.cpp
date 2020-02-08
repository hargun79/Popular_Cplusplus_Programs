// To use multimap and its functions.

#include<bits/stdc++.h>
using namespace std; 

int main() 
{ 
  multimap<int, int> gquiz1;
  gquiz1.insert(pair <int, int> (1, 40)); 
  gquiz1.insert(pair <int, int> (2, 30)); 
  gquiz1.insert(pair <int, int> (3, 60)); 
  gquiz1.insert(pair <int, int> (4, 20)); 
  gquiz1.insert(pair <int, int> (5, 50)); 
  gquiz1.insert(pair <int, int> (6, 50)); 
  gquiz1.insert(pair <int, int> (6, 10)); 
  multimap<int, int>::iterator itr; 
  cout<<"The multimap gquiz1 is : \n"; 
  cout<<"KEY ELEMENT\n"; 
  for(itr=gquiz1.begin();itr!=gquiz1.end();++itr)  
   cout<<itr->first<<" "<<itr->second<<'\n';  
  cout<<'\n'; 
  // assigning the elements from gquiz1 to gquiz2 
  multimap <int, int> gquiz2(gquiz1.begin(),gquiz1.end()); 
  cout<<"The multimap gquiz2 after assign from gquiz1 is : \n"; 
  cout<<"KEY tELEMENT\n"; 
  for(itr=gquiz2.begin();itr!=gquiz2.end();++itr) 
   cout<<itr->first<<" "<<itr->second<<'\n'; 
  cout<<'\n'; 
  // remove all elements up to element with value 30 in gquiz2 
  cout<<"gquiz2 after removal of elements less than key=3 : \n"; 
  cout<<"KEY ELEMENT\n"; 
  gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); 
  for(itr=gquiz2.begin();itr!=gquiz2.end();++itr) 
   cout<<itr->first<<" "<<itr->second<<'\n'; 
  // remove all elements with key = 4 
  int num; 
  num=gquiz2.erase(4); 
  cout<<"gquiz2.erase(4) : \n"; 
  cout<<num<<" removed \n"; 
  cout<<"KEY ELEMENT\n"; 
  for(itr=gquiz2.begin();itr!=gquiz2.end();++itr) 
   cout<<itr->first<<" "<<itr->second<<'\n'; 
  cout<<'\n'; 
  //lower bound and upper bound for multimap gquiz1 key = 5 
  cout<<"gquiz1.lower_bound(5) : "<<"KEY = "; 
  cout<<gquiz1.lower_bound(5)->first<<" "; 
  cout<<"ELEMENT = "<<gquiz1.lower_bound(5)->second<<'\n'; 
  cout<<"gquiz1.upper_bound(5) : "<<"KEY = "; 
  cout<<gquiz1.upper_bound(5)->first<<" "; 
  cout<<"ELEMENT = "<<gquiz1.upper_bound(5)->second<<'\n'; 
  return 0; 
} 

