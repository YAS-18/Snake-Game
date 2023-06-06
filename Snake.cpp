#include <iostream>
#include<stdlib.h>
#include <conio.h>
#include<unistd.h>
#include<cstdlib>
#include<windows.h>

using namespace std;
int x,y,m,n,Foodx=10,Foody=20;
int tailX[100],tailY[100];
int ntail;
int score;
int over;
int width=60;
int height=30;
enum Direction{Stop=0,Left,Right,Up,Down};
Direction dir;
void set_value()
{
    over=0;
    dir=Stop;
    x=width/2;
    y=height/2;
    Foodx=rand()%width;
    Foody=rand()%height;
    score=0;
}
void design()
{
   // system("cls");
    cout<<"\t\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t\t\t\t\t\t |  C L A S S I C   S N A K E   G A M E  |\n";
    cout<<"\t\t\t\t\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    cout<<"\t\t\t\t\t\t\t\t";
   for(int i=0;i<width;i++)
   {
   	    if(i==0)                      cout<<"|";
        if(i<=width-2)                cout<<"=";
        if(i==width-1)                cout<<"|";
   }
        cout<<endl;
         
    for(int i=0;i<height;i++)
       {
       	   cout<<"\t\t\t\t\t\t\t\t";
           for(int j=0;j<width;j++)
             {
                    if(j==0)                      cout<<"|";
                    if(j==width-1)                cout<<"|";
                    else if(i==height-1)          cout<<"=";
                    else if(i==y&&j==x)           cout<<"$";

                    else if(i==Foody && j==Foodx) cout<<"O";
                    else                        cout<<" ";
             }
             cout<<endl;
       }
       cout<<"\t\t\t\t\t\t\t\t"<<"|                       Score = "<<score<<"                           |"<<endl;
       cout<<"\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void GameOver()
{
	int choice,c;
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t    |  C L A S S I C   S N A K E   G A M E  |\n";
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"\n\n\n\n\n";
	cout<<"\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t\t |      G A M E ~ O V E R    |"<<endl;
    cout<<"\t\t\t\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t\t Score :"<<score<<endl<<endl;
	cout<<"\t\t\t\t\t Press any key countinue.........\n";
	getch();	
}

void input()
{
    char c;
    if(_kbhit())
    {
        c=_getch();
        if((c=='a'||c=='A')&&dir!=Right)      dir=Left;
        else if((c=='d'||c=='D')&&dir!=Left)  dir=Right;
        else if((c=='w'||c=='W')&&dir!=Down)  dir=Up;
        else if((c=='s'||c=='S')&&dir!=Up)    dir=Down;
        else if(c==' ')                       dir=Stop;
    }
}

void control()
{

    switch(dir)
    {
        case Up:
            if(y==0||y==height) over=1;
            else y--;
            break;

        case Down:
            if(y==0||y==height) over=1;
            else y++;
            break;

        case Left:
            if(x==0||x==width) over=1;
            else x--;
            break;

        case Right:
            if(x==0||x==width) over=1;
            else x++;
            break;
    }

}
void Score()
{
    if(x==Foodx&&y==Foody)
    {
        score+=10;
        Foodx=rand()%width-1;
        Foody=rand()%height-1;
    }
}
void Break()
{
        if(y==0||x==width||x==0||y==height)
                over=1;
}
int main()
{
    int choice,c;
    flag:
    do{
    	 cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
         cout<<"\t\t\t\t    |  C L A S S I C   S N A K E   G A M E  |\n";
         cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    	cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t *******************************\n";
        cout<<"\t\t\t\t\t *\t   1.Easy              *"<<endl;
        cout<<"\t\t\t\t\t *\t   2.Medium            *"<<endl;
        cout<<"\t\t\t\t\t *\t   3.Hard              *"<<endl;
        cout<<"\t\t\t\t\t *******************************\n";
        cout<<"\t\t\t\t\t Enter your choice:";
        cin>>c;
    system("cls");
    set_value();
    while(!over)
  {
    design();
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});
    input();
    control();
    Score();
    if(c==1)      _sleep(250);
    else if(c==2) _sleep(150);
    else if(c==3) _sleep(60);

  }
    system("cls");
    GameOver();
    system("cls");
    int choice,c;
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\t\t\t\t    |  C L A S S I C   S N A K E   G A M E  |\n";
    cout<<"\t\t\t\t    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t *******************************\n";
    cout<<"\t\t\t\t\t *          1.Restart          *"<<endl;
    cout<<"\t\t\t\t\t *          2.Quit             *"<<endl;
    cout<<"\t\t\t\t\t *******************************\n";
    cout<<"\t\t\t\t\t Enter your choice:";
    cin>>choice;

        switch(choice)
        {
            case 1:
               system("cls");
               goto flag;
                break;
            case 2:
                return 0;
                break;
            default:
                return 0;
        }
        }
        while(choice==1);
}