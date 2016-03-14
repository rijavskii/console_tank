#include "win_console.h"

#include "windows.h"
using namespace std;


HANDLE gConsoleHandle = 0;

static bool isInit = false;

void console_init()
{
    CONSOLE_CURSOR_INFO cursor_info;
    gConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    system("mode con cols=60 lines=30");
    cursor_info.dwSize   = 20;
    cursor_info.bVisible = 0;
    SetConsoleCursorInfo(gConsoleHandle, &cursor_info);
}

void set_position(int x, int y)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(gConsoleHandle, pos);

}


void print_char(char ch, int x, int y, eCColor color)
{
    COORD pos;
    pos.X = x;
    pos.Y = y;

    SetConsoleCursorPosition(gConsoleHandle, pos);
    SetConsoleTextAttribute(gConsoleHandle, color);
    cout << ch;
}

eCKeyKode wait_console_key_press()
{
    int key = 0;
    key = getch();

    if(key == 0x00 || key == 0xE0)// extended key
    {
        switch(getch())
        {
            case 72:
                return KEY_UP;
            case 75:
                return KEY_LEFT;
            case 77:
                return KEY_RIGHT;
            case 80:
                return KEY_DOWN;
            default:
                return UNKNOWN;
        }
    }

    switch(key)
    {
        case 13:
            return KEY_ENTER;
        case 27:
            return KEY_ESCAPE;
        default:
            return UNKNOWN;
    }

    return UNKNOWN;
}















