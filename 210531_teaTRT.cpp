#include <stdio.h>
#include <GL/glut.h>
float angle=0,diff=2;///����
///float angle[20]={};
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);///�]�w�U�@�ӭp�ɾ�
    angle+=diff;///���ܨ���
    if(angle>90) diff=-2;
    if(angle<0) diff=2;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///����
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///���W�u
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle,0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///���U�u
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///�k�W�u
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle,0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///�k�U�u
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15");

    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
}
