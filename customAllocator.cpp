// To use custom allocator and deallocator.

#include<bits/stdc++.h>
using namespace std;

template<typename type>
struct MyAlloc:allocator<type>
{
  type *allocate(size_t size)
  {
    cout<<"Allocation request size: "<<size<<'\n';
    return new type[size];
  }
  void deallocate(type *ptr, size_t size)
  {
    cout<<"Deallocating size: "<<size<<'\n';
    delete[] ptr;
  }
};

int main()
{
  vector<int, MyAlloc<int>> v1;
  v1.push_back(10);
  v1.push_back(20);
  v1.push_back(30);
  v1.push_back(40);
  v1.push_back(50);
  for(auto &var:v1)
   cout<<var<<" ";
  cout<<'\n'; 
  return 0;
}
