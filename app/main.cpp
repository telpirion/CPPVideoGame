/*
File: main.cpp (app)
Author: Eric Schmidt
Version: 2020-11-29

Entry point for the game.
*/
#include <GLUT/glut.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "Character.h"

#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
char defaultMessage[] = "Enter your name ...";
char defaultDirections[] = "";
char *message = defaultMessage;
char *directions = defaultDirections;
bool isUserEdited = false;
GLdouble width, height;
int wd;

void init(void)
{
    width  = 1280.0;
    height = 800.0;
    return;
}

void setNewMessage(string tmpMessage)
{
    char *cstr = new char[tmpMessage.length() + 1];
    strcpy(cstr, tmpMessage.c_str());
    message = cstr;
}

void updateMessage(unsigned char key)
{
    if (!isUserEdited)
    {
        isUserEdited = true;
        *message = 0;
    }

    // Backspace (8) or Delete (127); delete a character
    if ((key == 8) || (key == 127))
    {
        int msgLength = strlen(message);

        // Verify that the message is longer than 0
        if (msgLength > 0)
        {
            string tmpMessage(message);
            tmpMessage = tmpMessage.erase(msgLength-1, 1);
            setNewMessage(tmpMessage);
        }

    }
    else
    {
        string s(1, key);
        string tmpMessage(message);
        tmpMessage += s;
        setNewMessage(tmpMessage);

    }
}

void output(int x, int y, char *str)
{
    int len, i;

    glRasterPos2f(x, y);
    len = (int) strlen(str);
    for (i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }
}

/* Callback functions for GLUT */
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    output(100, 700, "C++ Video Game!");
    output(100, 650, message);
    output(100, 600, "PRESS ESC TO QUIT");
    glutSwapBuffers();
    glFlush();
    return;
}

void reshape(int w, int h)
{
    //width = (GLdouble) w;
    //height = (GLdouble) h;

    // Use the whole window for drawing
    //glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, -1.f, 1.f);

    // Maintain constant width & height
    glutReshapeWindow((int) width, (int) height);

    return;
}

void processNormalKeys(unsigned char key, int x, int y)
{

    // ESC key; exit the application
    if (key == 27)
    {
        glutDestroyWindow(wd);
        exit(0);
    }
    // Enter; accept the character's name
    else if (key == 13)
    {

    }
    else
    {
        updateMessage(key);
    }
}

void tick(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    init();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize((int) width, (int) height);
    wd = glutCreateWindow("CPPVideoGame");

    // Register event handlers
    glutReshapeFunc(reshape);
    glutKeyboardFunc(processNormalKeys);
    glutDisplayFunc(display);
    glutIdleFunc(tick);

    glutMainLoop();

    exit(0);
}