#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<iostream>
#include<stdio.h>
using namespace std;

float parameters[4];

void read_input(){
    FILE *f  = fopen("input1.txt", "r"); // read only
    if (!f) {
      printf("Error! Could not open file\n");
    }
    float number;
    int i=0;
    while(fscanf(f, "%f", &number)==1){
        parameters[i++]=number;
    }
}

void render(){
    float red = parameters[0];
    float green = parameters[1];
    float blue = parameters[2];
    float alpha = parameters[3];
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINT);
    glEnd();
    glFlush();
}


int main(int argc, char**argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Window 1");
    read_input();
    glutDisplayFunc(render);
    glutMainLoop();
}


