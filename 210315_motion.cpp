#include <GL/glut.h>///�ϥ�GLUT�~��
#include <stdio.h>

float teaX=0,teaY=0;///�����y��

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(teaX,teaY,0);
        glutSolidTeapot(0.5);
    glPopMatrix();///�٭�x�}
    glEnd();
    glutSwapBuffers();///�洫2����buffers
}

void motion(int x,int y)///����
{
    teaX=(x-150)/150.0;///����y��
    teaY=-(y-150)/150.0;
    display();///�Y�ɧ�s
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///��ܼҦ�
    glutCreateWindow("Mouse");///�}����

    glutDisplayFunc(display);///�n��ܪ��禡
    glutMotionFunc(motion);///���ʪ��禡
    glutMainLoop();///�D�n���j��
}
