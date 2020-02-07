// To use multiset and its functions.

#include<bits\stdc++.h>
using namespace std;

int main()
{
  multiset<int> ms; 
  multiset<int>::iterator it, it1, msIt;
  int ch,item;     
  do  
  {  
   cout<<"Multiset Operarions Menu: \n";  
   cout<<"1.Insert Number into the Multiset \n";  
   cout<<"2.Delete Element from the Multiset \n";  
   cout<<"3.Find Element in a Multiset \n";  
   cout<<"4.Count Elements with a specific key \n";  
   cout<<"5.Size of the Multiset \n";  
   cout<<"6.Display Multiset \n";  
   cout<<"7.First Element of the Multiset \n";  
   cout<<"8.Exit \n";  
   cout<<"Enter your Choice: \n";  
   cin>>ch;  
   switch(ch)  
   {  
    case 1:cout<<"Enter value to be inserted: \n";  
           cin>>item;  
           if(ms.empty())  
            it1=ms.insert(item);  
           else  
            it1=ms.insert(it1, item);  
           break;  
    case 2:cout<<"Enter value to be deleted: \n";  
           cin>>item;  
           ms.erase(item);  
           break;  
    case 3:cout<<"Enter element to be found: \n";  
           cin>>item;  
           it=ms.find(item);  
           if(it!=ms.end())  
            cout<<"Element found \n";  
           else  
            cout<<"Element not found \n";  
           break;  
    case 4:cout<<"Enter element to be counted: \n";  
           cin>>item;  
           cout<<item<<" appears "<<ms.count(item)<<" times."<<'\n';  
           break;  
    case 5:cout<<"Size of the Multiset: "<<ms.size()<<'\n';  
           break;  
    case 6:cout<<"Elements of the Multiset:  \n";  
           for(it=ms.begin();it!=ms.end();it++)  
            cout<<*it<<"  ";  
           cout<<'\n';  
           break;  
    case 7:if(ms.empty())  
            cout<<"Multiset is empty \n";  
           else  
           {  
            msIt=ms.begin();  
            cout<<"The First Element of the Multiset is " << *msIt <<'\n';   
           }    
           break;  
    case 8:exit(0);  
           break;  
    default:cout<<"Wrong Choice \n";  
   }  
  }while(ch!=8);
  return 0;
}
