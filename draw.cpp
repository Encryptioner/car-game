/* fumctions for drawing and rendering of each frame*/
//#include <windows.h>//
#include <bits/stdc++.h>
#include "declaration.cpp"
#include <unistd.h>
using namespace std;

void exit_game()
{
    cout<<"Your Score : "<<curr_score<<"\n";
    exit(0);
}

void draw_car(int x, int y)
{
    glPushMatrix();
    glTranslatef(x,y,0);

    glColor3f(1, 0, 0);//back window
    glBegin(GL_LINE_LOOP);
    glVertex2f(-VARA,0);
    glVertex2f(VARA,0);
    glVertex2f(-VARA/2.0,VARB/5.0);
    glVertex2f(VARA/2.0,VARB/5.0);
    glEnd();

    glColor3f(0, 0, 1);//hood
    glBegin(GL_POLYGON);
    glVertex2f(-VARA/2.0,VARB/5.0);
    glVertex2f(VARA/2.0, VARB/5.0);
    glVertex2f(VARA/2.0,(VARB*3.0)/5.0);
    glVertex2f(-VARA/2.0,(VARB*3.0)/5.0);
    glEnd();

    glColor3f(0, 0, 0);//front window
    glBegin(GL_LINE_LOOP);
    glVertex2f(-VARA/2.0,VARB*3.0/5.0);
    glVertex2f(VARA/2.0,VARB*3.0/5.0);
    glVertex2f(-VARA, (4.0*VARB)/5.0);
    glVertex2f(VARA,(4.0*VARB)/5.0);
    glEnd();

    glColor3f(1, 1, 0);//front hood
    glBegin(GL_LINE_LOOP);
    glVertex2f(-VARA, (4.0*VARB)/5.0);
    glVertex2f(VARA,(4.0*VARB)/5.0);
    glVertex2f(-VARA, VARB);
    glVertex2f(VARA, VARB);
    glEnd();

    glColor3f(1, 1, 1);//left window
    glBegin(GL_LINE_LOOP);
    glVertex2f(-VARA, (4.0*VARB)/5.0);
    glVertex2f(-VARA/2.0,VARB*3.0/5.0);
    glVertex2f(-VARA,0);
    glVertex2f(-VARA/2.0,VARB/5.0);
    glEnd();

    glColor3f(1, 1, 1);//right window
    glBegin(GL_LINE_LOOP);
    glVertex2f(VARA, (4.0*VARB)/5.0);
    glVertex2f(VARA/2.0,VARB*3.0/5.0);
    glVertex2f(VARA,0);
    glVertex2f(VARA/2.0,VARB/5.0);
    glEnd();

    glPopMatrix();
    glFlush();
}

void draw_ocars()
{
    int i;
    if(OCAR_COUNT!=MAX_OCAR)
    {
        for(i=0;i<MAX_OCAR;i++)
            if(ocar_present[i]==false)
            {
                ocar_present[i] = true;
                ocar_pos[i][0] = WL + VARZ + rand()%(int(seg_len-2*VARZ))+ (seg_len*i);
                ocar_pos[i][1] = height-(VARZ)+rand()%VARZ;

                ocar_speed[i] = OCAR_MIN_SEC + (rand()%((int)(OCAR_MAX_SEC-OCAR_MIN_SEC+1)));
                ocar_shape[i] = 1;
                ocar_color[i][0] = rand()%10000;
                ocar_color[i][1] = rand()%10000;
                ocar_color[i][2] = rand()%10000;
                OCAR_COUNT++;
            }
    }
    for(i=0;i<MAX_OCAR;i++)
    {
        glPushMatrix();
        glTranslatef(ocar_pos[i][0],ocar_pos[i][1],0);
        glColor3f(0.0001 + ocar_color[i][0]/10000.0, 0.0001 + ocar_color[i][1]/10000.0, 0.0001 + ocar_color[i][2]/10000.0);
        if(ocar_shape[i])
        {
            glBegin(GL_POLYGON);//Left
            glVertex2f(-VARZ,-VARZ);
            glVertex2f(-VARZ/2.0,-VARZ);
            glVertex2f(-VARZ/2.0,VARZ);
            glVertex2f(-VARZ,VARZ);
            glEnd();

            glBegin(GL_POLYGON);//Right
            glVertex2f(VARZ/2.0,-VARZ);
            glVertex2f(VARZ,-VARZ);
            glVertex2f(VARZ,VARZ);
            glVertex2f(VARZ/2.0,VARZ);
            glEnd();

            glColor3f(0.0001 + ocar_color[i][2]/10000.0 , 0.0001 + ocar_color[i][0]/10000.0 , 0.0001);
            glBegin(GL_LINE_LOOP);//Middle
            glVertex2f(-VARZ/2.0,-VARZ);
            glVertex2f(VARZ/2.0,-VARZ);
            glVertex2f(-VARZ/2.0,VARZ);
            glVertex2f(VARZ/2.0,VARZ);
            glEnd();
        }
        glPopMatrix();
    }
}

void draw_background2()
{
    int i;
    for(i=0;i<=10;i++)
    {
        glBegin(GL_QUADS);//Left green background
        if(i%2){glColor3f(0,0.4,0);}
        else{glColor3f(0,0.3,0);}
        glVertex2f(0, height*i/10);
        glVertex2f(BEHIND, height*i/10);
        glVertex2f(BEHIND, height*(i+1)/10);
        glVertex2f(0, height*(i+1)/10);
        glEnd();

        glBegin(GL_QUADS);//Right green background
        if(i%2){glColor3f(0,0.4,0);}
        else{glColor3f(0,0.3,0);}
        glVertex2f(width-BEHIND, height*i/10);
        glVertex2f(width, height*i/10);
        glVertex2f(width, height*(i+1)/10);
        glVertex2f(width-BEHIND, height*(i+1)/10);
        glEnd();

        glBegin(GL_QUADS);//left walkway
        if(i%2){glColor3f(0.3,0,0);}
        else{glColor3f(0.4,0,0);}
        glVertex2f(BEHIND, height*i/10);
        glVertex2f(BEHIND+WALK, height*i/10);
        glVertex2f(BEHIND, height*(i+1)/10);
        glVertex2f(BEHIND+WALK, height*(i+1)/10);
        glEnd();

        glBegin(GL_QUADS);//Right walkway
        if(i%2){glColor3f(0.3,0,0);}
        else{glColor3f(0.4,0,0);}
        glVertex2f(width-BEHIND, height*i/10);
        glVertex2f(width-BEHIND-WALK, height*i/10);
        glVertex2f(width-BEHIND, height*(i+1)/10);
        glVertex2f(width-BEHIND-WALK, height*(i+1)/10);
        glEnd();

        glBegin(GL_QUADS);//Road Divider
        if(i%2){glColor3f(1,1,1);}
        else{glColor3f(0.2,0.2,0.2);}
        glVertex2f(width/2-WALK/3, height*i/10);
        glVertex2f(width/2+WALK/3, height*i/10);
        glVertex2f(width/2+WALK/3, height*(i+1)/10);
        glVertex2f(width/2-WALK/3, height*(i+1)/10);
        glEnd();
    }
}

void draw_background()
{
    glBegin(GL_QUADS);//Road
    glColor3f(0.2,0.2,0.2);
    glVertex2f(BEHIND+WALK, 0);
    glVertex2f(width-BEHIND-WALK, 0);
    glVertex2f(width-BEHIND-WALK, height);
    glVertex2f(BEHIND+WALK, height);
    glEnd();
    draw_background2();
}

void draw_string(std::string str)
{
    int i, len=str.length();
    for(i=0;i<len;i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *(str.begin()+i));
    }
}

void draw_common()
{
    glPushMatrix();
    glTranslatef((width/2.0) - 250,(height/2.0) - 160, 0);
    // Drawing black empty place for menu
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(500,0);
    glVertex2f(500,300);
    glVertex2f(0,300);
    glEnd();

    glLineWidth(4);// Drawing border
    glColor3f(0.3,0.7,0.5);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0,0);
    glVertex2f(500,0);
    glVertex2f(500,300);
    glVertex2f(0,300);
    glEnd();
}

void draw_my_menu(string s1, string s2, string s3, string s4, int v[4])
{
    draw_common();
        //New matrix is pushed to print
        glLineWidth(1);
        glPushMatrix();
        glTranslatef(v[0], 210, 0);
        glScalef(0.4,0.4,0);
        glColor3f(200/255.0, 55/255.0, 255/255.0);
        draw_string(s1);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(v[1], 150, 0);
        glScalef(0.25,0.25,0);
        glColor3f(1.0, 200/255.0, 100/255.0);
        draw_string(s2);
        glPopMatrix();

        //Includes both start and quit button
        glPushMatrix();
            //Makes start Button
            glTranslatef(90,50,0);
            glPushMatrix();
            glLineWidth(2);
            glColor3f(100/255.0,150/255.0,250/255.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(0,0);
            glVertex2f(140,0);
            glVertex2f(140,45);
            glVertex2f(0,45);
            glEnd();

            glTranslatef(v[2],5,0);
            glScalef(0.25,0.25,0);
            glColor3f(0,1,0);
            draw_string(s3);
            glPopMatrix();

            //makes quit button
            glTranslatef(200,0,0);
            glPushMatrix();
            glLineWidth(2);
            glColor3f(100/255.0,150/255.0,250/255.0);
            glBegin(GL_LINE_LOOP);
            glVertex2f(0,0);
            glVertex2f(140,0);
            glVertex2f(140,45);
            glVertex2f(0,45);
            glEnd();
            glTranslatef(v[3],5,0);
            glScalef(0.25,0.25,0);
            glColor3f(1,0,0);
            draw_string(s4);
            glPopMatrix();


        glPopMatrix();//Includes both start and quit button

    glPopMatrix();//Closing
}

void draw_start_menu()
{
    int s[4] = {110,60,15,30};
    draw_my_menu("CAR GAME", "Press S/Enter or Q/Esc", "START","QUIT", s);
}
void draw_pause_menu()
{
    int p[4] = {90,80,5,30};
    draw_my_menu("Pause Game", "Press P/R or Q/Esc", "RESUME","QUIT", p);
}
void draw_exit_menu()
{
    int e[4] = {110,120,25,40};
    draw_my_menu("Quit Game", "Are You Sure?", "YES","NO", e);
}

string intToString( int number )
{
  ostringstream oss;
  oss<< number;
  return oss.str();
}

void draw_thank_you()
{
    draw_common();

        glPushMatrix();
        glTranslatef(100,220,0);
        glScalef(0.4,0.4,0);
        glColor3f(200/255.0, 55/255.0, 255/255.0);
        draw_string("THANK YOU");
        glPopMatrix();

        glPushMatrix();
        glTranslatef(100,150,0);
        glScalef(0.25,0.25,0);
        glColor3f(1.0, 200/255.0, 100/255.0);

        string s=intToString(curr_score);
        string str = "Your Score : ";
        str+=s;
        draw_string(str);
        glPopMatrix();

        glPushMatrix();
        glTranslatef(100,80,0);
        glScalef(0.25,0.25,0);
        glColor3f(1.0, 200/255.0, 100/255.0);
        s=intToString(high_score);
        str = "High Score : ";
        str+=s;
        draw_string(str);
        glPopMatrix();

    glPopMatrix();//closing

    glFlush();

    sleep(5);//time to show thank you
    //Sleep(3)
    glutSwapBuffers();

    exit_game();
}

void maindisp()
{
    glClearColor(0, 0, 0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    draw_background();

    if(game_state == 1)
    {
        draw_start_menu();
    }
    else if(game_state == 2)
    {
        draw_car(car_x,car_y);
        draw_ocars();
    }
    else if (game_state == 3)
    {
        draw_pause_menu();
    }
    else if(game_state == 4)
    {
        draw_exit_menu();
    }
    else if(game_state == 5)
    {
        draw_thank_you();
    }
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    car_x = (car_x*w)/width;
    width = (double) w;
    height = (double) h;

    seg_len = (WR-WL)/MAX_OCAR;
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
    glMatrixMode(GL_MODELVIEW);
}
