#include <GL/glut.h>///�ϥ�GLUT�~��
#include <stdio.h>
int N=0,vx[3000],vy[3000];///�ΰ}�C�s���I
float angle=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M��
    glPushMatrix();///�ƥ��x�}
        glRotatef(angle,0,0,1);
        glScalef(0.5,0.1,0.1);
        glColor3f(0.3,0.3,1.0);
        glutSolidCube(1);
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();///�洫2����buffers
}

void mouse(int button,int state,int x,int y)///����ƹ�
{

}

void keyboard(unsigned char key,int x,int y)
{

}

void motion(int x,int y)///����
{
    angle++;
    display();
    /*
    printf("%d %d\n",x,y);///�⳻�I�O�U��
    vx[N]=(x-150)/150.0;///����y��
    vy[N]=-(y-150)/150.0;
    N++;
    display();///�Y�ɧ�s
    */
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///��ܼҦ�
    glutCreateWindow("Move");///�}����

    glutDisplayFunc(display);///�n��ܪ��禡
    glutMouseFunc(mouse);///�ϥηƹ��禡
    glutKeyboardFunc(keyboard);///���ʪ��禡
    glutMotionFunc(motion);///���ʪ��禡
    glutMainLoop();///�D�n���j��
}
