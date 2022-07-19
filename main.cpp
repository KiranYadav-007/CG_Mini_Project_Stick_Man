//press 's' to stop
//press 'S' to start
//press 'e' to exit
//left click for morning
//right click for evening
//middle click for night

#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float  counter = 0.0;

void myinit()
{
    glClearColor(0, 0, 0, 0); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 950, 0, 700);
    glMatrixMode(GL_MODELVIEW);
}

void man()
{
    glLoadIdentity();
    counter = counter + 0.5;
    if (counter == 800.0)
        counter = -100.0;
    float th;
    glTranslated(counter, 100, 0);
    glLineWidth(7);

    glBegin(GL_LINES);
    glVertex2f(250, 350);
    glVertex2f(250, 150);

    glVertex2f(200, 50);
    glVertex2f(250, 150);

    glVertex2f(300, 50);
    glVertex2f(250, 150);

    glVertex2f(200, 250);
    glVertex2f(300, 250);

    glVertex2f(300, 250);
    glVertex2f(325, 300);

    glVertex2f(200, 250);
    glVertex2f(175, 200);

    glLineWidth(5);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(325, 200);
    glVertex2f(325, 430);

    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 360; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(250 + 50 * cos(th), 350 + 50 * sin(th));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    for (int i = 0; i < 181; i++)
    {
        th = i * (3.1416 / 180);
        glVertex2f(325 + 150 * cos(th), 430 + 150 * sin(th));
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(290, 40);
    glVertex2f(300, 50);
    glVertex2f(325, 50);
    glVertex2f(335, 40);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(190, 40);
    glVertex2f(200, 50);
    glVertex2f(225, 50);
    glVertex2f(235, 40);
    glEnd();
}

void display()
{   
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        man();
        glutSwapBuffers();
        glFlush();
}

void my_key(unsigned char key, int x, int y) {
    switch (key) {
    case 's':
        glutIdleFunc(NULL);
        break;
    case 'S':
        glutIdleFunc(display);
        break;
    case 'e':
        glutDisplayFunc(NULL);
        break;
    default:
        break;
    }
}

void my_mouse(int btn, int st, int x, int y) {
    switch (btn) {
    case GLUT_LEFT_BUTTON:
        if (st == GLUT_DOWN) {
            glClearColor(1, 1, 0, 0); //Background Color-morning
            glClear(GL_COLOR_BUFFER_BIT);
            glutIdleFunc(display);
            break;
        }
    case GLUT_RIGHT_BUTTON:
        if (st == GLUT_DOWN) {
            glClearColor(1.0, 0.5, 0.0, 0.0); //Background Color-evening
            glClear(GL_COLOR_BUFFER_BIT);
            glutIdleFunc(display);
            break;
        }
    case GLUT_MIDDLE_BUTTON:
        if (st == GLUT_DOWN) {
            glClearColor(0.0, 0.0, 0.0, 0.0); //Background Color-night
            glClear(GL_COLOR_BUFFER_BIT);
            glutIdleFunc(display);
            break;
    default:
        break;
        }
    }
}

int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 400);
    glutInitWindowPosition(450, 200);
    glutCreateWindow("Stick Man");
    myinit();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMouseFunc(my_mouse);
    glutKeyboardFunc(my_key);
    glutMainLoop();
    return 0;
}
