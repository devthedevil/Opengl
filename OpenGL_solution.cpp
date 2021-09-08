#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>
using namespace std;


float vertexx[1000000];  //X coordinate of vertex
float vertexy[1000000];  //Y coordinate of vertex
float vertexz[1000000];  //Z coordinate of vertex

float rotate_y=0; 
float rotate_x=0;

bool rotation;
float start_x;
float start_y;

int VertexCnt = 0;

float zoom = 1.0f;

float pow0_1(int a)  //Calculates (0.1)^(a+1) 
{
    float pow = 1.0;
    for(;a>=0;a--)
        pow *= 0.1;
    return pow;
}
float pow10(int a)  //Calculates 10^(a+1) 
{
    float pow = 1.0;
    for(;a>=0;a--)
        pow *= 10.0;
    return pow;
}
float gen_vertex(char input[15])   // generates vertex
{
    int temp1,temp2;float v;float multipler=0.0000001;
    if(input[0]=='-')
    {
        temp1=(input[1]-48)*1000000+(input[3]-48)*100000+(input[4]-48)*10000+(input[5]-48)*1000+(input[6]-48)*100+(input[7]-48)*10+(input[8]-48)*1;
        temp2=(input[11]-48)*10+(input[12]-48);
        if(input[10]=='-')
            multipler *= pow0_1(temp2);
        else
            multipler *= pow10(temp2);
        v = (float)temp1 * multipler * (-1.0);
    }
    else
    {
        temp1=(input[0]-48)*1000000+(input[2]-48)*100000+(input[3]-48)*10000+(input[4]-48)*1000+(input[5]-48)*100+(input[6]-48)*10+(input[7]-48)*1;
        temp2=(input[10]-48)*10+(input[11]-48);
        if(input[9]=='-')
            multipler *= pow0_1(temp2);
        else
            multipler *= pow10(temp2);
        v = (float)temp1 * multipler;
    }
    return v;
}

void STL_Read()  // reads the input file which is input.txt
{
	char word[15];
    freopen("input.txt","r",stdin);
    cin >> word;cin >> word;cin >> word;cin >> word;cin >> word;
    int i;
    char vertex[15];
    for(i=1;;i++)
    {
        cin >> word;
        if(word[0]=='e')
        {
            break;
        }

        cin >> word;cin >> word;cin >> word;cin >> word;
        cin >> word;cin >> word;
        
        cin >> word;
        cin >> vertex; vertexx[VertexCnt] = gen_vertex(vertex) * 0.1;
		cin >> vertex;  vertexy[VertexCnt] = gen_vertex(vertex)*0.1;
		cin >> vertex; vertexz[VertexCnt] = gen_vertex(vertex)*0.1;
		
		VertexCnt++;

		cin >> word;
        cin >> vertex; vertexx[VertexCnt] = gen_vertex(vertex) * 0.1;
		cin >> vertex; vertexy[VertexCnt] = gen_vertex(vertex)*0.1;
		cin >> vertex; vertexz[VertexCnt] = gen_vertex(vertex)*0.1;
		
		VertexCnt++;

		cin >> word;
        cin >> vertex;  vertexx[VertexCnt] = gen_vertex(vertex) * 0.1;
		cin >> vertex;  vertexy[VertexCnt] = gen_vertex(vertex)*0.1;
		cin >> vertex;  vertexz[VertexCnt] = gen_vertex(vertex)*0.1;

        	VertexCnt++;
		
		cin >> word;
		cin >> word;
    }
    fclose(stdin);
}


void MouseClick(int button, int state, int x, int y)  // identifies the mouse click and zooms/rotates the model accordingly
{
    if (button == GLUT_LEFT_BUTTON){
        if (state == GLUT_DOWN) {
            rotation = true;
            start_x = x;
            start_y = y;;
        }
        else {
            rotation = false;
        }
    }
    else if (button == 3 || button == 4) {
        if (button == 3) {
            zoom += 0.005f;
        }
        else {
            zoom -= 0.005f;
        }
    }
    glutPostRedisplay();
}

void MouseDrag(int x, int y) // identifies the mouse drag and rotates the model accordingly
{
    if (rotation == true){
        rotate_x += y - start_y;
        rotate_y += x - start_x;
        start_x = x;
        start_y = y;
    }
    glutPostRedisplay();
}

void display()  //displays the model
{
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,0.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
    glScalef(zoom,zoom,zoom);
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    for(int i=0;i<VertexCnt;i+=3){
        glBegin(GL_LINE_LOOP);
      glVertex3f(vertexx[i],vertexy[i],vertexz[i]);
      glVertex3f(vertexx[i+1],vertexy[i+1],vertexz[i+1]);
      glVertex3f(vertexx[i+2],vertexy[i+2],vertexz[i+2]);

        glEnd();
    }
    glFlush();
    glutSwapBuffers();
}



int main(int argc, char ** argv)  // our main function where the program starts
{
    STL_Read();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(570,490);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("B170628CS");
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMouseFunc(MouseClick);
    glutMotionFunc(MouseDrag);
    glutMainLoop();
    return 0;
}
