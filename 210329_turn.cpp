#include <GL/glut.h>///�ϥ�GLUT�~��
float angle=0;

void hand()///�e�����
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);
        glutSolidCube(1);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M��
    ///����
    glPushMatrix();///�ƥ��x�}
        glTranslatef(-0.25,0,0);///���ʪ���
        glRotatef(angle,0,0,1);
        glTranslatef(-0.25,0,0);///���ʤ����I
        hand();///�|�ʪ������
        glPushMatrix();///�ƥ��x�}
            glTranslatef(-0.25,0,0);///���ʪ���
            glRotatef(angle,0,0,1);
            glTranslatef(-0.25,0,0);///���ʤ����I
            hand();///�|�ʪ������
        glPopMatrix();///�٭�x�}
    glPopMatrix();///�٭�x�}
    ///�k��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(0.25,0,0);///���ʪ���
        glRotatef(-angle,0,0,1);
        glTranslatef(0.25,0,0);///���ʤ����I
        hand();///�|�ʪ������
        glPushMatrix();///�ƥ��x�}
            glTranslatef(0.25,0,0);///���ʪ���
            glRotatef(-angle,0,0,1);
            glTranslatef(0.25,0,0);///���ʤ����I
            hand();///�|�ʪ������
        glPopMatrix();///�٭�x�}
    glPopMatrix();///�٭�x�}
    glutSwapBuffers();///�洫2����buffers
    angle++;///�W�[����
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///��ܼҦ�
    glutCreateWindow("Turn");///�}����

    glutIdleFunc(display);///����e��
    glutDisplayFunc(display);///�n��ܪ��禡
    glutMainLoop();///�D�n���j��
}
