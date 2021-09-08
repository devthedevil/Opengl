#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>

struct points
{
    GLfloat x,y,z;
};

struct points p[10000];
int count = 0;

void readInput()
{
  FILE *fptr = fopen("input5.txt", "r");
    if(fptr)
    {
        while(fscanf(fptr, "%f %f %f",&(p[count].x), &(p[count].y),&(p[count].z)) != EOF)
        {
            count++;
        }
        fclose(fptr);
    }
}

void renderfunc()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glBegin(GL_QUADS);

    glColor3f(1,0,0);
    glVertex3f(p[0].x,p[0].y,p[0].z);
    glVertex3f(p[1].x,p[1].y,p[1].z);
    glVertex3f(p[2].x,p[2].y,p[2].z);
    glVertex3f(p[3].x,p[3].y,p[3].z);

    glColor3f(0,1,0);
    glVertex3f(p[4].x,p[4].y,p[4].z);
    glVertex3f(p[5].x,p[5].y,p[5].z);
    glVertex3f(p[6].x,p[6].y,p[6].z);
    glVertex3f(p[7].x,p[7].y,p[7].z);
    glColor3f(0,0,1);
    glVertex3f(p[8].x,p[8].y,p[8].z);
    glVertex3f(p[9].x,p[9].y,p[9].z);
    glVertex3f(p[10].x,p[10].y,p[10].z);
    glVertex3f(p[11].x,p[11].y,p[11].z);

    glEnd();

    glutSwapBuffers();

}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutCreateWindow("window 1");
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize(900,900);
glEnable(GL_DEPTH_TEST);
readInput();
glutInitWindowPosition(50, 50);
glOrtho(-1.0, 1.0, -1.0, 1.0,-1.0,1.0);
glutDisplayFunc(renderfunc);
glutMainLoop();
}
