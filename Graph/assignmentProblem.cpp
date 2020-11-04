// To implement assignment problem using branch and bound method (Special case of min cost flow problem, in which we have to find the min cost in which all the tasks can be done)

#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
 Node* parent; 
 int pathCost; 
 int cost; 
 int workerID; 
 int jobID; 
 bool assigned[100]; 
}; 

// Function to allocate a new node
Node* newNode(int x,int y,bool assigned[],Node* parent,int N) 
{ 
 Node* node=new Node; 
 for(int j=0;j<N;j++) 
  node->assigned[j]=assigned[j]; 
 node->assigned[y]=true; 
 node->parent=parent; 
 node->workerID=x; 
 node->jobID=y; 
 return node; 
} 

// Function to calculate the least promising cost of node after worker x is assigned to job y. 
int calculateCost(int costMatrix[][100],int x,int y,bool assigned[],int N) 
{ 
 int cost=0; 
 bool available[N]={true}; 
 for(int i=x+1;i<N;i++) 
 { 
  int min=INT_MAX,minIndex=-1; 
  for(int j=0;j<N;j++) 
  { 
   if(!assigned[j] && available[j] && costMatrix[i][j]<min) 
   { 
    minIndex=j;  
    min=costMatrix[i][j]; 
   } 
  } 
  cost+=min; 
  available[minIndex]=false; 
 } 
 return cost; 
} 

// Comparison object to be used to order the heap 
struct comp 
{ 
 bool operator()(const Node* lhs,const Node* rhs) const
 { 
  return lhs->cost > rhs->cost; 
 } 
}; 

// Function to print the solution
void printAssignments(Node *min) 
{ 
 if(min->parent==NULL) 
  return; 
 printAssignments(min->parent); 
 cout<<"Assign Worker "<<char(min->workerID+'A')<<" to Job "<<min->jobID<<'\n'; 
} 

// Function to find minimum cost using Branch and Bound. 
int findMinCost(int costMatrix[][100],int N) 
{  
 priority_queue<Node*,std::vector<Node*>,comp> pq; 
 bool assigned[N]={false}; 
 Node* root=newNode(-1,-1,assigned,NULL,N); 
 root->pathCost=root->cost=0; 
 root->workerID=-1; 
 pq.push(root); 
 while(!pq.empty()) 
 { 
  Node* min=pq.top(); 
  pq.pop(); 
  int i=min->workerID+1; 
  if(i==N) 
  { 
   printAssignments(min); 
   return min->cost; 
  } 
  for(int j=0;j<N;j++) 
  { 
   if(!min->assigned[j]) 
   { 
    Node* child=newNode(i,j,min->assigned,min,N); 
    child->pathCost=min->pathCost+costMatrix[i][j]; 
    child->cost=child->pathCost+calculateCost(costMatrix,i,j,child->assigned,N); 
    pq.push(child); 
   } 
  } 
 } 
} 

int main() 
{ 
 int n;
 cin>>n;
 int costMatrix[100][100];
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
   cin>>costMatrix[i][j];
 cout<<findMinCost(costMatrix,n);  
 return 0; 
} 
