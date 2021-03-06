// To do functional programming with map(), filter() and reduce().

#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v {1,2,3,4,5,6,7};
  vector<int> vout;
  //map
  transform(v.begin(),v.end(),back_inserter(vout), [](int &value){return value*3;});
  for(auto &val:vout)
   cout<<val<<" ";
  cout<<'\n'; 
  //filter
  auto endfilter=remove_if(vout.begin(),vout.end(), [](int &value){
   if(value%2==0)
    return true;
   return false; 
  });
  for(auto itr=vout.begin();itr!=endfilter;itr++)
   cout<<*itr<<" ";
  cout<<'\n'; 
  //reduce
  int finalval=accumulate(vout.begin(), endfilter, 0, [](int first, int second){return first+second;});
  cout<<"Final value: "<<finalval<<'\n';
  return 0;
}
