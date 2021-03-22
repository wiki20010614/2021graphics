#include <GL/glut.h>///�ϥ�GLUT�~��
#include <stdio.h>

float vx[2000],vy[2000];///�ΰ}�C�s���I
int N=0;///��N�ӳ��I

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M��
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    for(int i=0;i<N;i++)
    {
        glVertex2f(vx[i],vy[i]);
    }
    glEnd();
    glutSwapBuffers();///�洫2����buffers
}

void mouse(int button,int state,int x,int y)///����ƹ�
{

}

void motion(int x,int y)///����
{
    printf("%d %d\n",x,y);///�⳻�I�O�U��
    vx[N]=(x-150)/150.0;///����y��
    vy[N]=-(y-150)/150.0;
    N++;
    display();///�Y�ɧ�s
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///��ܼҦ�
    glutCreateWindow("Draw");///�}����

    glutDisplayFunc(display);///�n��ܪ��禡
    glutMouseFunc(mouse);///�ϥηƹ��禡
    glutMotionFunc(motion);///���ʪ��禡
    glutMainLoop();///�D�n���j��
}
