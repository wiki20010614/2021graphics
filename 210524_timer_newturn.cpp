#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidCube(0.3);///glutSolidSphere(0.3,30,30);///��߶�y(�b�|,�a��,���)
    glPopMatrix();
    glutSwapBuffers();
}
int diff=1;
void timer(int t)///timer����
{
    glutTimerFunc(20,timer,t+1);///�]�w�U�@��timer
    angle+=diff;
    if(angle>180) diff=-diff;
    if(angle<0) diff=-diff;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutTimerFunc(3000,timer,0);///��1��timer///�ɶ�,�ϥΪ��禡,�Ѽ�

    glutMainLoop();
}
