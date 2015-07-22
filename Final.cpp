//  Project Stage 06~07 : Final to use with OpenGL

#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <map>
#include <cmath>
#include "Matrix.h"
#include "Vector.h"
#define PI 3.14159

using namespace std;

// coordinates of frame
float array[3][7] = {
    {0.0, 50.0,  0.0, 45.0, 45.0, -5.0,  5.0},
    {0.0,  0.0, 50.0, -5.0,  5.0, 45.0, 45.0},
    {1.0,  1.0,  1.0,  1.0,  1.0,  1.0,  1.0}
};
float (*frame)[7] = array;

// translation matrix
float matrix_trans[3][3] = {
    {1.0, 0.0, 50.0},
    {0.0, 1.0, 0.0},
    {0.0, 0.0, 1.0}
};

// rotation matrix
float matrix_rotat[3][3] = {
    {0.0, -1.0, 0.0},
    {1.0, 0.0, 0.0},
    {0.0, 0.0, 1.0}
};

void init(void) {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
}
 
void draw_axis(void) { 
    // draw coordinate axis
	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 1.0);  // x axis
		glVertex2f(-400.0, 0.0);  
        glVertex2f(400.0, 0.0);

        glColor3f(1.0, 1.0, 1.0);  // y axis
		glVertex2f(0.0, 200.0);  
        glVertex2f(0.0, -200.0);
	glEnd();

    // draw scale
    glBegin(GL_LINES);
        for (int i = -40; i <= 40; i++) {  // x axis
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(10.0*i, 0.0);
            glVertex2f(10.0*i, 3.0);
        }

        for (int i = -20; i <= 20; i++) {  // y axis
            glColor3f(1.0, 1.0, 1.0);
            glVertex2f(0.0, 10.0*i);
            glVertex2f(3.0, 10.0*i);
        }
    glEnd();
}

void draw_frame(void) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            frame[i][j] /= frame[2][j];
        }
    }

    glShadeModel(GL_SMOOTH);
    glBegin (GL_LINES);//draw frame
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(frame[0][0], frame[1][0]);
        glVertex2f(frame[0][1], frame[1][1]);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(frame[0][1], frame[1][1]);
        glVertex2f(frame[0][3], frame[1][3]);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(frame[0][1], frame[1][1]);
        glVertex2f(frame[0][4], frame[1][4]);


        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(frame[0][0], frame[1][0]);
        glVertex2f(frame[0][2], frame[1][2]);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(frame[0][2], frame[1][2]);
        glVertex2f(frame[0][5], frame[1][5]);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(frame[0][2], frame[1][2]);
        glVertex2f(frame[0][6], frame[1][6]);
    glEnd();
}

void draw_frame(Matrix<float> cood) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            cood.array[i][j] /= cood.array[2][j];
        }
    }

    glShadeModel(GL_SMOOTH);
    glBegin (GL_LINES);//draw frame
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(cood.array[0][0], cood.array[1][0]);
        glVertex2f(cood.array[0][1], cood.array[1][1]);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(cood.array[0][1], cood.array[1][1]);
        glVertex2f(cood.array[0][3], cood.array[1][3]);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(cood.array[0][1], cood.array[1][1]);
        glVertex2f(cood.array[0][4], cood.array[1][4]);


        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(cood.array[0][0], cood.array[1][0]);
        glVertex2f(cood.array[0][2], cood.array[1][2]);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(cood.array[0][2], cood.array[1][2]);
        glVertex2f(cood.array[0][5], cood.array[1][5]);

        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(cood.array[0][2], cood.array[1][2]);
        glVertex2f(cood.array[0][6], cood.array[1][6]);
    glEnd();
}

void display() {
    glClear (GL_COLOR_BUFFER_BIT);
 
    draw_axis();

    glLoadIdentity();
    draw_frame();
 
    glFlush ();
}
 
void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    if (w <= h)
        gluOrtho2D (-200.0, 250.0, -100.0*(GLfloat)h/(GLfloat)w,
                    200.0*(GLfloat)h/(GLfloat)w);
    else
        gluOrtho2D (-200.0*(GLfloat)w/(GLfloat)h,
                    250.0*(GLfloat)w/(GLfloat)h, -50.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
}

// rotate
void rotateMatrix(string fromKeyboard) {
  Vector<int> zero(3);
  Vector<int> right(3);
  Vector<int> normal(3);
  Vector<int> falling(3);
  zero >> "0,0,0";
  right >> "90,0,0";
  normal >> "45,-45,-45";
  falling >> "-90,0,0";
  map<string, Vector<int> > ro;
  ro["qz"] = zero;
  ro["qr"] = right;
  ro["qn"] = normal;
  ro["qd"] = falling;
    map<string, Vector<int> >:: iterator it;
    for (it = ro.begin(); it != ro.end(); ++it)
     if (fromKeyboard == it -> first)
       break;
    float sine1 = sin(it -> second.get_Entry(0,0) * PI / 180);
    float cose1 = cos(it -> second.get_Entry(0,0) * PI / 180);
    float sine2 = sin(it -> second.get_Entry(0,1) * PI / 180);
    float cose2 = cos(it -> second.get_Entry(0,1) * PI / 180);
    float sine3 = sin(it -> second.get_Entry(0,2) * PI / 180);
    float cose3 = cos(it -> second.get_Entry(0,2) * PI / 180);
    Matrix<float> cood(3, 7);
    Matrix<float> result(3, 3);
    Matrix<float> initial(3, 3);
    Matrix<float> temp(3, 3);
    initial >> "0,0,50;0,0,0;0,0,1";
    result >> "0,0,50;0,0,0;0,0,1";
    temp >> "0,0,50;0,0,0;0,0,1";
    cood.set_all_elements((float **)array, 3, 7);
    initial.set_specified_element(0, 0, cose1);
    initial.set_specified_element(0, 1, sine1);
    initial.set_specified_element(1, 0, -sine1);
    initial.set_specified_element(1, 1, -cose1);
    temp.set_specified_element(0, 0, cose2);
    temp.set_specified_element(0, 1, sine2);
    temp.set_specified_element(1, 0, -sine2);
    temp.set_specified_element(1, 1, -cose2);
    result.set_specified_element(0, 0, cose3);
    result.set_specified_element(0, 1, sine3);
    result.set_specified_element(1, 0, -sine3);
    result.set_specified_element(1, 1, -cose3);
    temp = initial * temp;
    result = temp * result;
    cood = result * cood;
    /* 
    Matrix<float> rotate1(3, 7);
    Matrix<float> rotate2(3, 7);
    Matrix<float> rotate3(3, 7);
    Matrix<float> translate1(3, 3);
    Matrix<float> translate2(3, 3);
    Matrix<float> translate3(3, 3);
    rotate1 = initial * cood;
    float x = cood.get_Entry(0, 1) - cood.get_Entry(0, 0);
    float y = cood.get_Entry(1, 1) - cood.get_Entry(1, 0);
    translate1 >> "0,0,0;0,0,0;0,0,1";
    translate2 >> "0,0,0;0,0,0;0,0,1";
    translate3 >> "0,0,0;0,0,0;0,0,1";
    translate1.set_specified_element(0, 2, x);
    translate1.set_specified_element(1, 2, y);
    cood = translate1 * cood;
    */
    display();
    glLoadIdentity();
    draw_frame(cood); // draw the frame after transformation
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 'z':
      rotateMatrix("qz");
      break;
    case 'r':
      rotateMatrix("qr");
      break;
    case 'n':
      rotateMatrix("qn");
      break;
    case 'd':
      rotateMatrix("qd");
      break;
  }
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);  //  call the <glutCreateWindow>
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}
