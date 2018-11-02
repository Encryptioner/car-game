/* Fumctions for move every thing. every-time a new frame is rendered*/
#include <bits/stdc++.h>
#include "declaration.cpp"
using namespace std;

void main_car_move()
{
    if(car_left)
    {
        if(car_x>=WL+VARA+UNIT_MOVE)
        {
            car_x -= UNIT_MOVE;
        }
        else
        {
            car_x = WL+VARA;
        }
    }
    else if(car_right)
    {
        if(car_x<=(WR-UNIT_MOVE-VARA))
        {
            car_x += UNIT_MOVE;
        }
        else
        {
            car_x = WR-VARA;
        }
    }
}

void ocar_move()
{
    int i;
    float temps = height/((float)FPS);
    for(i=0;i<MAX_OCAR;i++)
    {
        ocar_pos[i][1] -= temps/(ocar_speed[i]);
        if(ocar_pos[i][1]<=PADDING_BELOW)
        {
            ocar_present[i]=false;
            OCAR_COUNT--;
            curr_score++;
        }
    }
}

bool collison_ocar_car(int ocar_ind)
{
    if(ocar_present[ocar_ind]==0){return false;}

    float A = float(VARA);
    float B = float(VARB);
    float Z = float(VARZ);

    float diffy = (ocar_pos[ocar_ind][1]-Z)- (car_y+B);
    float diffx = 0.0;

    if(ocar_pos[ocar_ind][0]<=car_x)
    {
        diffx = (car_x-A) - (ocar_pos[ocar_ind][0]+Z);//for ocar in left
    }
    else
    {
        diffx = (ocar_pos[ocar_ind][0]-Z) - (car_x+A);
    }

    if(diffy<0.0 && diffx<0.0){return true;}
    else{return false;}
}

void detect_collisions()
{
    int i;
    for(i = 0; i < MAX_OCAR; i++)
    {
        if(collison_ocar_car(i))
        {
            game_state = 5;
        }
    }
}

void timer_func(int v)
{
    //Updates animation
    if(game_state == 2)
    {
        main_car_move();
        ocar_move();
        detect_collisions();
    }
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer_func, v);
}
