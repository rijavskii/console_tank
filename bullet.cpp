//
// Created by Polik on 12.03.2016.
//

#include "bullet.h"
#include "win_console.h"
#include "tank.h"

void bullet::initWorld(int wX, int wY, int bX, int bY)
{
    worldX=wX;
    worldY=wY;
    blockX=bX;
    blockY=bY;
};


void bullet::setPos(int x, int y)
{
    bltX=x;
    bltY=y;
}

void bullet::setDir(tank::eDirection dir)
{
    bulDir=dir;
}

bool bullet::_isMoving()
{
    if(bltX==0) isExist = false;
    if(bltY==0) isExist = false;
    if(bltX==worldX*blockX) isExist = false;
    if(bltY==worldY*blockY) isExist = false;

    return isExist;
}

void bullet::bulDraw()
{
    while(_isMoving())
    {
        set_position(bltX,bltY);
        printf(" ");

        switch (bulDir)
        {
            case tank::UP:
            {
                --bltY;
                break;
            }
            case tank::DOWN:
            {
                ++bltY;
                break;
            }
            case tank::LEFT:
            {
                --bltX;
                break;
            }
            case tank::RIGHT:
            {
                ++bltX;
                break;
            }


        }

        set_position(bltX,bltY);
        printf("%c",bltSym);

    }
}