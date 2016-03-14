#include <iostream>
#include "tank.h"
#include "bullet.h"
#include <stdio.h>

#include "win_console.h"
//kjhg

using namespace std;

//global size of gaming world
int gX = 15;
int gY = 15;
int bX = 6;
int bY = 3;


int main()
{

    console_init();

    eCKeyKode keyInput;

    tank pTank;

    pTank.init();
    pTank.initWorld(gX,gY,bX,bY);
    pTank.t_draw();

    bool movFlag;

    while(1)
    {



        keyInput = wait_console_key_press();

        switch(keyInput)
        {
            case KEY_UP:
            {
                movFlag=pTank.change_dir(tank::UP);
                break;
            }
            case KEY_LEFT:
            {
                movFlag=pTank.change_dir(tank::LEFT);
                break;
            }
            case KEY_RIGHT:
            {
                movFlag=pTank.change_dir(tank::RIGHT);
                break;
            }
            case KEY_DOWN:
            {
                movFlag=pTank.change_dir(tank::DOWN);
                break;
            }
            case KEY_ESCAPE:
            {

                break;
            }
            case KEY_ENTER:
            {
                pTank.fire();
            }
            case UNKNOWN:
                break;
        }

        system("cls");
        if (movFlag) pTank.move();
        pTank.t_draw();
        Sleep(33);
        if (keyInput==KEY_ESCAPE) break;
    };

    return 0;
}