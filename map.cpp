// To use map and its functions.

#include<bits\stdc++.h>
using namespace std; 

int main() 
{ 
  map<int, int> gquiz1; 
  gquiz1.insert(pair<int, int>(1, 40)); 
  gquiz1.insert(pair<int, int>(2, 30)); 
  gquiz1.insert(pair<int, int>(3, 60)); 
  gquiz1.insert(pair<int, int>(4, 20)); 
  gquiz1.insert(pair<int, int>(5, 50)); 
  gquiz1.insert(pair<int, int>(6, 50)); 
  gquiz1.insert(pair<int, int>(7, 10)); 
  map<int, int>::iterator itr; 
  cout<<"The map gquiz1 is : \n"; 
  cout<<"KEY ELEMENT \n";  
  for(itr=gquiz1.begin();itr!=gquiz1.end();++itr)
   cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n'; 
  cout<<'\n'; 
  // assigning the elements from gquiz1 to gquiz2 
  map<int, int> gquiz2(gquiz1.begin(), gquiz1.end()); 
  cout<<"The map gquiz2 after assign from gquiz1 is : \n"; 
  cout<<"KEY ELEMENT\n"; 
  for(itr=gquiz2.begin();itr!=gquiz2.end();++itr) 
   cout<<itr->first<<" "<<itr->second<< '\n'; 
  cout<<'\n'; 
  // remove all elements up to element with key=3 in gquiz2 
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
  // lower bound and upper bound for map gquiz1 key = 5 
  cout<<"gquiz1.lower_bound(5) : "<<"\tKEY = "; 
  cout<<gquiz1.lower_bound(5)->first<<'\t'; 
  cout<<"\tELEMENT = "<<gquiz1.lower_bound(5)->second<<'\n'; 
  cout<<"gquiz1.upper_bound(5) : "<< "\tKEY = "; 
  cout<<gquiz1.upper_bound(5)->first << '\t'; 
  cout<<"\tELEMENT = "<< gquiz1.upper_bound(5)->second<<'\n'; 
  return 0; 
} 

