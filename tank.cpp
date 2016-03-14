//
// Created by Polik on 11.03.2016.
//

#include <iostream>
#include "tank.h"
#include "bullet.h"

#include "win_console.h"

void tank::initWorld(int wX, int wY, int bX, int bY)
{
    worldX=wX;
    worldY=wY;
    blockX=bX;
    blockY=bY;
};

void tank::init(){

        x=10;
        y=5;
        lives=5;
        dir=UP;
        isAlive = true;
        isMove = true;


}

void tank::_isMoveAval()
{
    // check borders
    isMove=true;

    if(y==0 && dir==UP)     isMove = false;
    if(y==27 && dir==DOWN)  isMove = false;
    if(x==0 && dir==LEFT)   isMove = false;
    if(x==54 && dir==RIGHT) isMove = false;

}

void tank::move()
{
    _isMoveAval();

    if(isMove)
    {

        switch (dir)
        {
            case UP:
            {
                --y;
                break;
            }
            case DOWN:
            {
                ++y;
                break;
            }
            case LEFT:
            {
                x-=2;
                break;
            }
            case RIGHT:
            {
                x+=2;
                break;
            }
        }
    }
}

void tank::change_pos(int aX, int aY)
{
    x=aX;
    y=aY;
}

bool tank::change_dir(eDirection aDir)
{
    bool f = true;
    if(dir!=aDir) f=false;
    dir=aDir;
    return f;
}

void tank::get_hit()
{
    --lives;
    if (!lives) isAlive= false;
}

void tank::fire()
{
    bullet tmpBul = bullet();
    tmpBul.initWorld(worldX,worldY,blockX,blockY);
    tmpBul.setPos(x,y);
    tmpBul.setDir(dir);
//    tmpBul.bulDraw;
}

void tank::t_draw()
{
    set_position(x,y);

    switch (dir)
    {


        case UP:
        {
            set_position(x,y);
            printf("  %c%c  ",223,223);
            set_position(x,y+1);
            printf("%c%c  %c%c",219,219,219,219);
            set_position(x,y+2);
            printf("%c%c  %c%c",219,219,219,219);

            break;
        }

        case DOWN:
        {
            set_position(x,y);

            printf("%c%c  %c%c",219,219,219,219);
            set_position(x,y+1);
            printf("%c%c  %c%c",219,219,219,219);
            set_position(x,y+2);
            printf("  %c%c  ",220,220);

            break;
        }

        case RIGHT:
        {
            set_position(x,y);
            printf("%c%c%c%c",219,219,219,219);
            set_position(x,y+1);
            printf("     %c",254);
            set_position(x,y+2);
            printf("%c%c%c%c",219,219,219,219);

            break;
        }

        case LEFT:
        {
            set_position(x,y);
            printf("  %c%c%c%c",219,219,219,219);
            set_position(x,y+1);
            printf("%c",254);
            set_position(x,y+2);
            printf("  %c%c%c%c",219,219,219,219);

            break;
        }
    }

}
