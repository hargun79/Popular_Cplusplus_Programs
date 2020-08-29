// To implement quick sorting

#include<bits/stdc++.h>
using namespace std;

int partition(int a[],int l,int u)
{
 int v,i,j,temp;
 v=a[l];
 i=l;
 j=u+1;
 do
 {
  do
   i++;
  while(a[i]<v&&i<=u);
  do
   j--;
  while(v<a[j]);
  if(i<j)
  {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
  }
 }while(i<j);
 a[l]=a[j];
 a[j]=v;
 return j;
}

// Function for quick sorting in ascending order.
void qsort(int a[],int l,int u)
{
 int j;
 if(l<u)
 {
  j=partition(a,l,u);
  qsort(a,l,j-1);
  qsort(a,j+1,u);
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
 qsort(arr,0,n-1);
 cout<<"The array after quick sorting in ascending order is: \n";
 for(int i=0;i<n;i++)
  cout<<arr[i]<<" "; 
 return 0;
}
