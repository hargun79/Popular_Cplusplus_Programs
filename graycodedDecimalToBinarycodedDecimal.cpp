// To implement gray coded decimal to binary coded decimal converter

#include<bits/stdc++.h>
using namespace std;

int main()
{
 long long int n;
 cin>>n;
 string str1=bitset<32>(n).to_string();
 string str2="00000000000000000000000000000000";
 str2[0]=str1[0];
 int j=0;
 for(int i=1;i<str1.length();i++)
 {
  if(str1[i]=='1' && str2[j]=='1')
   str2[++j]='0';
  else 
   if(str1[i]=='0' && str2[j]=='0')
    str2[++j]='0';
  else
   str2[++j]='1'; 
 } 
 unsigned long long int ans=bitset<32>(str2).to_ullong();
 cout<<ans<<'\n';
 return 0;
}
