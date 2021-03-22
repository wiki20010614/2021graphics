# 2021電腦圖學

Week03
======

Week03-1
------
```C++
#include <GL/glut.h>

static void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glBegin(GL_TRIANGLES);

                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

            glEnd();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);

    glutMainLoop();
}
```

Week03-2
------
```C++
#include <GL/glut.h>///使用GLUT外掛

void display()
{           ///清空顏色         ///清空3D深度
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清空

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
    glEnd();

    glColor3f(0,0,1);///調整顏色(R,G,B)
    glutSolidTeapot(0.5);///畫實心茶壺(可調整大小)

    glutSwapBuffers();///交換2倍的buffers
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT初始設定
                        ///2倍顯示 ///3D深度
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///顯示模式
    glutCreateWindow("08161080");///開視窗

    glutDisplayFunc(display);///要顯示的函式

    glutMainLoop();///主要的迴圈
}
```

Week03-3
------
```C++
#include <GL/glut.h>///使用GLUT外掛

void display()
{           ///清空顏色         ///清空3D深度
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

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT初始設定
                        ///2倍顯示 ///3D深度
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///顯示模式
    glutCreateWindow("富士山");///開視窗

    glutDisplayFunc(display);///要顯示的函式

    glutMainLoop();///主要的迴圈
}
```

Week04
======

Week04-1
------
```C++
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
```

Week04-2
------
```C++
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
```

Week05
======

Week05-1
------
```C++
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
```
