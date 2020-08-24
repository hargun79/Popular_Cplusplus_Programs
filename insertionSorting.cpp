// To implement insertion sorting using an array.

#include<bits/stdc++.h>
using namespace std;

// Function for insertion sorting in ascending order.
void isort(int a[], int n)
{
 for(int i=1;i<n;i++)
 {
  int t,j;
  for(t=a[i],j=i-1;t<a[j] && j>=0;j--)
   a[j+1]=a[j];
  a[j+1]=t; 
 }
}

int main()
{
 int n;
 cout<<"Enter the size of the array: \n";
 cin>>n;
 int arr[n];
 cout<<"Enter the elements of the array: \n";
 for(int i=0;i<n;i++)
  cin>>arr[i];
 isort(arr,n);
 cout<<"The array after insertion sorting in ascending order is: \n";
 for(int i=0;i<n;i++)
  cout<<arr[i]<<" "; 
 return 0;
}
