#include <GL/glut.h>///使用GLUT外掛
#include <stdio.h>

float vx[2000],vy[2000];///用陣列存頂點
int N=0;///有N個頂點

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清空
    glBegin(GL_POLYGON);
    glColor3f(0,1,0);
    for(int i=0;i<N;i++)
    {
        glVertex2f(vx[i],vy[i]);
    }
    glEnd();
    glutSwapBuffers();///交換2倍的buffers
}

void mouse(int button,int state,int x,int y)///控制滑鼠
{

}

void motion(int x,int y)///移動
{
    printf("%d %d\n",x,y);///把頂點記下來
    vx[N]=(x-150)/150.0;///換算座標
    vy[N]=-(y-150)/150.0;
    N++;
    display();///即時更新
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT初始設定
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///顯示模式
    glutCreateWindow("Draw");///開視窗

    glutDisplayFunc(display);///要顯示的函式
    glutMouseFunc(mouse);///使用滑鼠函式
    glutMotionFunc(motion);///移動的函式
    glutMainLoop();///主要的迴圈
}
