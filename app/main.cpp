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
#include "Character.h"

using namespace std;

void *font = GLUT_BITMAP_TIMES_ROMAN_24;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};
char defaultMessage[] = "Enter your name ...";
char *message = defaultMessage;
string tmpMessage = "";

void processNormalKeys(unsigned char key, int x, int y) {

    if (key == 27)
    {
        exit(0);
    }
    else
    {
        string s(1, key);
        tmpMessage += s;
        char *cstr = new char[tmpMessage.length() + 1];
        strcpy(cstr, tmpMessage.c_str());
        message = cstr;
    }
}

void selectFont(int newfont)
{
    font = fonts[newfont];
    glutPostRedisplay();
}

void selectMessage(int msg)
{
    switch (msg) {
        case 1:
            message = "abcdefghijklmnop";
            break;
        case 2:
            message = "ABCDEFGHIJKLMNOP";
            break;
    }
}

void selectColor(int color)
{
    switch (color) {
    case 1:
        glColor3f(0.0, 1.0, 0.0);
        break;
    case 2:
        glColor3f(1.0, 0.0, 0.0);
        break;
    case 3:
        glColor3f(1.0, 1.0, 1.0);
        break;
    }
    glutPostRedisplay();
}

void tick(void)
{
   glutPostRedisplay();
}

void output(int x, int y, char *string)
{
    int len, i;

    glRasterPos2f(x, y);
    len = (int) strlen(string);
    for (i = 0; i < len; i++) {
      glutBitmapCharacter(font, string[i]);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    output(100, 24, "C++ Video Game!");
    output(100, 100, message);
    output(100, 145, "PRESS ESC TO QUIT");
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    int i, msg_submenu, color_submenu;

    glutInit(&argc, argv);
    for (i = 1; i < argc; i++) {
      if (!strcmp(argv[i], "-mono")) {
        font = GLUT_BITMAP_9_BY_15;
      }
    }
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("GLUT bitmap font example");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(tick);
    /*
    msg_submenu = glutCreateMenu(selectMessage);
    glutAddMenuEntry("abc", 1);
    glutAddMenuEntry("ABC", 2);
    color_submenu = glutCreateMenu(selectColor);
    glutAddMenuEntry("Green", 1);
    glutAddMenuEntry("Red", 2);
    glutAddMenuEntry("White", 3);
    glutCreateMenu(selectFont);
    glutAddMenuEntry("9 by 15", 0);
    glutAddMenuEntry("Times Roman 10", 1);
    glutAddMenuEntry("Times Roman 24", 2);
    glutAddSubMenu("Messages", msg_submenu);
    glutAddSubMenu("Color", color_submenu);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    */
    glutKeyboardFunc(processNormalKeys);
    glutMainLoop();
    return 0;
}