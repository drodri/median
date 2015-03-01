#pragma once
#include <stdlib.h>

#define GLFW_INCLUDE_GLU
#include <diego/glfw/include/GLFW/glfw3.h>

#include "generator.h"


void reshape( GLFWwindow* window, int w, int h ){
   glViewport( 0, 0, (GLsizei)w, (GLsizei)h );

   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();

   gluPerspective( 45,
                   (GLfloat)w / (GLfloat)h,
                   1.0,
                   100);

   glMatrixMode( GL_MODELVIEW );
   glLoadIdentity();

   gluLookAt( 0.0, 1.0, 15.0,/* eye */
              0.0, 0.0, 0.0,            /* center of vision */
              0.0, 1.0, 0.0 );         /* up vector */
}


void DrawGrid( void ){
   int num_cells = 50;
   int size = 1;
   glLineWidth(1);
   glColor3f(1, 0.5, 0.5);
    
    glBegin(GL_LINES); 
      for(int i=0;i<num_cells;i++)
      {
        glVertex3f(i*size,-num_cells*size,0);
        glVertex3f(i*size,num_cells*size,0);      
        glVertex3f(-i*size,-num_cells*size,0);
        glVertex3f(-i*size,num_cells*size,0);     
    
        glVertex3f(-num_cells*size,i*size,0);
        glVertex3f(num_cells*size,i*size,0);        
        glVertex3f(-num_cells*size,-i*size,0);
        glVertex3f(num_cells*size,-i*size,0);       
      }
    glEnd();  
}

void draw_function(const std::vector<Point2d>& v){
  glBegin(GL_LINE_STRIP); 
  for (int i=0;i<v.size();i++)
     glVertex3f(v[i].x,v[i].y,0);       
  glEnd();  
}

GLFWwindow* init_window(){
  GLFWwindow* window;

   /* Init GLFW */
   if( !glfwInit() )
      exit(EXIT_FAILURE);

   glfwWindowHint(GLFW_DEPTH_BITS, 16);

   window = glfwCreateWindow( 800, 600, "My signal analyzer", NULL, NULL );
   if (!window){
       glfwTerminate();
       exit( EXIT_FAILURE );
   }

   glfwSetFramebufferSizeCallback(window, reshape);
   glfwMakeContextCurrent(window);
   glfwSwapInterval( 1 );

   int width, height;
   glfwGetFramebufferSize(window, &width, &height);
   reshape(window, width, height);

  glClearColor( 0.75f, 0.75f, 0.75f, 0.f );
   glShadeModel( GL_FLAT );
   return window;
}

