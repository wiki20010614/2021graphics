#include <stdio.h>
#include <GL/glut.h>
float angle=0,diff=2;///角度
///float angle[20]={};
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);///設定下一個計時器
    angle+=diff;///改變角度
    if(angle>90) diff=-2;
    if(angle<0) diff=2;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///左上臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle,0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///左下臂
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///右上臂
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle,0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///右下臂
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
