#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;


bool gameOver;
const int width=20,height=20;
int x,y,fruitX,fruitY,score;

enum directions{STOP=0,LEFT,RIGHT,UP,DOWN};
directions dir;


void setup(){
    gameOver=false;
    dir=STOP;       //Snake does not move initially
    x=width/2;      //Snake placed at center
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
}

void draw(){
    system("clear");

    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            if(j==0)
                cout<<"#";

            if(i==y && j==x)
                cout<<"O";
            else if(i==fruitY && j==fruitX)
                cout<<"F";
            else        
                cout<<" ";

            if(j==width-1)
                cout<<"#";     
        }
        cout<<endl;
    }
    for(int i=0;i<width+2;i++)
        cout<<"#";
    cout<<endl;
}

void input(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                dir=LEFT;
                break;
            case 'd':
                dir=RIGHT;
                break;
            case 'w':
                dir=UP;
                break;
            case 's':
                dir=DOWN;
                break;
            case 'x':
                gameOver=true;
                break;    
        }
    }
    
}

void logic(){

}


int main(){
    setup();

    while(!gameOver)
    {
        draw();
        input();
        logic();
    }
    return 0;
}