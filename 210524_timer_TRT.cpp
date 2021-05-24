#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);///白色
        glutSolidCube(0.4);///身體
        glPushMatrix();
            glTranslatef(-0.2,+0.2,0);///放到左上角
            glRotatef(angle,0,0,1);///左手旋轉
            glColor3f(1,0,0);///紅色
            glutSolidCube(0.3);///左手
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int diff=2;
void timer(int t)///timer執行
{
    glutTimerFunc(20,timer,t+1);///設定下一個timer
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
    glutTimerFunc(0,timer,0);///第1個timer///時間,使用的函式,參數
    glutMainLoop();
}
