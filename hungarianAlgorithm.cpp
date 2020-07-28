// To implement Hungarian algorithm

#include<bits/stdc++.h>
using namespace std;

int drawLines(vector<vector<pair<int,bool>>> &matrix, vector<pair<int,int>> &intersection, vector<vector<bool>> &assign, int N);

// Function to implement Hungarian algorithm 
void Hungarian()
{
 int N;
 cin>>N;
 vector<vector<pair<int,bool>>> matrix(N,vector<pair<int,bool>>(N));
 vector<vector<int>> costs(N,vector<int>(N));
 for(int i=0;i<N;i++)
 {
  for(int j=0;j<N;j++)
  {
   int temp;
   cin>>temp;
   costs[i][j]=temp;
   matrix[i][j].first=temp;
  }
 }
 //find min in each row and subtract each element in that row by min
 for(int i=0;i<N;i++)
 {
  int min=matrix[i][0].first;
  for(int j=0;j<N;j++)
   if(min>matrix[i][j].first)
    min=matrix[i][j].first;
  for(int k=0;k<N;k++)
   matrix[i][k].first-=min;
 }
 //find min in each col and subtract each element in that col by min
 for(int i=0;i<N;i++)
 {
  int min=matrix[0][i].first;
  for(int j=0;j<N;j++)
   if(min>matrix[j][i].first)
    min=matrix[j][i].first;
  for(int k=0;k<N;k++)
   matrix[k][i].first-=min;
 }
 //draw the minimum number of lines and find the intersections
 vector<pair<int,int>> intersection;
 vector<vector<bool>> assign(N,vector<bool>(N));
 int numLines=drawLines(matrix,intersection,assign,N);
 while(numLines<N)
 {
  int min=201;
  for(int i=0;i<N;i++)
   for(int j=0;j<N;j++)
    if(matrix[i][j].second==false && min>matrix[i][j].first)
     min=matrix[i][j].first;
  for(int i=0;i<N;i++)
   for(int j=0;j<N;j++)
    if(matrix[i][j].second==false)
     matrix[i][j].first -= min;
  for(int i=0;i<intersection.size();i++)
   matrix[intersection[i].first][intersection[i].second].first+=min;
  numLines=drawLines(matrix,intersection,assign,N);
 }
 //add the costs using the assignments in assign
 int totalCost=0;
 for(int i=0;i<N;i++)
  for(int j=0;j<N;j++)
   if(assign[i][j])
    totalCost+=costs[i][j];
 cout<<totalCost;
}
 
// Function to draw minimum number of lines 
int drawLines(vector<vector<pair<int,bool>>> &matrix,vector<pair<int,int>> &intersection,vector<vector<bool>> &assign,int N)
{
 for(auto &temp:assign)
  fill(temp.begin(),temp.end(),false);
 for(auto &temp:matrix)
  for(auto &x : temp)
   x.second=false;
 vector<vector<int>> tick(N,vector<int>(N));
 vector<bool> markedRow(N,true),markedCol(N);
 int numZero,numLine=0,row,col;
 bool zeroFound=true;
 bool singleZero=true;
 while(zeroFound)
 {
  while(singleZero)
  {
   singleZero=false;
   //iterate through matrix
   for(int i = 0; i < N; i++)
   {
    //check row for num of unticked zeros and tick non zero
    numZero=0;
    for(int j=0;j<N;j++)
    {
     if(matrix[i][j].first!=0)
      tick[i][j]=true;
     else 
	  if(tick[i][j]==false)
      {
       numZero++;
       row=i;
       col=j;
      }
    }
    //if only 1 zero found, tick col of that zero and cross out other unticked zeros
    if(numZero==1)
    {
     tick[row][col]=true;
     markedRow[row]=false;//unmark row with assignment
     assign[row][col]=true;
     singleZero=true;
     for(int k=0;k<N;k++)
     {
      if(matrix[k][col].first==0 && tick[k][col]==false)
       tick[k][col]=-1;
      else 
	   if(tick[k][col]==false)
        tick[k][col] = true;
     }
    }
    //check col for num of unticked zeros
    numZero=0;
    for(int j=0;j<N;j++)
    {
     if(matrix[j][i].first!=0)
      tick[j][i]=true;
     else 
	  if(tick[j][i]==false)
      {
       numZero++;
       row=j;
       col=i;
      }
    }
    //if only 1 zero found, tick row of that zero and cross out other unticked zeros
    if(numZero==1)
    {
     tick[row][col]=true;
     markedRow[row]=false;//unmark row with assignments
     assign[row][col]=true;
     singleZero=true;
     for(int k=0;k<N;k++)
     {
      if(matrix[row][k].first==0 && tick[row][k]==false)
       tick[row][k]=-1;
      else 
	   if(tick[row][k]!=-1)
        tick[row][k]=true;
     }
    }
   }
  }
  //loop through and check if there are any unticked zeros
  zeroFound=false;
  for(int i=0;i<N;i++)
  {
   for(int j=0;j<N;j++)
   {
    //if found, tick row and col of that zero and cross out other unticked zeros
    if(tick[i][j]==false && matrix[i][j].first==0)
    {
     tick[i][j]=true;
     markedRow[i]=false;//unmark row with assignments
     assign[i][j]=true;
     zeroFound=true;
     for(int k=0;k<N;k++)
     {
      if(tick[i][k]==false && matrix[i][k].first==0)
       tick[i][k]=-1;
      else 
	   if(tick[i][k]==false)
        tick[i][k] = true;
      if(tick[k][j]==false && matrix[k][j].first==0)
       tick[k][j]=-1;
      else 
	   if(tick[i][k]==false)
        tick[k][j]=true;
     }
     break;//move on to next row, since a zero is found
    }
   }
   if(zeroFound)
    break;
  }
  if(zeroFound)
   singleZero=true;
 }
 bool rowUpdate=true;
 while(rowUpdate)
 {
  rowUpdate=false;
  //iterate through markedRow
  for(int i=0;i<N;i++)
  {
   //check if row is unassigned
   if(markedRow[i]==true)
   {
    //iterate through unassigned row
    for(int j=0;j<N;j++)
    {
     //if there is an zero in the row, mark the corresponding col and row assigned to that col
     if(markedCol[j]==false && matrix[i][j].first==0)
     {
      markedCol[j] = true;
      for(int k=0;k<N;k++)
      {
       if(markedRow[k]==false && matrix[k][j].first==0 && tick[k][j]==true)
       {
        rowUpdate=true;
        markedRow[k]=true;
        break;//move on to next col in unassigned row
       }
      }
     }
    }
   }
  }
 }
 //iterate through markedRow and markedCol
 for(int i=0;i<N;i++)
 {
  //if row not marked, draw line at row
  if(markedRow[i]==false)
  {
   numLine++;
   for(int j=0;j<N;j++)
    matrix[i][j].second=true;
  }
  //if col marked, draw line at col
  if(markedCol[i]==true)
  {
   numLine++;
   for(int k=0;k<N;k++)
    matrix[k][i].second=true;
  }
 }
 intersection.clear();
 intersection.shrink_to_fit();
 //interate through markedRow and markedCol and record the intersections
 for(int i=0;i<N;i++)
 {
  if(markedRow[i]==false)
   for(int j=0;j<N;j++)
    if(markedCol[j]==true)
     intersection.push_back(make_pair(i, j));
 }
 return numLine;
}
 
void print(vector<vector<pair<int,bool>>> &matrix)
{
 for(auto &temp:matrix)
 {
  for(auto x : temp)
   cout<<x.first<<" ";
  cout<<'\n';
 }
 cout<<'\n';
 for(auto &temp:matrix)
 {
  for(auto x:temp)
   cout<<x.second<<" ";
  cout<<'\n';
 }
 cout<<'\n';
}
 
void printA(vector<vector<bool>> &matrix)
{
 for(auto &temp:matrix)
 {
  for(auto x:temp)
   cout<<x<<" ";
  cout<<'\n';
 }
 cout<<'\n';
}

int main()
{
 Hungarian();
 return 0;
}
