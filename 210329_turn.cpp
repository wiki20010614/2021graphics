#include <GL/glut.h>///使用GLUT外掛
float angle=0;

void hand()///畫長方形
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清空
    ///左手
    glPushMatrix();///備份矩陣
        glTranslatef(-0.25,0,0);///移動物體
        glRotatef(angle,0,0,1);
        glTranslatef(-0.25,0,0);///移動中心點
        hand();///會動的長方形
        glPushMatrix();///備份矩陣
            glTranslatef(-0.25,0,0);///移動物體
            glRotatef(angle,0,0,1);
            glTranslatef(-0.25,0,0);///移動中心點
            hand();///會動的長方形
        glPopMatrix();///還原矩陣
    glPopMatrix();///還原矩陣
    ///右手
    glPushMatrix();///備份矩陣
        glTranslatef(0.25,0,0);///移動物體
        glRotatef(-angle,0,0,1);
        glTranslatef(0.25,0,0);///移動中心點
        hand();///會動的長方形
        glPushMatrix();///備份矩陣
            glTranslatef(0.25,0,0);///移動物體
            glRotatef(-angle,0,0,1);
            glTranslatef(0.25,0,0);///移動中心點
            hand();///會動的長方形
        glPopMatrix();///還原矩陣
    glPopMatrix();///還原矩陣
    glutSwapBuffers();///交換2倍的buffers
    angle++;///增加角度
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT初始設定
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///顯示模式
    glutCreateWindow("Turn");///開視窗

    glutIdleFunc(display);///重整畫面
    glutDisplayFunc(display);///要顯示的函式
    glutMainLoop();///主要的迴圈
}
