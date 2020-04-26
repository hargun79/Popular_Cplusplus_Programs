// Data file handling using Text file.

/* 1. Create a file.
   2. To display the number of alphabets,digits,spaces,special
      characters and total number of characters.
   3. To display the content of text file 'first.txt'.
   4. To create a file 'second.txt' from the file 'first.txt' after
      truncating multiple spaces to a single space.
   5. To create a file 'rev.txt' such that it contains all the lines
      of 'first.txt' but after reversing each of them.
   6. To count and display the lines which starts with letter of
      our choice.
   7. To count a word in the file of our choice.
      (Ignoring case sensitiveness.)
   8. To copy all those words which start from uppercase vowels
      to a new file.
   9. Frequency table of alphabets ignoring case sensitiveness
      of a given text file.
   10.To read a file 'first.txt' created by the user and to
      replace each letter 'a' with 'e'.
   11.To copy lines of text which start with uppercase characters
      from the text file 'first.txt' to 'third.txt.
*/

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

//To create a text file line by line.
void create()
{
 char str[100],ch;
 ofstream f("first.txt");
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 do
 {
  cout<<"Enter a line by pressing enter key \n";
  fflush(stdin);
  cin.getline(str,1000);
  f<<str<<'\n';
  cout<<"Do you wish to continue\n";
  cin>>ch;
 }while(toupper(ch)=='Y');
 f.close();
}

//To display the number of alphabets,digits,spaces,special characters and total number of characters.
void count()
{
 int t=0,v=0,c=0,sp=0,sch=0,d=0;
 char ch;
 ifstream f("first.txt");
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f.get(ch))
 {
  t++;
  if(isalpha(ch))
  {
   switch(ch)
   {
    case 'A':
    case 'a':
    case 'E':
    case 'e':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'U':
    case 'u':v++;
	     break;
    default:c++;
   }
  }
  else
   if(isdigit(ch))
    d++;
  else
   if(ch==' ')
    sp++;
  else
   sch++;
 }
 f.close();
 cout<<"The number of vowels are            :\t"<<v<<'\n';
 cout<<"The number of consonants are        :\t"<<c<<'\n';
 cout<<"The number of digits are            :\t"<<d<<'\n';
 cout<<"The number of spaces are            :\t"<<sp<<'\n';
 cout<<"The number of special characters are:\t"<<sch<<'\n';
 cout<<"The total number of characters are  :\t"<<t<<'\n';
}

//To display the content of text file "first.txt".(Page by page)
void display(char bn[])
{
 char str[80];
 ifstream f;
 f.open(bn);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f)
 {
  f.getline(str,80,'\n');
  cout<<str<<'\n';
 }
 f.close();
}

//To create a file "second.txt" from the file "first.txt" after truncating multiple spaces to a single space.
void replace()
{
 ifstream f1("first.txt");
 ofstream f2("second.txt");
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 int ctr;
 char x;
 while(f1)
 {
  f1.get(x);
  if(x!=' ')
   ctr=1;
  else
   ctr--;
  if(ctr>=0)
   f2.put(x);
 }
 f1.close();
 f2.close();
}

// To create a file "rev.txt" such that it contains all the lines of first.txt but after reversing each of them.
void reverse()
{
 char str[80];
 ifstream f1("first.txt");
 ofstream f2("rev.txt");
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f1)
 {
  f1.getline(str,80,'\n');
  for(int l=0;str[l]!='\0';l++)
   for(int i=0,j=l-1;i<j;i++,j--)
   {
    char t=str[i];
	 str[i]=str[j];
	 str[j]=t;
   }
  f2<<str<<'\n';
 }
 f1.close();
 f2.close();
}

//To count and display the lines which starts with letter of our choice .
void count(char ch)
{
 char str[80];
 int l=0;
 ifstream f("first.txt");
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f)
 {
  f.getline(str,80,'\n');
  if(toupper(str[0])==ch)
  {
   l++;
   cout<<str<<'\n';
  }
 }
 f.close();
}

// To count a word in the file of our choice.(Ignoring case sensitiveness)
void count(char str[80])
{
 ifstream f("first.txt");
 char word[20];
 int c=0;
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f)
 {
  f>>word;
  if((strcmpi(word,str)==0))
   c++;
 }
 f.close();
 cout<<"Number of words are\n"<<c;
}

//To copy all those words which start from uppercase vowels to a new file.
void copy()
{
 char word[20];
 ifstream f1("first.txt");
 ofstream f2("new.txt");
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f1)
 {
  f1>>word;
  if(isalpha(word[0]))
  {
   switch(word[0])
   {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':cout<<word<<' ';
	     f2<<word<<' ';
	     break;
   }
  }
 }
 f1.close();
 f2.close();
}

// Frequency table of alphabets ignoring case sensitiveness of a given text file.
void ftable(char fn[])
{
 int ctr[26];
 char x;
 ifstream f(fn);
 if(f==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 for(int i=0;i<26;i++)
  ctr[i]=0;
 while(f)
 {
  f.get(x);
  if(isalpha(x))
   if(isupper(x))
    ctr[x-'A']++;
  else
   if(islower(x))
    ctr[x-'a']++;
 }
 f.close();
 char ch1='A',ch2='a';
 cout<<"The frequency table is \n"<<'\n'<<"Alphabet"<<"        Count";
 for(int i=0;i<26;i++,ch1++,ch2++)
  if(ctr[i])
   cout<<'\n'<<ch1<<' '<<ch2<<'\t'<<'\t'<<ctr[i]<<'\n';
}

// To read a file "first.txt" created by the user and to replace each letter 'e' with 'a'.(using seekg)
void replaceae()
{
 char ch;
 fstream f("first.txt",ios::in|ios::out);
 if(!(f))
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f)
 {
  f.get(ch);
  if(ch=='E' || ch=='e')
  {
   int x=f.tellg();
   f.seekg(x-(2*sizeof(ch)));
   f<<'a';
  }
 }
 f.close();
}

// To copy lines of text which starts with uppercase characters from the text file "first.txt" to "third.txt". 
void uppercopy()
{
 ifstream f1("first.txt");
 ofstream f2("third.txt");
 char str[80];
 if(f1==NULL || f2==NULL)
 {
  cout<<"Error in opening file\n";
  return;
 }
 while(f1)
 {
  f1.getline(str,80);
  if(isupper(str[0]))
   f2<<str<<'\n';
 }
 f1.close();
 f2.close();
}

int main()
{
 int ch;
 char b[50],c;
 do
 {
  system("cls");
  cout<<" 1. Create a file\n";
  cout<<" 2. To display the number of alphabets,digits,spaces,special\n";
  cout<<"     characters and total number of characters\n";
  cout<<" 3. To display the content of a text file  \n";
  cout<<" 4. To create a file 'second.txt' from the file 'first.txt' after\n";
  cout<<"    truncating multiple spaces to a single space\n";
  cout<<" 5. To create a file 'rev.txt' such that it contains all the lines\n";
  cout<<"    of 'first.txt' but after reversing each of them\n";
  cout<<" 6. To count and display the lines which starts with letter of\n";
  cout<<"    our choice\n";
  cout<<" 7. To count a word in the file of our choice.\n";
  cout<<"    (Ignoring case sensitiveness.)\n";
  cout<<" 8. To copy all those words which start from uppercase vowels\n";
  cout<<"    to a new file\n";
  cout<<" 9. Frequency table of alphabets ignoring case sensitiveness\n";
  cout<<"    of a given text file\n";
  cout<<" 10.To read a file 'first.txt' created by the user and to \n";
  cout<<"    replace each letter 'e' with 'a'\n";
  cout<<" 11.To copy lines of text which start with uppercase characters\n";
  cout<<"    from the text file 'first.txt' to 'third.txt'\n";
  cout<<" 12.Quit\n";
  cout<<"Enter your choice\n";
  cin>>ch;
  switch(ch)
  {
   case 1:create();
	      break;
   case 2:count();
          Sleep(2000);
	      break;
   case 3:cout<<"Enter the name of the file to be opened\n";
	      cin>>b;
	      display(b);
	      Sleep(2000);
	      break;
   case 4:replace();
	      cout<<"Enter the name of the file to be opened\n";
	      cin>>b;
	      display(b);
	      Sleep(2000);
	      break;
   case 5:reverse();
	      cout<<"Enter the name of the file to be opened\n";
	      cin>>b;
	      display(b);
	      Sleep(2000);
	      break;
   case 6:cout<<"Enter the letter of your choice\n";
	      cin>>c;
	      count(c);
	      Sleep(2000);
	      break;
   case 7:cout<<"Enter the word of your choice\n";
	      cin>>b;
	      count(b);
	      Sleep(2000);
	      break;
   case 8:copy();
	      cout<<"Enter the name of the file to be opened\n";
	      cin>>b;
	      display(b);
	      Sleep(2000);
	      break;
   case 9:cout<<"Enter the file whose frequncy table is to be counted\n";
	      cin>>b;
	      ftable(b);
	      Sleep(2000);
	      break;
   case 10:replaceae();
	       cout<<"Enter the name of the file to be opened\n";
	       cin>>b;
	       display(b);
	       Sleep(2000);
	       break;
   case 11:uppercopy();
	       cout<<"Enter the name of the file to be opened\n";
	       cin>>b;
	       display(b);
	       Sleep(2000);
	       break;
   case 12:exit(0);
   default:cout<<"Wrong choice\n";
           Sleep(2000);
  }
 }while(ch!=12);
 return 0;
}
