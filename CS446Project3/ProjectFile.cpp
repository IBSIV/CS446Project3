#include <stdio.h>
//
// You may need to change the directory for the gl.h and glut.h
//
#include<stdio.h>
#include <GL/glut.h>


void keyboard (unsigned char key, int x, int y);
void mouse (int button, int state, int x, int y);
void init (void);
void display(void);

int pts[100][2];
int num_pts = 0;

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Shading Exercise");
    init ();
    glutDisplayFunc(display); 
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}


void keyboard (unsigned char key, int x, int y)
{ int i;

  switch (key)
    {
    case 'q':
      // 
      // Fill your code: call exit function
      //
      break;
    default:
      break;
    }
  }


void mouse (int button, int state, int x, int y)
{   
  int i;

  switch (button)
    {
    case GLUT_LEFT_BUTTON:
      if (state == GLUT_DOWN) {
	//
	// Fill your code: insert the current mouse postion (x,y) to the array/list
	//
	glutPostRedisplay();
      }
      break;
    case GLUT_RIGHT_BUTTON:
      if (state == GLUT_DOWN) {
	//
	// For CS446G only: 
        // Fill your code: remove relevant points 
	//
	glutPostRedisplay();
      }
      break;
    default:
      break;
    }
}

void init (void) 
{
    /*  select clearing (background) color       */
    glClearColor (0.0, 0.0, 0.0, 0.0);

    /*  initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void display(void)
{
  int i; 

  /*  clear all pixels  */
  glClear (GL_COLOR_BUFFER_BIT);

  /* Write code to display all lines */
  glColor3f (1.0, 1.0, 1.0);

  //
  // Fill your code: display
  //
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      //glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2i(0, 0);    // x, y
      glVertex2i(20, 0);
      glVertex2i(20, 20);
      glVertex2i(0,  20);
   glEnd();

  /*  don't wait!  
   *  start processing buffered OpenGL routines 
   */
  glFlush ();
}

