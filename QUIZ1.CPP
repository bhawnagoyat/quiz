#include<iostream.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>
#define false 0
#define true 1
#define bool int

//player class
class contest
{
public:
    float x;
    char name[20];
    char s[1000],ans,city[10];

public:
    contest()
    { x=0; }
    void init();
    void define();
    void display();
    void score();
    void score1();
};
//working of quiz
void  contest :: define()
{
   ifstream in;
   char a,ch[1000];
      int n,k=0;
      gotoxy(5,5);
    cout<<"\t choose one category under which you want to play \n\n";
    cout<<"\t 1. COMPUTER \n"
	<<"\t 2. SCIENCE \n"
	<<"\t 3. G.K \n"
	<<"\t 4. ENGLISH \n"
	<<"\t 5. MATHS\n";
   cin>>n;
   cleardevice();
   switch(n)
   {
     case 1 :
    in.open("computer.txt");
    break;
    case 2:
    in.open("science.txt");
    break;
    case 3:
    in.open("g.k.txt");
    break;
    case 4:
    in.open("english.txt");
    break;
    case 5:
    in.open("math.txt");
    break;
    }
    while(in.eof()==0)
    {
	in.getline(ch,1000);
	  cout<<"\n"<<ch;
		  if(k==4)
	     {
			in.get(a);
			cout<<"\nans:";
			cin>>ans;
k=-2;
			if(ans==a)
			{
			   x=x+2;
			   cout<<" *****Your ans is  correct.\n";
			}
			else
			{
				x=x-1;
				cout<<" #### Wrong ans.... ans is "<<a<<"\n" ;
			}

		}
k++;
    }
   in.close();
   }

//getting player info and displaying result
     void contest :: init()
       {
       int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
    setcolor(11);
    settextstyle(7,0,5);
    outtextxy(100,100," player Name:");
    gotoxy(20,12);
     cin>>name;
     outtextxy(100,180,"  player city:");
     gotoxy(20,16);
     cin>>city;
       }
     void contest :: display()
       {
	 cleardevice();
	 cout<<"          here is your result    \n\n:";
	 cout<<" name of player :"<<name <<"\n\n";
	 cout<<" name of city :"<< city <<"\n\n";
     cout<<"\n *****Result******:\n";
     cout<<"\t  you got total = "<<x<<" marks\n";
     sleep(4);
       }
       void contest :: score1()
{
       fstream in;
       in.open("score.txt",ios::in);
       int c;
       while(in.eof()==0)
       {
	   in>>c;
	   if(c<x)
	   {
		fstream f;
		f.open("score.txt",ios::app);
		f<<endl<<name<<"                  ";
		f<<city<<"                ";
		f<<x;
		f.close();
		break;
	     }
       }
       in.close();

}

void contest:: score()
{
     cleardevice();
    ifstream fin;
    fin.open("score.txt");
    char txt[100];
    while(fin.eof()==0)
    {
	fin.getline(txt,100);
	cout<<txt<<"\n";
    }
    fin.close();
    sleep(5);
}
//author part started
class author
{
   public:

   void add();
   void del();
   void pass();
};
//password access
void author :: pass()
{
    cleardevice();
    char pass[10]="bhawna",pass1[10];
    cout<<"enter password to get access :";
    cin>>pass1;
    if(strcmp(pass1,pass)==0)
    {
      cout<<"\naccess granted \n welcome to admin panel\n";
      }
    else
    {
       cout<<"\nwrong password access denied";
       sleep(2);
       exit(0);
    }
}
void author :: del()
{
    int i,n,j=0;
    char c[1000],c1[100];
    cleardevice();
    fstream co,tem;
    cout<<"\t choose one category under which you want to delete ques \n\n";
    cout<<"\t 1. COMPUTER \n"
	<<"\t 2. SCIENCE \n"
	<<"\t 3. G.K \n"
	<<"\t 4. ENGLISH \n"
	<<"\t 5. MATHS\n";
   cin>>n;
   cleardevice();
   switch(n)
   {
     case 1 :
    co.open("computer.txt",ios::in);
    break;
    case 2:
    co.open("science.txt",ios::in);
    break;
    case 3:
    co.open("g.k.txt",ios::in);
    break;
    case 4:
    co.open("english.txt",ios::in);
    break;
    case 5:
    co.open("math.txt",ios::in);
    break;
   }
    tem.open("temp.txt",ios::out);
    cout<<"number of ques :\n";
    cin>>n;
    i=(n-1)*6;
    int k=i+6;
    cout<<k;
    while(co.eof()==0)
    {
       if(j==i)
       {
	 for(j=i;j<i+6;j++)
	 {
	 co.getline(c,1000);
	 }
       }
       else
       {
	 co.getline(c,1000);
	 tem<<c<<endl;
       }
	j++;
    }
    tem.close();
    co.close();
    cout<<"which file is updated \n";
    cout<<" 1 computer \n";
    cout<<" 2 science \n";
    cout<<" 3 g.k \n";
    cout<<" 4 english \n";
    cout<<" 5 math \n";
    int n1;
    cin>>n1;
switch(n1)
   {
     case 1 :
    rename("temp.txt","computer.txt");
    break;
    case 2:
    rename("temp.txt","science.txt");
    break;
    case 3:
    rename("temp.txt","g.k.txt");
    break;
    case 4:
     rename("temp.txt","english.txt");
    break;
    case 5:
    rename("temp.txt","math.txt");
    break;
   }
remove("temp.txt");
}

void author :: add()
{
    int n;
    char s[2],ques[1000],ans1[50],ans2[50],ans3[50],ans4[50],ans;
    fstream co;
   cout<<"\t choose one category under which you want to add a ques \n\n";
    cout<<"\t 1. COMPUTER \n"
	<<"\t 2. SCIENCE \n"
	<<"\t 3. G.K \n"
	<<"\t 4. ENGLISH \n"
	<<"\t 5. MATHS\n";
   cin>>n;
   cleardevice();
   switch(n)
   {
     case 1 :
    co.open("computer.txt",ios::app);
    break;
    case 2:
    co.open("science.txt",ios::app);
    break;
    case 3:
    co.open("g.k.txt",ios::app);
    break;
    case 4:
    co.open("english.txt",ios::app);
    break;
    case 5:
    co.open("math.txt",ios::app);
    break;
   }

    cout<<"\n enter question number";
    cin>>n;
    co<<endl<<n<<".";
    cout<<"\n enter question :";
     cin.getline(s,2);
   cin.getline(ques,100);
    co<<ques<<endl;
    cout<<"\n ans a :";
    co<<"a)";
    cin.getline(ans1,50);
    co<<ans1<<endl;
    cout<<"\n ans b :";
    cin.getline(ans2,50);
    co<<"b)";
    co<<ans2<<endl;
    cout<<"\n ans c:";
    cin.getline(ans3,50);
    co<<"c)";
    co<<ans3<<endl;
    cout<<"\n ans d :";
    cin.getline(ans4,50);
    co<<"d)";
    co<<ans4<<endl;
    cout<<"\n correct ans :";
    cin.get(ans);
    co<<ans;
    co.close();
}

void display()
{
    setcolor(2);
    settextstyle(1,0,6);
    outtextxy(150,50,"..WELCOME..");
    setcolor(10);
    settextstyle(7,0,6);
    outtextxy(0,150,"*** QUIZ CONTEST ***");
    setcolor(13);
    settextstyle(1,0,5);
    outtextxy(250,250,"###Made By: ");
    setcolor(13);
    settextstyle(7,0,5);
    outtextxy(400,300,"BHAWNA");
    sleep(4);


    int  c1;
    contest r;
    author a;
    cleardevice();
    setcolor(12);
    settextstyle(7,0,4);
    outtextxy(100,100," you are player or author ");
    outtextxy(100,150,"press 1 for player");
    outtextxy(100,200," press 2 for author");
    cin>>c1;
    cleardevice();
    switch(c1)
    {
      case 1:
    {
      cleardevice();
      setcolor(13);
      settextstyle(8,0,3);
      outtextxy(100,50,"### player mode ###");
      r.init();
      cleardevice();
      setcolor(14);
      settextstyle(9,0,3);
      outtextxy(100,100,"****** INSTRUCTIONS*******");
      setcolor(9);
      settextstyle(8,0,1);
      outtextxy(0,150," 1. there will be 5 categories according to subject");
      outtextxy(0,175," 2. there will be 20 questions in each category\n");
      outtextxy(0,200,"3. every correct answere will awarded by 2 marks\n");
      outtextxy(0,225,"4. there will be penaulity of 1 mark for each wrong answere\n");
      outtextxy(0,250,"************************************************************\n");
       L:
     outtextxy(0,275,"\n\n\tselect your choice:\n");
	outtextxy(0,300,"1 for start quiz");
	outtextxy(0,325,"2 for quit the quiz :");
	outtextxy(0,350,"3 to see highscore :");
	gotoxy(0,350);
       int c;
       gotoxy(0,350);
       cin>>c;
       cleardevice();
       switch(c)
       {
       case 1:
	r.define();
	r.display();
	break;
       case 2:
	exit(1);
	break;
	case 3 :
	r.score();
	break;
       default:
	cout<<"invalid choice!";
	goto L;
       }
       break;
     }
       case 2:
      {
       a.pass();
       cout<<"what you want to do\n";
       cout<<"1. to delete a question. \n";
       cout<<"2. to add a question.\n";
       cout<<"3. to exit\n";
       int n;
       cin>>n;
	switch(n)
	{
	  case 1:
	  cleardevice();
	  a.del();
	  break;
	  case 2:
	  cleardevice();
	  a.add();
	   break;
	   case 3:
	   exit(0);
	   break;
	  }
	  break;
	}
       default :
       cout<<"enter valid choice\n";
       }
       r.score1();
       closegraph();
       exit(0);

}
void main()
{
   int gdriver = DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\Turboc3\\BGI");
   display();
   getch();
}