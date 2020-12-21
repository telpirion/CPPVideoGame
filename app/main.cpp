/*
File: main.cpp (app)
Author: Eric Schmidt
Version: 2020-11-29

Entry point for the game.
*/
#include <GLUT/glut.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "Character.h"

using namespace std;


int main(int argc, char **argv)
{

  Character person;
  string name = person.GetName();

  GLFWwindow* window;
  if (!glfwInit())
  {
    fprintf( stderr, "Failed to initialize GLFW\n" );
    getchar();
    exit(EXIT_FAILURE);
  }
  window = glfwCreateWindow(640, 480, name.c_str(), NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(window);
  while (!glfwWindowShouldClose(window))
  {
    float ratio;
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);
    ratio = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef((float)glfwGetTime() * 50.f, 0.f, 0.f, 1.f);
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex3f(-0.6f, -0.4f, 0.f);
    glColor3f(0.f, 1.f, 0.f);
    glVertex3f(0.6f, -0.4f, 0.f);
    glColor3f(0.f, 0.f, 1.f);
    glVertex3f(0.f, 0.6f, 0.f);
    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);
}