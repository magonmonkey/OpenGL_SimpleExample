#include <GL/glut.h>
#include <stdlib.h>
#include<iostream>
#include<math.h>
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
    glFrustum(-ar, ar, -1.0, 1.0, 1, 100.0);  //to prevent graphic from distortion
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}
double c=0;
static void 
display(void)
{
    float t = glutGet(GLUT_ELAPSED_TIME) / 500.0; //set each value
    int c=(int)(glutGet(GLUT_ELAPSED_TIME)/4000.0)%4; 
    float d=glutGet(GLUT_ELAPSED_TIME)/4000.0-(int)(glutGet(GLUT_ELAPSED_TIME)/4000.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();          //d to make the eye spin, t to make the eye move
    if (c==3)gluLookAt(-(4+10*d)*cos(t),0,(4+10*d)*sin(t),0,0,0,0,1,0); //moving away
    else if(c==0)gluLookAt(-14*cos(t), 0,14*sin(t) , 0, 0, 0, 0, 1, 0); //stay at farest point
    else if(c==1)gluLookAt(-(14-10*d)*cos(t), 0,(14-10*d)*sin(t), 0, 0, 0, 0, 1, 0); //moving closer
    else gluLookAt(-4*cos(t), 0, 4*sin(t), 0, 0, 0, 0, 1, 0); //stay at closest point
        glPushMatrix();        //black ring
          glColor3d(0,0,0);
          glutSolidTorus(0.08,0.8,slices,stacks);
        glPopMatrix();        
        glPushMatrix();        //red ring
          glColor3d(1,0,0);
          glTranslated(-2,0,0);
          glutSolidTorus(0.08,0.8,slices,stacks);
        glPopMatrix();
        glPushMatrix();        //blue ring
          glColor3d(0,0,1);
          glTranslated(2,0,0);
          glutSolidTorus(0.08,0.8,slices,stacks);
        glPopMatrix();
        glPushMatrix();        //green ring
          glColor3d(0,1,0);
          glTranslated(-1,-0.8,-0.16);
          glutSolidTorus(0.08,0.8,slices,stacks);
        glPopMatrix();
          glPushMatrix();      //yellow ring
          glColor3d(1,1,0);
          glTranslated(1,-0.8,-0.16);
          glutSolidTorus(0.08,0.8,slices,stacks);
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
    glutInitWindowSize(640,480);
    glutInitWindowPosition(300,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("FreeGLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
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

