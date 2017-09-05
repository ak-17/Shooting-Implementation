#include<bits/stdc++.h>
#include<graphics.h>

using namespace std;
int ex = 300,ey=100;
vector<pair<int,int>>bullet;

void drawbullet(int x,int y)
{
    bar(x-1,y-3,x+1,y+3);
}

void travel(int x,int y)
{
    y-=6;
}

void dissapear()
{
    for(int i=0;i<bullet.size();i++)
    {
        if(bullet[i].second<=0)
        {
            bullet.erase(bullet.begin());
        }
    }
}
bool collide()
{
    for(int i=0;i<bullet.size();i++)
    {
        if(bullet[i].first>=290 && bullet[i].first<=310)
        {
            if(bullet[i].second>=90 && bullet[i].second<=110)
            {
                return true;
            }
        }
    }
    return false;
}

void enemy(int x,int y)
{
    bar(x-10,y-10,x+10,y+10);
}

void rocket(int x,int y)
{
    int length= 20,width =7,wwidth = 10,wheight = 8;

    bar(x-width,y-length,x+width,y+width);
    int arr[8] = {x-width,y-length,x,y-length-3,x+width,y-length,x-width,y-length};
    fillpoly(4,arr);
    int arr2[8] = {x-wwidth,y+wheight,x,y-wheight,x+wwidth,y+wheight,x-wwidth,y+wheight};
    fillpoly(4,arr2);

}
void navigate()
{
    int a = rand()%2;
    if(a==1)
    {
        ex+=10;
    }
    else if(a==0)
    {
        ex-=10;
    }

}
int main()
{
    int gd = DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    int x = 300,y=300;

    bool gameOver = false;
    srand(NULL);
    getch();
    while(!gameOver)
    {
        enemy(ex,ey);
        if(!bullet.empty())
        {
            for(int i=0;i<bullet.size();i++)
            {
                drawbullet(bullet[i].first,bullet[i].second);
                bullet[i].second -= 5;
                //cout<<bullet[i].first<<" "<<bullet[i].second<<endl;
            }
        }
        if(collide())
        {
            gameOver=true;
        }
        dissapear();
        rocket(x,y);
        if(kbhit())
        {
            char c = getch();
            if(c=='a')
            {
                x-=10;
            }
            else if(c=='d')
            {
                x+=10;
            }
            if(c=='k')
            {
                bullet.push_back(make_pair(x,y));
            }
        }
        cout<<ex<<" "<<ey<<endl;
        //navigate();
        delay(100);
        cleardevice();
    }

}
