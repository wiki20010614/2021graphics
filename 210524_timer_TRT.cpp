#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);///�զ�
        glutSolidCube(0.4);///����
        glPushMatrix();
            glTranslatef(-0.2,+0.2,0);///��쥪�W��
            glRotatef(angle,0,0,1);///�������
            glColor3f(1,0,0);///����
            glutSolidCube(0.3);///����
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int diff=2;
void timer(int t)///timer����
{
    glutTimerFunc(20,timer,t+1);///�]�w�U�@��timer
    angle+=diff;
    if(angle>90||angle<0) diff=-diff;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);///��1��timer///�ɶ�,�ϥΪ��禡,�Ѽ�
    glutMainLoop();
}
