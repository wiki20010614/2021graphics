#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidCube(0.3);///glutSolidSphere(0.3,30,30);///實心圓球(半徑,縱切,橫切)
    glPopMatrix();
    glutSwapBuffers();
}
int diff=1;
void timer(int t)///timer執行
{
    glutTimerFunc(20,timer,t+1);///設定下一個timer
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
    glutTimerFunc(3000,timer,0);///第1個timer///時間,使用的函式,參數

    glutMainLoop();
}
