// To implement boolean parenthesization problem i.e. find the number of ways in which expression evaluates to true

#include <bits/stdc++.h>
using namespace std;

unordered_map<string,int> ump;

// Function to find the boolean parethesization
int bp(string X,int i,int j,bool isTrue) 
{
 string key=to_string(i)+" "+to_string(j)+" "+(isTrue?"T":"F");
 if(ump.find(key)!=ump.end())
  return ump[key];
 if(i>=j) 
 {
  if(isTrue)
   ump[key]=X[i]=='T';
  else
   ump[key]=X[i]=='F';
  return ump[key];
 }
 int ans=0;
 for(int k=i+1;k<j;k+=2) 
 {
  int l_T=bp(X,i,k-1,true);
  int l_F=bp(X,i,k-1,false);
  int r_T=bp(X,k+1,j,true);
  int r_F=bp(X,k+1,j,false);
  if(X[k]=='|') 
  {
   if(isTrue==true)
	ans+=l_T*r_T+l_T*r_F+l_F*r_T;
   else
	ans+=l_F*r_F;
  }
  else 
   if(X[k]=='&') 
   {
	if(isTrue==true)
	 ans+=l_T*r_T;
	else
	 ans+=l_T*r_F+l_F*r_T+l_F*r_F;
   }
   else 
    if(X[k]=='^') 
    {
	 if(isTrue==true)
	  ans+=l_T*r_F+l_F*r_T;
	 else
	  ans+=l_T*r_T+l_F*r_F;
	}
  }
  return ump[key]=ans;
}

int main() 
{
 string X; 
 cin >> X;
 ump.clear();
 cout<<bp(X,0,X.length()-1,true)<<'\n';
 return 0;
}