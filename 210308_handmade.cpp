#include <GL/glut.h>///�ϥ�GLUT�~��

void display()
{           ///�M���C��         ///�M��3D�`��
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///�M��

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
        glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
        glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);
    glEnd();

    glColor3f(0,0,1);///�վ��C��(R,G,B)
    glutSolidTeapot(0.5);///�e��߯���(�i�վ�j�p)

    glutSwapBuffers();///�洫2����buffers
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT��l�]�w
                        ///2����� ///3D�`��
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///��ܼҦ�
    glutCreateWindow("08161080");///�}����

    glutDisplayFunc(display);///�n��ܪ��禡

    glutMainLoop();///�D�n���j��
}
