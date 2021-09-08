#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
using namespace std;

float x[20];
float y[20];
int number_of_points=0;

void read_input(){
    FILE *f  = fopen("input6.txt", "r"); // read only
    if (!f) {
      printf("Error! Could not open file\n");
    }
    float number1;
    float number2;
    int i=0;
    while (!feof(f)){
        fscanf(f, "%f ", &number1);
        x[i]=number1;
        printf("x[i] = %f\n", x[i]);

        fscanf(f, "%f\n", &number2);
        y[i]=number2;
        printf("y[i] = %f\n", y[i]);

        i++;
    }
    number_of_points = i;
}

void render(){
    float red = 1.0;
    float green = 1.0;
    float blue = 1.0;
    float alpha = 1.0;
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);

    int i=0;

    i=0;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    {
        for(int i=0; i<number_of_points;i++){
            for(int j=i+1; j<number_of_points; j++){
                if(j!=0){
                    glVertex2f(x[i], y[i]);
                    glVertex2f(x[j], y[j]);
                }
            }
        }
    }
    glEnd();


    glFlush();
}

//void reshape(int w, int h){
//    glViewport(0,0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-1.25, 1.25, -1.25, 1.25);
//    glMatrixMode(GL_MODELVIEW);
//
//}


int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Window 1");
    read_input();
    glutDisplayFunc(render);
//    glutReshapeFunc(reshape);
    glutMainLoop();
}


/*
0.7 0.5
1.0 1.0
0.8 0.3
0.3 0.8
0.0 -0.7
-0.5 -0.5
0.2 -0.4
-0.7 0.9
*/





