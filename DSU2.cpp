// To implement disjoint set data structure using linked list
 
#include <bits/stdc++.h> 
using namespace std; 
 
struct Item; 

struct Node 
{ 
 int val; 
 Node *next; 
 Item *itemPtr; 
}; 

struct Item 
{ 
 Node *hd,*tl; 
}; 

class ListSet 
{ 
 unordered_map<int,Node *> nodeAddress; 
 public: void makeset(int a); 
	     Item* find(int key); 
	     void Union(Item *i1, Item *i2); 
}; 

// Function to make a set with one object with its representative 
void ListSet::makeset(int a) 
{ 
 Item *newSet=new Item; 
 newSet->hd=new Node; 
 newSet->tl=newSet->hd; 
 nodeAddress[a] = newSet->hd; 
 newSet->hd->val=a; 
 newSet->hd->itemPtr=newSet; 
 newSet->hd->next=NULL; 
} 

// Function to find representative address of a key 
Item *ListSet::find(int key) 
{ 
 Node *ptr=nodeAddress[key]; 
 return (ptr->itemPtr); 
} 

// Union function for joining two subsets  
void ListSet::Union(Item *set1,Item *set2) 
{ 
 Node *cur=set2->hd; 
 while(cur!=0) 
 { 
  cur->itemPtr=set1; 
  cur=cur->next; 
 } 
 (set1->tl)->next=set2->hd; 
 set1->tl=set2->tl; 
 delete set2; 
} 

int main() 
{ 
 ListSet a; 
 a.makeset(13);  
 a.makeset(25); 
 a.makeset(45); 
 a.makeset(65); 
 cout<<"find(13): "<<a.find(13)<<'\n'; 
 cout<<"find(25): "<<a.find(25)<<'\n';  
 a.Union(a.find(65),a.find(45)); 
 cout<<"find(65): "<<a.find(65)<<'\n'; 
 cout<<"find(45): "<<a.find(45)<<'\n'; 
 return 0; 
} 
