#include <GL/glut.h>
#include <math.h>
#include <string>
void init(void)
{
 glClearColor(0.0,0.0,0.0,0.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(0.0,400.0,0.0,400.0);
}

static void display(void)
{
    float t =0.0;    //set environment number
    int b=0;    
    std::string words="MOVING BOX! ";
    t=glutGet(GLUT_ELAPSED_TIME)%4000;
    b=(glutGet(GLUT_ELAPSED_TIME)/4000)%2;
    glClear(GL_COLOR_BUFFER_BIT);  
    glPushMatrix();                 //three boxs running repeatedly
      glTranslatef(t/10,200,0);
        glColor3f(-1+t/4000,-1+t/4000,1);
        glRectf(-350,0,-450,100);
        glColor3f(-0.5+t/4000,-0.5+t/4000,1);        
        glRectf(-150,0,-250,100);
        glColor3f(t/4000,t/4000,1);
        glRectf(-50,0.0,50,100.0);  
        glColor3f(0.5+t/4000,0.5+t/4000,1);
        glRectf(150,100,250,0);
        glColor3f(1,1,1);
        glRectf(350,100,450,0);
    glPopMatrix();
    glPushMatrix();             //color changing stream
      if(b==1)glColor3f(0,1,1-t/4000);
      if(b==0) glColor3f(0,1,0+t/4000);
      glRectf(0,185,400,200);
    glPopMatrix();
    glPushMatrix();       //create the rotating words
      glTranslatef(200,100,0);        
      glRotatef(t*360/4000-90,0,0,1);   //to make the words spin
    for(float i=0;i<words.length();i++){    //the same as creating circles
        float theta = -2.0f * 3.1415926f * i / words.length();
        float x = 40 * cosf(theta);
        float y = 40 * sinf(theta);
        if((1-i/words.length()+t/4000)>1) glColor3f(1,-i/words.length()+t/4000,-i/words.length()+t/4000);
        else  glColor3f(1,1-i/words.length()+t/4000,1-i/words.length()+t/4000);
         glRasterPos2f(x,y);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, words[i]); 
        }
    glPopMatrix();
    glFlush();
}

static void idle(void)
{
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(300,300);
    glutInitWindowSize(900,900);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);    
    glutCreateWindow("MOVING BOX");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
  glutMainLoop();
}

