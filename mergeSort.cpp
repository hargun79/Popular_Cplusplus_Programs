// To implement merge sorting

#include<bits/stdc++.h>
using namespace std;

// Function for merging two arrays. 
void merge(int a[],int i1,int j1,int i2,int j2)
{
 int temp[15];	
 int i,j,k;
 i=i1;
 j=i2;
 k=0;
 while(i<=j1 && j<=j2)
 {
  if(a[i]<a[j])
   temp[k++]=a[i++];
  else
   temp[k++]=a[j++];
 }
 while(i<=j1)
  temp[k++]=a[i++];
 while(j<=j2)
  temp[k++]=a[j++];
 for(i=i1,j=0;i<=j2;i++,j++)
  a[i]=temp[j];
}

// Function for merge sorting in ascending order.
void msort(int a[],int i,int j)
{
 int mid;
 if(i<j)
 {
  mid=(i+j)/2;
  msort(a,i,mid);
  msort(a,mid+1,j);
  merge(a,i,mid,mid+1,j);
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
 msort(arr,0,n-1);
 cout<<"The array after merge sorting in ascending order is: \n";
 for(int i=0;i<n;i++)
  cout<<arr[i]<<" "; 
 return 0;
}
