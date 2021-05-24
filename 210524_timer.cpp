#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(0.3,30,30);///實心圓球(半徑,縱切,橫切)
    glutSwapBuffers();
}
void timer(int t)
{
    glClearColor(1,0,0,0);///清除背景色彩(紅色)
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutTimerFunc(4000,timer,0);///時間,使用的函式,參數

    glutMainLoop();
}
