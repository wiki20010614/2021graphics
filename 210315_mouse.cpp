#include <GL/glut.h>///�ϥ�GLUT�~��
#include <stdio.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M��

    glBegin(GL_TRIANGLES);
        glColor3ub(24,94,151);   glVertex2f((148-150)/150.0,-(29-150)/150.0);
        glColor3ub(24,94,151);   glVertex2f((0-150)/150.0,-(300-150)/150.0);
        glColor3ub(24,94,151);   glVertex2f((300-150)/150.0,-(300-150)/150.0);

        glColor3ub(255,255,255);   glVertex2f((148-150)/150.0,-(29-150)/150.0);
        glColor3ub(255,255,255);  glVertex2f((84-150)/150.0,-(146-150)/150.0);
        glColor3ub(255,255,255);   glVertex2f((213-150)/150.0,-(146-150)/150.0);
    glEnd();

    glutSwapBuffers();///�洫2����buffers
}

void mouse(int button,int state,int x,int y)///����ƹ�
{
    if(state==GLUT_DOWN)
    {
        printf("glVertex2f((%d-150)/150.0,-(%d-150)/150.0)\n",x,y);///�L�X�ƹ��y��
    }
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///��ܼҦ�
    glutCreateWindow("�I�h�s");///�}����

    glutDisplayFunc(display);///�n��ܪ��禡
    glutMouseFunc(mouse);///�ϥηƹ��禡
    glutMainLoop();///�D�n���j��
}
