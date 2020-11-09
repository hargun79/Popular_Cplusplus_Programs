// To implement activity selection problem.
 
#include <bits/stdc++.h> 
using namespace std; 

struct Activity 
{ 
 int start,finish; 
}; 

// A utility function that is used for sorting activities according to finish time 
bool activityCompare(Activity s1,Activity s2) 
{ 
 return (s1.finish<s2.finish); 
} 

// Function to find the required set of activities 
void printMaxActivities(Activity arr[],int n) 
{ 
 sort(arr,arr+n,activityCompare); 
 cout<<"Following activities are selected n"; 
 int i=0; 
 cout<<"("<<arr[i].start<<","<<arr[i].finish<<"),"; 
 for(int j=1;j<n;j++) 
 { 
  if(arr[j].start>=arr[i].finish) 
  { 
   cout<<"("<<arr[j].start<<","<<arr[j].finish<<"),"; 
   i=j; 
  } 
 } 
} 

int main() 
{ 
 Activity arr[]={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}}; 
 int n=sizeof(arr)/sizeof(arr[0]); 
 printMaxActivities(arr,n);  
 return 0; 
} 
