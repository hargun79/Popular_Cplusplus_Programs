// To study vector and its associated functions.

#include<bits/stdc++.h> 
using namespace std; 
   
int main() 
{ 
  vector<int> vec; 
  // fill the array with 1 five times .
  vec.assign(5, 1); 
  cout<<"The vector elements are: \n"; 
  for(int i=0;i<5;i++) 
   cout<<vec[i]<<" ";
  cout<<'\n';  
  // inserts 2 to the last position 
  vec.push_back(2); 
  int s=vec.size(); 
  cout<<"The last element is: \n"<<vec[s-1]<<'\n'; 
  // removes last element 
  vec.pop_back(); 
  // prints the vector 
  cout<<"The vector elements after pop_back are: \n"; 
  for(int i=0;i<vec.size();i++) 
   cout<<vec[i]<<" "; 
  cout<<'\n'; 
  // inserts 0 at the beginning 
  vec.insert(vec.begin(), 0); 
  cout<<"The first element after insert command is: \n"<<vec[0]<<'\n'; 
  // removes the first element 
  vec.erase(vec.begin()); 
  cout << "The first element after erase command is: " << vec[0]<<'\n'; 
  // inserts at the beginning 
  vec.emplace(vec.begin(), 5); 
  cout<<"The first element emplace is: \n"<<vec[0]<<'\n'; 
  // inserts 20 at the end 
  vec.emplace_back(20); 
  s=vec.size(); 
  cout<<"The last element after emplace_back is: \n"<<vec[s-1]<<'\n'; 
  // erase-remove idiom
  // removes all elements with value 5
  vec.erase(remove(vec.begin(),vec.end(),5),vec.end());
  cout<<"The vector after removing 5 is: \n";
  // showing use of iterators 
  for(auto i=vec.begin();i!=vec.end();++i) 
   cout<<*i<<" ";
  cout<<'\n';
  // erases the vector 
  vec.clear(); 
  cout<<"Vector size after clear(): \n"<<vec.size()<<'\n'; 
  cout<<"Capacity of our vector: \n"<<vec.capacity()<<'\n'; 
  cout<<"Max_Size of our vector: \n"<<vec.max_size()<<'\n'; 
  // two vector to perform swap 
  vector<int> obj1, obj2; 
  obj1.push_back(2); 
  obj1.push_back(4); 
  obj2.push_back(6); 
  obj2.push_back(8); 
  cout<<"Vector 1: \n"; 
  for(int i=0;i<obj1.size();i++) 
   cout<<obj1[i]<<" "; 
  cout<<'\n'; 
  cout<<"Vector 2: \n"; 
  for(int i = 0;i<obj2.size();i++) 
   cout<<obj2[i]<<" ";
  cout<<'\n';  
  // Swaps obj1 and obj2 
  obj1.swap(obj2); 
  cout<<"After Swap Vector 1: \n"; 
  for(int i=0;i<obj1.size();i++) 
   cout<<obj1[i]<<" "; 
  cout<<'\n'; 
  cout<<"Vector 2: \n"; 
  for(int i=0;i<obj2.size();i++) 
   cout<<obj2[i]<<" "; 
  cout<<'\n';   
}
