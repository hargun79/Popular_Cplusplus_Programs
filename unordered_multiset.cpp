// To use unordered_multiset and its functions.

#include<bits/stdc++.h>
using namespace std;

int main()
{
  unordered_multiset<int> ums1;
  unordered_multiset<int> ums2;
  ums1 = {9, 8, 7, 6, 6, 6, 5, 4, 3};
  ums2 = {99, 88, 77, 66, 55};
  cout << "Elements in ums1 before swap are" << endl;
  for(auto it= ums1.begin(); it!=ums1.end(); ++it) 
   cout<<*it<<" "; 
  cout<<'\n';
  cout<<"Elements in the ums2 before swap are: \n";
  for(auto it= ums2.begin(); it!=ums2.end(); ++it) 
   cout<<*it<<" "; 
  cout<<'\n';
  cout<<"Doing swap opeartion......."<<'\n';
  ums1.swap(ums2);
  cout<<"Elements in ums1 after swap are: \n";
  for(auto it= ums1.begin(); it!=ums1.end(); ++it) 
   cout<<*it<<" "; 
  cout<<'\n';
  cout<<"Elements in the ums2 after swap are: \n";
  for(auto it= ums2.begin(); it!=ums2.end(); ++it) 
   cout<<*it<<" "; 
  cout<<'\n';
  cout<<"Erasing element 5 in ums2..."<<'\n';
  ums2.erase(5);
  cout<<"Now erasing 1st element in ums2 by pointing iterator to it..."<<'\n';
  auto it= ums2.begin();
  ums2.erase(it);
  cout<<"Range erasing..."<<'\n';
  ums2.erase (ums2.find(6), ums2.end());
  cout<<"Elements in ums2 after doing above erase operations are: \n";
  for(auto it= ums2.begin(); it!=ums2.end(); ++it) 
   cout<<*it<<" ";
  cout<<'\n';
  return 0;
}
