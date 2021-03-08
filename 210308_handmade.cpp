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
