//#include <windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>

#include "declaration.cpp"
#include "draw.cpp"
#include "move.cpp"
#include "keyboard.cpp"

double width = 1366, height = 768, WL=BEHIND+WALK, WR=width-BEHIND-WALK; //initial size of screen
double seg_len;//segment length for other car
int game_state;
//Game State Values 1 = Start Menu 2 = In Action 3 = Pause MenuS 4 = Quit 5 = Exit- ThankYou Screen

//Main car Variables
bool car_left, car_right;
int car_x = (width/2), car_y = PADDING_BELOW;
int FPS = 60, UNIT_MOVE;//Frame per second and per key  stroke move

//ocar Variables
float ocar_pos[MAX_MAX_OCAR][2];
bool ocar_present[MAX_MAX_OCAR],ocar_shape[MAX_MAX_OCAR];
int MAX_OCAR, OCAR_COUNT, ocar_speed[MAX_MAX_OCAR], ocar_color[MAX_MAX_OCAR][3];

//Score Variables
int curr_score, high_score = 100;


void set_settings()
{
    MAX_OCAR=12;
    UNIT_MOVE=5;//for keyboard left right arrow key
    int possible_len = (WR-WL)/MAX_OCAR;

    if( possible_len < 2*VARZ )
    {
        MAX_OCAR = (WR-WL)/(2*VARZ);
    }
    seg_len = (WR-WL)/MAX_OCAR;//width/MAX_BOMB
}

void myinit()
{
    set_settings(); //for initialize settings

    car_left = false, car_right = false, game_state = 1;
    OCAR_COUNT = 0;//highest can be MAX_OCAR;
    curr_score = (-1)*MAX_OCAR;
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize((int) width, (int) height);
    glutCreateWindow("CAR GAME");
    glutFullScreen();
    myinit();

    glutReshapeFunc(reshape); // in draw.cpp
    glutDisplayFunc(maindisp);// in draw.cpp
    glutKeyboardFunc(normal_key);// in keyboard.cpp
    glutSpecialFunc(keyboard_func);// in keyboard.cpp
    glutSpecialUpFunc(keyboard_up_func);// in keyboard.cpp
    glutTimerFunc(100, timer_func, 0);// in move.cpp
    glutMainLoop();

    return 0;
}
