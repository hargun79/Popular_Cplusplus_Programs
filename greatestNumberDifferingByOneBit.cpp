// To find the greatest number that varies only by 1 bit.

#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long int n;
  long long int x;
  int flag=1;
  cin>>n;
  if(n%2==0)
   cout<<n+1<<'\n';
  else
  {
   x=n;
   while(flag)
   {
   	x+=2;
   	if((x & n) == n)
   	{
   	 cout<<x;
   	 flag=0;
	}
   }
  } 
 return 0;
}

/* Alternative solution
#include<bits/stdc++.h>
using namespace std;

int main()
{
 unsigned long long n;
 cin>>n;
 unsigned long long ans=n;
 long long x=1;
 while(ans<=n)
 {
  ans= ans|x;
  x=x<<1;
 }
 cout<<ans;
}
*/
