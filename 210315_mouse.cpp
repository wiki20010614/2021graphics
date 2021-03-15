#include <GL/glut.h>///使用GLUT外掛
#include <stdio.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清空

    glBegin(GL_TRIANGLES);
        glColor3ub(24,94,151);   glVertex2f((148-150)/150.0,-(29-150)/150.0);
        glColor3ub(24,94,151);   glVertex2f((0-150)/150.0,-(300-150)/150.0);
        glColor3ub(24,94,151);   glVertex2f((300-150)/150.0,-(300-150)/150.0);

        glColor3ub(255,255,255);   glVertex2f((148-150)/150.0,-(29-150)/150.0);
        glColor3ub(255,255,255);  glVertex2f((84-150)/150.0,-(146-150)/150.0);
        glColor3ub(255,255,255);   glVertex2f((213-150)/150.0,-(146-150)/150.0);
    glEnd();

    glutSwapBuffers();///交換2倍的buffers
}

void mouse(int button,int state,int x,int y)///控制滑鼠
{
    if(state==GLUT_DOWN)
    {
        printf("glVertex2f((%d-150)/150.0,-(%d-150)/150.0)\n",x,y);///印出滑鼠座標
    }
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT初始設定
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///顯示模式
    glutCreateWindow("富士山");///開視窗

    glutDisplayFunc(display);///要顯示的函式
    glutMouseFunc(mouse);///使用滑鼠函式
    glutMainLoop();///主要的迴圈
}
