#include <vector>

#define GLFW_INCLUDE_GLU
#include <diego/glfw/include/GLFW/glfw3.h>

#include "generator.h"
#include "median.h"
#include "draw_helpers.h"


int main(){
  GLFWwindow* window = init_window();
  MobileAverageFilter median(10);
  std::vector<Point2d> signal, noisy, filtered;

  while(!glfwWindowShouldClose(window)){
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    Point2d v = sin_signal(3);
    signal.push_back(v);
    Point2d vn = add_noise(v, 1);
    noisy.push_back(vn);
    float vf = median.filter(vn.y);
    filtered.push_back(Point2d(vn.x, vf));

    DrawGrid();
    glLineWidth(2);
    glColor3f(0,0,1);
    draw_function(signal);
    glColor3f(1,0,0);
    draw_function(noisy);
    glColor3f(0,1,0);
    draw_function(filtered);

    glFlush();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  exit( EXIT_SUCCESS );
}

