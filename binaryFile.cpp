//Data file handling using binary file.

/* 1. Create a file.
   2. Display a file.
   3. Display the details of a given cycle number.
   4. Display the details of cycles of a given manufacturer.
   5. Display the details of cycles in a given price range.
   6. Add the details of a new cycle.
   7. Delete a record from a file.
   8. Modification of a record.
   9. Sorting of records.
   10. Insertion of a record.
   11. Number of cycles and total size.
   12. Modification of a record without using temporary file.
*/

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

class cycle
{
 int cno;       // For cycle number.
 char mno[10];  // For model number.
 char ctype;    // For type of cycle.
 float price;   // For price of cycle.
 int noc;       // For number of cycles.
 char mname[20];// For manufacturer name.
 public:
	void input()
	{
	 cout<<"Enter the cycle number\n";
	 cin>>cno;
	 cout<<"Enter the model number\n";
	 cin>>mno;
	 cout<<"Enter the type of cycle(R,G,N)\n";
	 cin>>ctype;
	 cout<<"Enter the price\n";
	 cin>>price;
	 cout<<"Enter the no of cycles\n";
	 cin>>noc;
	 cout<<"Enter the manufacturer name\n";
	 fflush(stdin);
	 cin.getline(mname, 50);
	}
	void output()
	{
	 cout<<"\nThe cycle number is     :\t";
	 cout<<cno<<'\n';
	 cout<<"The model number is     :\t";
	 cout<<mno<<'\n';
	 cout<<"The type of cycle is    :\t";
	 cout<<ctype<<'\n';
	 cout<<"The price of cycle is   :\t";
	 cout<<price<<'\n';
	 cout<<"The no of cycles are    :\t";
	 cout<<noc<<'\n';
	 cout<<"The manufacturer name is:\t";
	 cout<<mname<<'\n';
	}
	int retcno()
	{
	 return(cno);
	}
	char *retmno()
	{
	 return(mname);
	}
	float retprice()
	{
	 return(price);
	}
};

//To create a binary file which contains the objects of class cycle.
void create()
{
 cycle c;
 char ch;
 ofstream f("factory.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 do
 {
  c.input();
  f.write((char *)&c,sizeof(c));
  cout<<"Do you want to enter more records\n";
  cin>>ch;
 }while(ch=='Y'|| ch=='y');
 f.close();
}

//To display the contents of the above created file.
void display()
{
 ifstream f;
 cycle c;
 f.open("factory.dat",ios::binary);
 if(!(f))
 {
  cout<<"Error in opening file\n";
  return;
 }
 f.read((char *)&c,sizeof(c));
 while(f)
 {
  c.output();
  f.read((char *)&c,sizeof(c));
 }
 f.close();
}

//To display the details of cycle whose number is passed as argument.
void display(int no)
{
 cycle c;
 int flag=-1;
 ifstream f;
 f.open("factory.dat",ios::binary);
 if(!(f))
 {
  cout<<"Error in opening file\n";
  return;
 }
 f.read((char *)&c,sizeof(c));
 while(f)
 {
  if(c.retcno()==no)
  {
   flag=1;
   c.output();
   break;
  }
  f.read((char *)&c,sizeof(c));
 }
 f.close();
 if(flag==-1)
  cout<<"Record not found\n";
}

// To display details of cycles of a given manufacturer.
void display(char mn[])
{
 cycle c;
 int flag=-1;
 ifstream f("factory.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 f.read((char *)&c,sizeof(c));
 while(f)
 {
  int x=strcmp(mn,c.retmno());
  if(x==0)
  {
   flag=1;
   c.output();
  }
  f.read((char *)&c,sizeof(c));
 }
 f.close();
 if(flag==-1)
  cout<<"Record not found\n";
}

// To display the details of cycles whose price lies in the given range.
void display(float l,float u)
{
 cycle c;
 int flag=-1;
 ifstream f("factory.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 f.read((char *)&c,sizeof(c));
 while(f)
 {
  if(c.retprice()>=l && c.retprice()<=u)
  {
   flag=1;
   c.output();
  }
  f.read((char *)&c,sizeof(c));
 }
 f.close();
 if(flag==-1)
  cout<<"Record not found\n";
}

// To append a new record to a file.
void append()
{
 cycle c;
 fstream f("factory.dat",ios::binary|ios::app);
 if(!(f))
 {
  cout<<"Error in finding file\n";
  return;
 }
 cout<<"Enter the new cycle details\n";
 c.input();
 f.write((char *)&c,sizeof(c));
 f.close();
}

// Deletion of a record from a binary file.
void deletion(int cn)
{
 int flag=-1;
 cycle c;
 char ch;
 ifstream f1("factory.dat",ios::binary);
 ofstream f2("temp.dat",ios::binary);
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 f1.read((char *)&c,sizeof(c));
 while(f1)
 {
  if(c.retcno()!=cn)
   f2.write((char *)&c,sizeof(c));
  else
  {
   flag=1;
   cout<<"Do you want the record to be permanently deleted\n";
   cin>>ch;
   if(ch=='Y' || ch=='y')
   cout<<"Deleted\n";
   else
    f2.write((char *)&c,sizeof(c));
  }
  f1.read((char *)&c,sizeof(c));
 }
 f1.close();
 f2.close();
 if(flag==-1)
  cout<<"Record not found\n";
 remove("factory.dat");
 rename("temp.dat","factory.dat");
}

//Modification in a file using sequential processing.
void modify(int bn)
{
 cycle c;
 int flag=0;
 ifstream f1;
 ofstream f2;
 f1.open("factory.dat",ios::binary);
 f2.open("temp.dat",ios::binary);
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 f1.read((char *)&c,sizeof(c));
 while(f1)
 {
  if(c.retcno()==bn)
  {
   flag=1;
   cout<<"Enter the new details\n";
   c.input();
  }
  f2.write((char *)&c,sizeof(c));
  f1.read((char *)&c,sizeof(c));
 }
 if(flag==0)
  cout<<"Record not found\n";
 f1.close();
 f2.close();
 remove("factory.dat");
 rename("temp.dat","factory.dat");
}

//Sorting of records in a binary file.
void sort()
{
 cycle c[100],t;
 int n=0;
 ifstream f1("factory.dat",ios::binary);
 if(!(f1))
 {
  cout<<"Error in opening file\n";
  return;
 }
 f1.read((char *)&c[n],sizeof(cycle));
 while(f1)
 {
  n++;
  f1.read((char *)&c[n],sizeof(cycle));
 }
 f1.close();
 for(int i=1;i<n;i++)
 {
  t=c[i];
  int j=i-1;
  while((j>=0) && (t.retcno()<c[j].retcno()))
  {
   c[j+1]=c[j];
   j--;
  }
  c[j+1]=t;
 }
 ofstream f2("factory.dat",ios::binary);
 if(f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 for(int i=0;i<n;i++)
  f2.write((char *)&c[i],sizeof(cycle));
 f2.close();
}

//Insertion of a new record in a sorted file.
void insertion(cycle ck)
{
 cycle c;
 char found='N';
 ifstream f1("factory.dat",ios::binary);
 ofstream f2("temp.dat",ios::binary);
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f1.read((char *)&c,sizeof(c)))
 {
  if(c.retcno()<ck.retcno())
   f2.write((char *)&c,sizeof(c));
  else
  {
   found='Y';
   f2.write((char *)&ck,sizeof(ck));
   break;
  }
 }
 if(found=='N')
  f2.write((char *)&ck,sizeof(ck));
 else
 {
  while(f1)
  {
   f2.write((char *)&c,sizeof(c));
   f1.read((char *)&c,sizeof(c));
  }
 }
 f1.close();
 f2.close();
 remove("factory.dat");
 rename("temp.dat","factory.dat");
}

//To display the total file size of factory.dat and also the total no of records in the file.
void nor()
{
 cycle c;
 int r;
 ifstream f;
 f.open("factory.dat",ios::binary);
 if(f==NULL)
 {
  cout<<"Error in openiig file\n";
  return;
 }
 f.seekg(0,ios::end);
 long x=f.tellg();
 cout<<"The file size is     :"<<x;
 r=x/sizeof(c);
 cout<<"\nThe no of records are:"<<r<<'\n';
 f.close();
}

// Insertion of a record in a binary file without using temporary file.
void updater()
{
 cycle c;
 int no;
 fstream f("factory.dat",ios::binary|ios::in|ios::app);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f.read((char *)&c,sizeof(c)))
 {
  int x=f.tellg();
  f.seekg(x-sizeof(c));
  c.input();
  f.write((char *)&c,sizeof(c));
  break;
 }
 f.close();
}

int main()
{
 int i,ch,cn;
 char mn[35];
 float l,u;
 cycle cg;
 do
 {
  system("cls");
  cout<<"1. Create a file\n";
  cout<<"2. Display a file\n";
  cout<<"3. Display the details of a given cycle number\n";
  cout<<"4. Display the details of cycles of a given manufacturer\n";
  cout<<"5. Display the details of cycles in a given price range\n";
  cout<<"6. Add the details of a new cycle\n";
  cout<<"7. Delete a record from a file\n";
  cout<<"8. Modification of a record \n";
  cout<<"9. Sorting of records\n";
  cout<<"10.Insertion of a record \n";
  cout<<"11.Total file size and number of cycles\n";
  cout<<"12.Insertion of a record without using temporary file\n";
  cout<<"13.Quit\n";
  cout<<"Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:create();
          Sleep(2000);
	      break;
   case 2:display();
          Sleep(2000);
	      break;
   case 3:cout<<"Enter the cycle number\n";
	      cin>>cn;
	      display(cn);
	      Sleep(2000);
	      break;
   case 4:cout<<"Enter the manufacturer name\n";
	      gets(mn);
	      display(mn);
	      Sleep(2000);
	      break;
   case 5:cout<<"Enter the lower and upper limit\n";
	      cin>>l>>u;
	      display(l,u);
	      Sleep(2000);
	      break;
   case 6:append();
          Sleep(2000);
	      break;
   case 7:cout<<"Enter the cycle number to be deleted\n";
	      cin>>cn;
	      deletion(cn);
	      Sleep(2000);
	      break;
   case 8:cout<<"Enter the cycle number to be modified\n";
	      cin>>cn;
	      modify(cn);
	      Sleep(2000);
	      break;
   case 9:sort();
	      display();
	      Sleep(2000);
	      break;
   case 10:cout<<"\n Enter the details\n";
	       cg.input();
	       insertion(cg);
	       Sleep(2000);
	       break;
   case 11:nor();
           Sleep(2000);
	       break;
   case 12:updater();
	       display();
	       Sleep(2000);
	       break;
   case 13:exit(0);
   default:cout<<"Wrong choice\n";
           Sleep(2000);
  }
 }while(ch!=13);
 return 0;
}
