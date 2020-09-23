#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

void init(GLFWwindow* w){

}

void display(GLFWwindow *w, double currentTime) {
  glClearColor(1.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

int main() {
  if (!glfwInit()) {exit(EXIT_FAILURE);}
  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  GLFWwindow * window = glfwCreateWindow(600, 600, "Hello OpenGL", NULL, NULL);
  glfwMakeContextCurrent(window);

  if (glewInit()!=GLEW_OK){exit(EXIT_FAILURE);}
  glfwSwapInterval(1);

  init(window);

  while(!glfwWindowShouldClose(window)) {
    display(window, 0);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  exit(EXIT_SUCCESS);

  return 0;
}