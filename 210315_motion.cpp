#include <GL/glut.h>///使用GLUT外掛
#include <stdio.h>

float teaX=0,teaY=0;///茶壺座標

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清空
    glPushMatrix();///備份矩陣
        glTranslatef(teaX,teaY,0);
        glutSolidTeapot(0.5);
    glPopMatrix();///還原矩陣
    glEnd();
    glutSwapBuffers();///交換2倍的buffers
}

void motion(int x,int y)///移動
{
    teaX=(x-150)/150.0;///換算座標
    teaY=-(y-150)/150.0;
    display();///即時更新
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT初始設定
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///顯示模式
    glutCreateWindow("Mouse");///開視窗

    glutDisplayFunc(display);///要顯示的函式
    glutMotionFunc(motion);///移動的函式
    glutMainLoop();///主要的迴圈
}
