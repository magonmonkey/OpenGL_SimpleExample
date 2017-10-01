#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
void init(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,300.0,0.0,300.0);
}

void DrawCircle(float cx, float cy, float r)  //to draw an circle at cx,cy with radius r
{    
glBegin(GL_LINE_LOOP);   
    for(float ii = 0.0; ii < 100.0; ii=ii+1)
    {
        float theta = 2.0f * 3.1415926f * ii / 100.0;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void wordDisplay(void){      //to display words
 glColor3f(0,0,1);
 glRasterPos2f(80.0,140.0);    //set the place of words
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'C');   //TIMES_ROMAN with size 24
 glColor3f(1,0,1);
 glRasterPos2f(115.0,140.0);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'A');
 glColor3f(1,0,0);
 glRasterPos2f(150.0,140.0);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'N');
 glColor3f(1,1,0);
 glRasterPos2f(185.0,140.0);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'O');
 glColor3f(0,1,0); 
 glRasterPos2f(220.0,140.0);
 glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'E');
}


void initialPose(void){
glPushMatrix();
 GLUquadricObj* quad=gluNewQuadric();
 glTranslatef(150,100,0); //translate to center
 glColor3f(0,1,0);
 glPushMatrix();  //body
  glRotated(-10,0,0,1);  //rotate object
  glRecti(-8,0,8,-50);
 glPopMatrix();
 glColor3f(0,0,1);
 glPushMatrix();   //left arm
  glRotated(30,0,0,1);
  glRecti(10,5,40,-5);
 glPopMatrix();
 glColor3f(0,0,1);
 glPushMatrix();   //right arm
  glRotated(-45,0,0,1);
  glRecti(5,5,35,-5);
 glPopMatrix();
 glColor3f(1,0,0);
 glPushMatrix();   //head
  glTranslatef(5,20,0);
  gluDisk(quad,0,15,30,30); //gluDisk(inRadius,outRadius,slices,loop)
 glPopMatrix();
glPopMatrix();
}

void boat(void){  //generate the boat
 glPushMatrix();
 glColor3f(1,0.5,0);
  glTranslatef(150,50,0);
  glBegin(GL_QUADS);
   glVertex2f(-90,0);
   glVertex2f(90,0);
   glVertex2f(70,-20);
   glVertex2f(-70,-20);
  glEnd();
 
  
 glPopMatrix();
}

void paddle(void){   
 glPushMatrix();   //generate the paddlec
  glTranslatef(150,100,0);
  glRotated(-15,0,0,1);
  glColor3f(1,0,1);
  glRecti(33,45,37,-80);
 glPopMatrix();
}

void lineSegment(void)
{
 glEnable(GL_LINE_SMOOTH);  //so the circle will be smooth
 glClear(GL_COLOR_BUFFER_BIT);
 glLineWidth(55);
  glColor3f(1.0,1.0,1.0);
  glRecti(30,280,270,150);
  glColor3f(0,0,0);
  DrawCircle(150.0,230.0,35.0);
  glColor3f(0,0,1);
  DrawCircle(70.0,230.0,35.0);
  glColor3f(1,0,0);
  DrawCircle(230.0,230.0,35.0);
  glColor3f(1,1,0);  
  DrawCircle(110.0,200.0,35.0);
  glColor3f(0,1,0);
  DrawCircle(190.0,200.0,35.0);
 glDisable(GL_LINE_SMOOTH);
 wordDisplay();
 initialPose();
 boat(); 
 paddle();
 glFlush();
}

int main(int argc, char** argv)
{
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(300,300);
 glutInitWindowSize(900,900);
 glutCreateWindow("First Project");
 init();
 glutDisplayFunc(lineSegment);
 glutMainLoop();
}
