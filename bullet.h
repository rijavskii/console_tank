//
// Created by Polik on 12.03.2016.
//
#include "tank.h"

#ifndef TANKS_BULLET_H
#define TANKS_BULLET_H


class bullet {

private:
    int bltX;
    int bltY;

    int speed;

    bool isExist = true;
    tank::eDirection bulDir;

    int worldX;
    int worldY;
    int blockX;
    int blockY;

    char bltSym='*';


private:

    bool _isMoving();

public:

    void initWorld(int wX, int wY, int bX, int bY);
    void setPos(int x, int y);
    void setDir(tank::eDirection dir);
    void bulDraw();

};


#endif //TANKS_BULLET_H
