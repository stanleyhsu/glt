#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

void init(GLFWwindow *w)
{
}

void display(GLFWwindow *w, double currentTime)
{
  glClearColor(1.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main()
{
  if (!glfwInit())
  {
    return (-1);
  }

  glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL

  GLFWwindow *window = glfwCreateWindow(600, 600, "Hello OpenGL", NULL, NULL);
  glfwMakeContextCurrent(window);

  if (glewInit() != GLEW_OK)
  {
    return (-1);
  }
  glfwSwapInterval(1);

  init(window);

  while (!glfwWindowShouldClose(window))
  {
    display(window, 0);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return (0);
}