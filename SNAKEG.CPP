// Snake Game using graphics and other features.

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>

class SnakeGame
{
 int a,b,c,d,e,f,prev,pres,n,colour,d1,d2,dly,m,sug;
 int xradius,yradius;
 public:
	int score;
	int startx,starty,endx,endy;
	int posn[100][4];
	SnakeGame();
	SnakeGame(SnakeGame*);
	~SnakeGame();
	void over();
	void snakel();
	void init();
	void sugar();
	void transpose();
	void gnrtCond();
	void gnrtUnCond();
	void check();
	void checksugar();
	void move();
	void chngDir();
	void soundeffect();
	void sndCgt();
	int test();
	void scorec();
};

// Default Constructor.
SnakeGame::SnakeGame()
{
 score=0;
}

// Copy Constructor.
SnakeGame::SnakeGame(SnakeGame *p)
{
 *p=NULL;
}

// Destructor.
SnakeGame::~SnakeGame()
{
}

// Function to end the game when the snake is bitten by itself.
void SnakeGame::over()
{
 d2=0;
 sndCgt();
 for(int i=0;i<=7;i++)
 {
  if(i%2)
  {
   setcolor(10);
   outtextxy(512,250,"Game Over");
   delay(900);
  }
  else
  {
   setcolor(0);
   outtextxy(512,250,"Game Over");
   delay(500);
  }
 }
 sleep(1);
}

// Function to control length of the snake.
void SnakeGame::snakel()
{
  int x=getcolor();
  if(sug!=1)
  {
   setcolor(getbkcolor());
   setfillstyle(1,getbkcolor());
   fillellipse(c,d,yradius,yradius);
  }
  else
   sug=0;
  if(sug==2)
   sug--;
  setcolor(colour);
  setfillstyle(1,9);
  if(pres==8 || pres==2)
   fillellipse(posn[0][0],posn[0][1],xradius,yradius);
  else
   if(pres==4 || pres==1)
    fillellipse(posn[0][0],posn[0][1],yradius,xradius);
 setcolor(x);
}

// Function to display playing area of the game.
void SnakeGame::init()
{
 time_t tm;
 srand(time(&tm));
 d1=20;
 n=5;
 prev=4;
 for(int i=4;i>=0;i--)
 {
  posn[i][0]=201+(n-i-1)*d1;
  posn[i][1]=301;
 }
 startx=21;
 starty=21;
 endx=481;
 endy=361;
 colour=14;
 pres=prev;
 d1=20;
 d2=111;
 score=0;
 dly=150;
 xradius=3;
 yradius=9;
 sugar();
 sug=1;
 scorec();
 int x=getcolor();
 setlinestyle(0,1,3);
 setcolor(15);
 rectangle(startx-15,starty-15,endx+15,endy+15);
 rectangle(endx+25,starty-15,getmaxx()-15,endy+15);
 rectangle(startx-15,endy+25,getmaxx()-15,getmaxy()-5);
 line(endx+25,starty+75,getmaxx()-15,starty+75);
 line(endx+25,starty+200,getmaxx()-15,starty+200);
 line(endx+25,starty+275,getmaxx()-15,starty+275);
 setlinestyle(0,1,1);
 settextstyle(8,0,1);
 setcolor(11);
 outtextxy(514,40,"Score");
 setcolor(14);
 settextstyle(11,0,5);
 outtextxy(524,110," CONTROLS ");
 outtextxy(522,135,"P = PAUSE");
 outtextxy(522,155,"R = RESUME");
 outtextxy(522,175,"E = EXIT");
 outtextxy(513,195,"ARROWS");
 outtextxy(512,205,"    -MOVEMENT");
 setcolor(14);
 settextstyle(4,0,9);
 outtextxy(getmaxx()-500,getmaxy()-110,"GAME");
 settextstyle(8,0,1);
 setcolor(x);
}

// Function to add length when sugar is eaten.
void SnakeGame::sugar()
{
 do
 {
  e=(rand()%100)*d1+startx;
  f=(rand()%100)*d1+starty;
 }while(test());
 int x=getcolor();
 setcolor(7);
 setfillstyle(1,random(15)+1);
 fillellipse(e,f,xradius+2,xradius+2);
 setcolor(x);
 sug=2;
}

// Function to control movement.
void SnakeGame::transpose()
{
 int i,j,x,y;
 a=posn[0][0];
 b=posn[0][1];
 if(!sug)
 {
  c=posn[n-1][0];
  d=posn[n-1][1];
 }
 else
  sug=0;
 for(i=n-1;i>=1;i--)
 {
  posn[i][0]=posn[i-1][0];
  posn[i][1]=posn[i-1][1];
 }
}

// Function for checking proper movement.
void SnakeGame::gnrtCond()
{
 if(n<367)
 {
  if(pres==8 && (prev!=8 && prev!=2))
  {
   posn[0][0]=a;
   posn[0][1]=b-d1;
   prev=pres;
  }
  if(pres==4 && (prev!=4 && prev!=1))
  {
   posn[0][0]=a+d1;
   posn[0][1]=b;
   prev=pres;
  }
  if(pres==2 && (prev!=8 && prev!=2))
  {
   posn[0][0]=a;
   posn[0][1]=b+d1;
   prev=pres;
  }
  if(pres==1 && (prev!=1 && prev!=4))
  {
   posn[0][0]=a-d1;
   posn[0][1]=b;
   prev=pres;
  }
 }
}

// Function for checking proper movement.
void SnakeGame::gnrtUnCond()
{
 if(prev==8)
 {
  posn[0][0]=a;
  posn[0][1]=b-d1;
 }
 if(prev==4)
 {
  posn[0][0]=a+d1;
  posn[0][1]=b;
 }
 if(prev==2)
 {
  posn[0][0]=a;
  posn[0][1]=b+d1;
 }
 if(prev==1)
 {
  posn[0][0]=a-d1;
  posn[0][1]=b;
 }
 a=posn[0][0];
 b=posn[0][1];
}

// Function to check whether snake has bitten itself or not.
void SnakeGame::check()
{
 if(a>endx)
  a=startx;
 else
  if(a<startx)
   a=endx;
 if(b>endy)
  b=starty;
 else
  if(b<starty)
   b=endy;
 posn[0][0]=a;
 posn[0][1]=b;
 for(int i=1;i<n;i++)
 {
  if(a==posn[i][0] && b==posn[i][1])
  {
   over();
   break;
  }
 }
}

// Function for introducing new sugar when the old one is eaten.
void SnakeGame::checksugar()
{
 if((e==a) && (f==b))
 {
  soundeffect();
  sugar();
  dly--;
  scorec();
  n++;
 }
}

// Function to control movement of the snake.
void SnakeGame::move()
{
 int st=0;
 do
 {
  if(!kbhit())
  {
   checksugar();
   if(!st)
    snakel();
   else
    st=0;
   delay(dly/4);
   transpose();
   delay(dly/4);
   gnrtUnCond();
   delay(dly/4);
   check();
   delay(dly/4);
  }
  else
  if(d2)
  {
   chngDir();
   gnrtCond();
   check();
   snakel();
   st=1;
  }
 }while(d2);
}

// Function to change the direction of snake.
void SnakeGame::chngDir()
{
 int clr;
 fillsettingstype *p;
 char x=getch();
 if(x==72)
  pres=8;
 else
  if(x==77)
   pres=4;
 else
  if(x==80)
   pres=2;
 else
  if(x==75)
   pres=1;
 else
  if(x=='e')
   over();
 else
  if(x=='p')
  {
   int twnkl = 1;
   settextstyle(11,0,9);
   while(1)
   {
    if(kbhit())
    {
     int c=getch();
     if(c=='g')
     {
      clr=getcolor();
      setcolor(0);
      rectangle(endx+40,endy-10,getmaxx()-35,getmaxy()-160);
      outtextxy(endx+60,endy-29,"PAUSE");
      break;
     }
    }
   else
   {
    if(twnkl%2)
    {
     clr = getcolor();
     setcolor(10);
     rectangle(endx+40,endy-10,getmaxx()-35,getmaxy()-160);
     outtextxy(endx+60,endy-29,"PAUSE");
     setcolor(clr);
     delay(1000);
    }
    else
    {
     clr = getcolor();
     setcolor(0);
     rectangle(endx+40,endy-10,getmaxx()-35,getmaxy()-160);
     outtextxy(endx+60,endy-29,"PAUSE");
     delay(1000);
    }
   }
   twnkl++;
  }
  settextstyle(8,0,1);
 }
}

// Function for producing sound effect.
void SnakeGame::soundeffect()
{
 nosound();
 sound(2500);
 delay(2);
 nosound();
}

// Function for sound effect when game is over.
void SnakeGame::sndCgt()
{
 nosound();
 for(int x=1000;x>0;x--)
 {
  sound(x);
  delay(1);
 }
 nosound();
}

// Function for testing.
int SnakeGame::test()
{
 for(int i=0;i<n;i++)
 {
  if(e==posn[i][0] && f==posn[i][1])
    break;
  if(c==e && d==f)
   break;
  if((e>=endx+1) || (f>=endy+1))
   break;
 }
 if(i!=n)
  return 1;
 else
  return 0;
}

// Function to calculate score of the game.
void SnakeGame::scorec()
{
 char *p;
 ltoa(score,p,10);
 settextstyle(8,0,1);
 setcolor(0);
 outtextxy(585,40,p);
 if(sug!=1)
 {
  score=score+1;
 }
 ltoa(score,p,10);
 setcolor(10);
 outtextxy(585,40,p);
}

void main()
{
 SnakeGame snake;
 int gd=DETECT,gm,i,j,k,x,y;
 clrscr();
 initgraph(&gd,&gm,"C:\\TC\\BGI");
 snake.init();
 snake.move();
 closegraph();
 restorecrtmode();
}
