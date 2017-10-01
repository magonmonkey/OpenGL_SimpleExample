#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
static int slices = 32;
static int stacks = 32;


/* GLUT callback Handlers */

static void 
resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    
    glViewport(0, 0, width, height);  //to make view port as same as window size
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 1, 150.0);  //to prevent graphic from distortion
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}

void cylinder(float a,float b,float c){
GLUquadricObj* quad=gluNewQuadric();
gluCylinder(quad, a, b, c, slices, stacks);
glPushMatrix();
glTranslatef(0,0,c);
gluDisk(quad,0,b,slices,stacks);
glPopMatrix();
glPushMatrix();
glRotatef(180,0,1,0);
gluDisk(quad,0,a,slices,stacks);
glPopMatrix();
}

void boat1(){
glBegin(GL_QUAD_STRIP);
glColor3d(1,1,0);
glVertex3f(0,8,-4);
glVertex3f(0,20,0);
glVertex3f(0,7,-4);
glVertex3f(-3,7,0);
glVertex3f(0,0,-4);
glVertex3f(-3,0,0);
glVertex3f(0,-8,-4);
glVertex3f(0,-20,0);
glVertex3f(0,0,-4);
glVertex3f(3,0,0);
glVertex3f(0,7,-4);
glVertex3f(3,7,0);
glVertex3f(0,8,-4);
glVertex3f(0,20,0);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3d(1,1,0);
glVertex3f(0,20,0);
glVertex3f(0,8,-4);
glVertex3f(-3,7,0);
glVertex3f(0,7,-4);
glVertex3f(-3,0,0);
glVertex3f(0,0,-4);
glVertex3f(0,-20,0);
glVertex3f(0,-8,-4);
glVertex3f(3,0,0);
glVertex3f(0,0,-4);
glVertex3f(3,7,0);
glVertex3f(0,7,-4);
glVertex3f(0,8,-4);
glVertex3f(0,20,0);
glVertex3f(0,8,-4);
glEnd();

glBegin(GL_QUAD_STRIP);
glColor3d(1,1,0);
glVertex3f(0,20,0);
glVertex3f(3,7,0);
glVertex3f(-3,7,0);
glVertex3f(3,0,0);
glVertex3f(-3,0,0);
glVertex3f(0,-20,0);
glEnd();
}

void boat2(float t,int c){
glPushMatrix();
glTranslatef(1,18,-1);
glRotatef(-90,0,0,1);
glRotatef(-90,0,1,0);
glColor3d(1,0,0);
cylinder(1.5,1,5);
glPopMatrix();

if(c>=40){
glPushMatrix();
glTranslatef(1,24,-1);
glRotatef(-90,0,0,1);
glRotatef(-90,0,1,0);
glColor3d(0,1,1);
cylinder(1,0.1,4);
glPopMatrix();}

if(c>=40&&c<50){
glPushMatrix();
glTranslatef(-1,24,-1);
glRotatef(-90,0,0,1);
glRotatef(-90,0,1,0);
glColor3d(0,1,1);
cylinder(1,0.1,4);
glPopMatrix();}


glPushMatrix();
if(c>=50){
glTranslatef((t-50),18+15*(t-50),-4);
glRotatef(-90,0,0,1);
glRotatef(-90,0,1,0);
glColor3f(0,0,0);
}
else {
glTranslatef(-1,18,-1);
glRotatef(-90,0,0,1);
glRotatef(-90,0,1,0);
glColor3f(1,0,0);
}
cylinder(1.5,1,5);
glPopMatrix();

boat1();
}

void man1(float a,float b, float c, float x){
glColor3f(a,b,c);
cylinder(1,2,1);
glPushMatrix();
 glTranslatef(0,0,1);
 cylinder(2,2,1);                //base
 glPushMatrix();
  glRotatef(10,1,0,0);
  glTranslatef(0,0,1.5);
  cylinder(2,2,1);               //wrist
  glPushMatrix();
   glTranslatef(0,0,1.5);
   cylinder(2,2.4,3);             //torso
   glPushMatrix();
    glTranslatef(0,0,3.7);
    cylinder(1.2,1.2,2);             //head
   glPopMatrix();
   glPushMatrix();
    glTranslatef(2.6,0,3.1);        //left arm
    glRotatef(150,0,1,0);
    glRotatef(30+20*cos( glutGet(GLUT_ELAPSED_TIME) / 500.0 +x),1,0,0);
    cylinder(0.5,0.5,4);
   glPushMatrix();
    glTranslatef(0,0,4.5);
    glRotatef(20,0,1,0);
    cylinder(0.5,0.5,3.7);
    glPushMatrix();
glTranslatef(0,0,4);
     glRotatef(-90,1,0,0);
     //glRotatef(90,0,1,0);
     glColor3f(1,0.6,0.6);
     cylinder(0.1,0.1,5);                    //paddle
     glBegin(GL_TRIANGLE_FAN);
     glVertex3f(0,0,10);
     glVertex3f(-1.5,0,7.5);
     glVertex3f(-1.5,0,5);
     glVertex3f(1.5,0,5);
     glVertex3f(1.5,0,7.5);
     glEnd();
     glBegin(GL_TRIANGLE_FAN);
     glVertex3f(0,0,10);
     glVertex3f(1.5,0,7.5);
     glVertex3f(1.5,0,5);
     glVertex3f(-1.5,0,5);
     glVertex3f(-1.5,0,7.5);
     glEnd();
     
glRotatef(180,0,1,0);
     cylinder(0.1,0.1,10);
    glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   glPushMatrix();
    glColor3f(a,b,c);
    glTranslatef(-2.6,0,3.1);        //right arm
    glRotatef(-150,0,1,0);
    glRotatef(20*cos( glutGet(GLUT_ELAPSED_TIME) / 1000.0),1,0,0);
    cylinder(0.5,0.5,4);
   glPushMatrix();
    glTranslatef(0,0,4.5);
    glRotatef(90,0,0,1);
    cylinder(0.5,0.5,3.7);
   glPopMatrix();
  glPopMatrix();
 glPopMatrix();
glPopMatrix();
glPushMatrix();
glTranslatef(1,0,-1);
glRotatef(-160,1,0,0);
cylinder(0.6,0.6,3);          //left leg
glPopMatrix();
glPushMatrix();
glTranslatef(-1,0,-1);
glRotatef(90,1,0,0);
cylinder(0.6,0.6,5);         //right leg
glPushMatrix();
glTranslatef(0,0,5.5);
glRotatef(90,1,0,0);
cylinder(0.5,0.5,1);
glPopMatrix();
glPopMatrix();

glPopMatrix();//boat
///boat1();
}

void man2(float a,float b, float c,float t){
glColor3f(a,b,c);
cylinder(1,2,1);
glPushMatrix();
 glTranslatef(0,0,1);
 cylinder(2,2,1);                //base-man2
 glPushMatrix();
  glRotatef(10,1,0,0);
  glTranslatef(0,0,1.5);
  cylinder(2,2,1);               //wrist-man2
  glPushMatrix();
   glTranslatef(0,0,1.5);
   cylinder(2,2.4,3);             //torso-man2
   glPushMatrix();
    glTranslatef(0,0,3.7);
    cylinder(1.2,1.2,2);             //head-man2
   glPopMatrix();
   glPushMatrix();
    glTranslatef(2.6,0,3.1);        //left arm-man2
    glRotatef(150,0,1,0);
    cylinder(0.5,0.5,4);
   glPushMatrix();
    glTranslatef(0,0,4.5);
    glRotatef(20,0,1,0);
    cylinder(0.5,0.5,3.7);
    glPushMatrix();
glTranslatef(0,0,4);
     glRotatef(-90,1,0,0);
     //glRotatef(90,0,1,0);
     glColor3f(1,0.6,0.6);
     cylinder(0.1,0.1,5);                    //paddle-man2
     glBegin(GL_TRIANGLE_FAN);
     glVertex3f(0,0,10);
     glVertex3f(-1.5,0,7.5);
     glVertex3f(-1.5,0,5);
     glVertex3f(1.5,0,5);
     glVertex3f(1.5,0,7.5);
     glEnd();
     glBegin(GL_TRIANGLE_FAN);
     glVertex3f(0,0,10);
     glVertex3f(1.5,0,7.5);
     glVertex3f(1.5,0,5);
     glVertex3f(-1.5,0,5);
     glVertex3f(-1.5,0,7.5);
     glEnd();

glRotatef(180,0,1,0);
     cylinder(0.1,0.1,10);
    glPopMatrix();
   glPopMatrix();
   glPopMatrix();
   glPushMatrix();
    glColor3f(a,b,c);
    glTranslatef(-2.6,0,3.1);        //right arm-man2*-***
    glRotatef(-150,0,1,0);
if((int)(glutGet(GLUT_ELAPSED_TIME)/1000.0)>=38)glRotatef(-80,0,0,1);    
else glRotatef(-10*(t-30),0,0,1);
    cylinder(0.5,0.5,4);
   glPushMatrix();
    glTranslatef(0,0,4.5);
    glRotatef(90,0,0,1);
if((int)(glutGet(GLUT_ELAPSED_TIME)/1000.0)>=38)glRotatef(120,1,0,0);
else    glRotatef(15*(t-30),1,0,0);
    cylinder(0.5,0.5,3.7);
    glPushMatrix();
     glTranslatef(0,0,5.5);
     glColor3f(0,0,0);
     glBegin(GL_QUADS);
     glVertex3f(0,1,1.5);
glVertex3f(0,1,-1.5);
glVertex3f(0,-1,-1.5);
glVertex3f(0,-1,1.5);
glEnd();
glBegin(GL_QUADS);
     glVertex3f(0,1,1.5);
glVertex3f(0,-1,1.5);
glVertex3f(0,-1,-1.5);
glVertex3f(0,1,-1.5);
glEnd();
glColor3f(a,b,c);
    glPopMatrix();
   glPopMatrix();
  glPopMatrix();
 glPopMatrix();
glPopMatrix();
glPushMatrix();
glTranslatef(1,0,-1);
glRotatef(-160,1,0,0);
cylinder(0.6,0.6,3);          //left leg-man2
glPopMatrix();
glPushMatrix();
glTranslatef(-1,0,-1);
glRotatef(90,1,0,0);
cylinder(0.6,0.6,5);         //right leg-man2
glPushMatrix();
glTranslatef(0,0,5.5);
glRotatef(90,1,0,0);
cylinder(0.5,0.5,1);
glPopMatrix();
glPopMatrix();

glPopMatrix();//boat
///boat1();
}

void man3(float a,float b, float c){
glColor3f(a,b,c);
cylinder(1,2,1);
glPushMatrix();
 glTranslatef(0,0,1);
 cylinder(2,2,1);                //base
 glPushMatrix();
  glRotatef(-10,1,0,0);
  glTranslatef(0,0,1.5);
  cylinder(2,2,1);               //wrist
  glPushMatrix();
   glTranslatef(0,0,1.5);
   cylinder(2,2.4,3);             //torso
   glPushMatrix();
    glTranslatef(0,0,3.7);
    cylinder(1.2,1.2,2);             //head
   glPopMatrix();
   glPushMatrix();
    glTranslatef(2.6,0,3.1);        //left arm
    glRotatef(-100,1,0,0);
    cylinder(0.5,0.5,4);
   glPushMatrix();
    glTranslatef(0,0,4.5);
    glRotatef(20,0,1,0);
    cylinder(0.5,0.5,3.7);
   glPopMatrix();
   glPopMatrix();
   glPushMatrix();
    glColor3f(a,b,c);
    glTranslatef(-2.6,0,3.1);        //right arm
    glRotatef(-100,1,0,0);
    cylinder(0.5,0.5,4);
   glPushMatrix();
    glTranslatef(0,0,4.5);
    glRotatef(90,0,0,1);
    cylinder(0.5,0.5,3.7);
   glPopMatrix();
  glPopMatrix();
 glPopMatrix();
glPopMatrix();
glPushMatrix();
glTranslatef(1,0,-1);
glRotatef(-160,1,0,0);
cylinder(0.6,0.6,3);          //left leg
glPopMatrix();
glPushMatrix();
glTranslatef(-1,0,-1);
glRotatef(90,1,0,0);
cylinder(0.6,0.6,5);         //right leg
glPushMatrix();
glTranslatef(0,0,5.5);
glRotatef(90,1,0,0);
cylinder(0.5,0.5,1);
glPopMatrix();
glPopMatrix();

glPopMatrix();//boat
///boat1();
}


static void display(void)
{
    float t = glutGet(GLUT_ELAPSED_TIME) / 1000.0; //set time value
    int c=(int)(glutGet(GLUT_ELAPSED_TIME)/1000.0); 

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();     
    if(c<5)gluLookAt(-10+2*t, 6*t, 10+2*t , 0, 0, 0, 0, 1, 0); 
    else if(c<7) gluLookAt(0,30+2*(t-5),20+5*(t-5),0,0,0,0,1,0);    
    else if(c<30) gluLookAt(1*(t-7),34,30,1*(t-7),0,0,0,1,0);
    else if(c<40) gluLookAt(-100+9*(t-30),10,30,-100+9*(t-30),15,0,0,1,0);
    else if(c<50) gluLookAt(-150+30*(t-40),10,30,-150+30*(t-40),15,0,0,1,0);
    else if(c<53) gluLookAt(-150+30*(t-50),10,30+30*(t-50),-150+30*(t-50),15,30*(t-50),0,1,0);
    else if(c<55) gluLookAt(-100+9*(t-7),34,30,-100+9*(t-7),0,0,0,1,0);
    else if(c<70) gluLookAt(-150+30*(t-40),34,20,-150+30*(t-40),0,0,0,1,0);

    else gluLookAt(-100,30,10,-100,0,0,0,1,0);

for(int i=-100;i<650;i=i+30){for(int j=0;j<160;j=j+20){        
glPushMatrix();        //yellow ball
glColor3d(1,1,0);
          glTranslated(-150+i,0,-50+j);
          glutSolidSphere(1,slices,stacks);
        glPopMatrix();}}

for(int j=0;j<160;j=j+20){
glPushMatrix();        //final red ball
glColor3d(1,0,0);
          glTranslated(500,0,-50+j);
          glutSolidSphere(1,slices,stacks);
        glPopMatrix();}

        glBegin(GL_QUADS);
          glColor3d(1,1,0);
          glVertex3i(-500,0,-50);
          glVertex3i(800,0,-50);
          glVertex3i(800,0,-70);
          glVertex3i(-500,0,-70);

          glColor3d(1,0,0);
          glVertex3i(-500,0,-70);
          glVertex3i(800,0,-70);
          glVertex3i(800,10,-70);
          glVertex3i(-500,10,-70);
	  
	  glColor3d(1,1,1);
	  glVertex3i(-500,10,-70);
	  glVertex3i(800,10,-70);
	  glVertex3i(800,10,-150);
	  glVertex3i(-600,10,-70);

          glColor3d(1,1,0);
glVertex3i(-600,-5,-70);
glVertex3i(800,-5,-70);
glVertex3i(800,0,-70);
 glVertex3i(-600,0,-70);

/*          glVertex3i(-600,0,-70);
          glVertex3i(800,0,-70);
          glVertex3i(800,-5,-70);
          glVertex3i(-600,-5,-70);
*/
        glEnd();
if(c>7&&c<40){
glPushMatrix();
glTranslatef(-70+9*(t-7)-2.5*cos(t*2+30),0,20);  //green guy
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man1(0,1,0,30);
boat1();
glPopMatrix();

glPushMatrix();
glTranslatef(-100+8*(t-7)-2.5*cos(t*2+15),0,-40);  //white guy
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man1(1,1,1,15);
boat1();
glPopMatrix();

glPushMatrix();
glTranslatef(-120+10*(t-7)-2.5*cos(t*2+70),0,0);  //yellow guy
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man1(1,1,0,70);
boat1();
glPopMatrix();
}
if(c>10&&c<30){glPushMatrix();
glTranslatef(-100+10*(t-9)-2.5*cos(t*2+50),0,-20);
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man1(1,0,0,50);
boat2(t,c);
glPopMatrix();}
if(c>25&&c<40){
glPushMatrix();
glTranslatef(-100+9*(t-30),0,0);
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
if(c==38)man2(0,1,1,t);
else man2(1,0,0,t);
boat2(t,c);
glPopMatrix();
}
if(c>=40&&c<50){
glPushMatrix();
glTranslatef(-150+30*(t-40),0,0);
if(c>50&&c<54)glRotatef(-45,1,0,0);
else glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man3(1,0,0);
boat2(t,c);
glPopMatrix();
}
if(c>=50&&c<54){
glPushMatrix();
glTranslatef(-150+30*(t-50),0,30*(t-50));
glRotatef(-45,1,0,0);
glRotatef(90,0,0,1);
man3(1,0,0);
boat2(t,c);
glPopMatrix();
}
if(c>=52&&c<55){glPushMatrix();
glTranslatef(-100+9*(t-7)-2.5*cos(t*2+30),0,20);
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man1(0,1,0,30);
boat1();
glPopMatrix();}

if(c>=55){glPushMatrix();
glTranslatef(-150+30*(t-40),0,0);
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man3(0,1,0);
boat1();
glPopMatrix();
glPushMatrix();
glTranslatef(-180+30*(t-40),0,0);
glRotatef(-90,1,0,0);
glRotatef(90,0,0,1);
man3(1,0,0);
boat2(t,c);
glPopMatrix();

}


glBegin(GL_QUADS);
          glColor3f(0,0,1);
          glVertex3i(-500,0,-50);
          glVertex3i(500,0,-50);
          glVertex3i(500,0,150);
          glVertex3i(-500,0,150);
glEnd();
glBegin(GL_QUADS);

          glColor3f(0,0,1);
glVertex3i(-500,-5,150);
 glVertex3i(1000,-5,150);
glVertex3i(1000,-5,-100);
glVertex3i(-500,-5,-100);

glEnd();

    glPopMatrix();
glPopMatrix();
    glutSwapBuffers();
}

static void 
idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(100,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Final Project");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glClearColor(0.5,0.5,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}

