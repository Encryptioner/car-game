/*Functions for Keyboard operations.*/
#include <bits/stdc++.h>
#include "declaration.cpp"
using namespace std;

//controls Left right arrow key
void keyboard_func(int k, int x, int y)
{
    switch(k)
    {
        case GLUT_KEY_LEFT: car_left = true, car_right = false;
                            break;
        case GLUT_KEY_RIGHT: car_right = true,car_left = false;
                             break;
    }
}
//controls glutSpecialUpFunc
void keyboard_up_func(int k, int x, int y)
{
    switch(k)
    {
        case GLUT_KEY_LEFT: car_left = false;
                            break;
        case GLUT_KEY_RIGHT:car_right = false;
                            break;
    }
}
//For shortcut key
void normal_key(unsigned char k, int x, int y)
{
    switch(k)
    {
        case 27:
        case 'q':
        case 'Q':   game_state = 4;
                    break;
        case ' ':
        case 'p':
        case 'P':   if(game_state == 2) game_state = 3;
                    else if(game_state == 3) game_state = 2;
                    break;
        case 'R':
        case 'r':   if(game_state == 3) game_state = 2;
                    break;
        case 'Y':
        case 'y':   if(game_state == 4) game_state = 5;
                    break;
        case 'N':
        case 'n':   if(game_state == 4) game_state = 3;
                    break;
        case 13:
        case 'S':
        case 's':   if(game_state == 1) game_state = 2;
                    break;
    }
}
