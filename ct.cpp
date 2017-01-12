#include<iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>
#include"game.h"
#include <ctime> 
#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib,"glut32.lib")
 GLfloat xRotated, yRotated, zRotated;
 GLfloat x1=-2.9;
 GLfloat y1=2.9;
 GLfloat a1,b1,c1,d1;
 GLfloat xn=0,yn=0;
 GLfloat xtt[20],ytt[20];
 //GLfloat xtt,ytt;
 int n,k;
 //int nc=0,kt=0;
 int kt[20];
 int dem;
 int i=0;
 int c;
void display(void)
{  
	khoitao();
        gluLookAt (xn,yn, 7.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
	 //vẽ mặt phẳng:
	matphang();
	//chinhdiem
	glPushMatrix();
	glTranslatef (x1,y1, 0.0);
	if(y1+0.05>3.0 || y1-0.05<-3.0){y1=2.9;x1=-2.9;glutPostRedisplay();}
	if(x1+0.05>3.0 || x1-0.05<-3.0){x1=-2.9;y1=2.9;glutPostRedisplay();}
	glColor4f(250,0,0,1);
 	glBegin(GL_QUADS);
		glVertex3f(-0.05f,0.05f,0.0f);
		glVertex3f(-0.05f,-0.05f,0.0f);
		glVertex3f(0.05f,-0.05f,0.0f);
		glVertex3f(0.05f,0.05f,0.0f);	
	glEnd();
	glPopMatrix();
	ban2(x1,y1,
	     xtt[0],xtt[1],xtt[2],xtt[3],xtt[4],xtt[5],xtt[6],xtt[7],xtt[8],xtt[9],
	     kt[0], kt[1], kt[2], kt[3], kt[4], kt[5], kt[6], kt[7], kt[8], kt[9]);
	//ban1(x1,y1,xtt,ytt,kt);
	//intro(x1,y1);
   	
   glFlush ();
	 
}


void keyboard (unsigned char key, int x, int y)
{

switch (key) {
case 'd':
x1 = x1 +0.1;

glutPostRedisplay();
break;
case 'a':
x1 = x1-0.1 ;
glutPostRedisplay();
break;
case 'w':
y1 = y1 +0.1;

glutPostRedisplay();
break;
case 's':
y1 = y1-0.1 ;
glutPostRedisplay();
break;


break;
default:
break;
}
}

void animation(void)
{
 for(dem=0;dem<20;dem++){
	if(kt[dem]==0){
 	xtt[dem]=xtt[dem]+0.001;
 	ytt[dem]=ytt[dem]+0.001;
	}else{
 	xtt[dem]=xtt[dem]-0.001;
 	ytt[dem]=ytt[dem]-0.001;
	}
 }
if(i==0){
//khoi tao bo khoitao so ngau nhien
         srand(time(0));
	 n= rand() % 3000+1000;
 	 k = rand() % 4 + 1; 
	}
switch(k){
 
	case 1:
	 x1=x1+0.001;
	xn=-1;yn=0;
		break;
	case 2:
	x1=x1-0.001;
	xn=1;yn=0;
		break;
	
	case 3:
	y1=y1+0.001;
	xn=0;yn=-1;
		break;
	case 4:
	y1=y1-0.001;
	xn=0;yn=1;
		break;
	default:
	xn=0;yn=0;
}	
	i++;
	if(i==n){i=0;k=0;xn=0;yn=0;}
glutPostRedisplay();
}

 
int main(int argc, char** argv)
{
	cout<<"1 lan"<<endl;
   for(dem=0;dem<20;dem++){
		kt[dem]=0;
		xtt[dem]=0;
		ytt[dem]=0;
	}
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (800, 1000);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutIdleFunc(animation);
   glutKeyboardFunc(keyboard);
    glutMainLoop();
   return 0;
}

