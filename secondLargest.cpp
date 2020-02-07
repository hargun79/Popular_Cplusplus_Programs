#include <iostream>

using namespace std;



int main() 
{
	
 int n,a,b,c;
	 
 cin>>n;
	
 while(n--)
	
 {
	    
  cin>>a>>b>>c;
	    
  if(a>b && a>c && b>c)
	    
  {
	     
   cout<<b<<'\n';
	     
   continue;
	    
  } 
	    
  else
	     
   if(a>b && a>c && c>b)
	     
   {
	      
    cout<<c;
	      
    continue;
	     
   } 
	    
  else
	     
   if(b>a && b>c && c>a)
	     
   {
	      
    cout<<c<<'\n';
	      
    continue;
	     
   } 
	    
  else
	      
   if(b>a && b>c && a>c)
	     
   {
	      
    cout<<a<<'\n';   
	       
    continue;
	     
   }
	    
  else
	     
   if(c>a && c>b && a>b)
	     
   {
	      
    cout<<a<<'\n';
	      
    continue;
	     
   } 
	    
  else
	     
   if(c>a && c>b && b>a)
	     
   {
	      
    cout<<b<<'\n';
	      
    continue;
	     
   }
	
 } 
 
 return 0;

}
