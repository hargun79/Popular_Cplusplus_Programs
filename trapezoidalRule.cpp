// To implement trapezoidal rule.

#include<bits/stdc++.h>
using namespace std;

#define f(x) 1/(1+pow(x,2))

int main()
{
 float lower, upper, integration=0.0, stepSize, k;
 int i, subInterval;
 cout<<"Enter lower limit of integration: \n";
 cin>>lower;
 cout<<"Enter upper limit of integration: \n";
 cin>>upper;
 cout<<"Enter number of sub intervals: \n";
 cin>>subInterval;
 stepSize=(upper-lower)/subInterval;
 integration=f(lower)+f(upper);
 for(i=1;i<=subInterval-1;i++)
 {
  k=lower+i*stepSize;
  integration=integration+2*(f(k));
 }
 integration=integration*stepSize/2;
 cout<<"Required value of integration is: "<< integration<<'\n';
 return 0;
}
