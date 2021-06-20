#include <GL/glut.h>
#include <stdio.h>
FILE * fout = NULL;
FILE * fin = NULL;
float angle[20]={};///�����]��0
int angleID=0;///�{�b�n�ʪ����`�O��?
void keyboard(unsigned char key, int x, int y){
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
    if(key=='s'){///�s��
        if( fout==NULL ) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++) fprintf(fout, "%.2f ", angle[i]);
        fprintf(fout, "\n");
        printf("save angle.txt\n");
    }else if(key=='r'){///Ū�� (����M�s�ɦP�ɰ�,�]angle.txt����}2��)
        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angle[i]);
        glutPostRedisplay();///���e�e��
        printf("read angle.txt\n");
    }
}///�p�G���`�ܦh, �i��n�ΰj������{���u�n2�� for(int i=0; i<10; i++)
///�i��]�n�Ψ�^��r��
float oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion( int x, int y ){
    angle[angleID] += x-oldX;///0: angle[0], 1: angle[1]..
    oldX = x;
    glutPostRedisplay();///���e�e��
}
void display(){
    glClearColor( 1,0,0,0);///�Ψ�Clear��Color �ά���
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f( 1,1,0 );
        glutSolidTeapot( 0.3 );///��������ѱ�����,�u�ݤ��u
        glPushMatrix();///���b��
            glTranslatef(-.3, 0, 0);///(3)�A����ʤ������u,����ӤW
            glRotatef(angle[0], 0,0,1);///(2)�A��ʥ�
            glTranslatef(-.3, .1, 0);///(1)���ʱ��त��,�񥿤���
            glutSolidTeapot(0.3);///�����u
            glPushMatrix();
                glTranslatef(-.3, 0, 0);///(3)�A����ʤ������u,����ӤW
                glRotatef(angle[1], 0,0,1);///(2)�A��ʥ�
                glTranslatef(-.3, 0, 0);///(1)���ʱ��त��,�񥿤���
                glutSolidTeapot(0.3);///����y
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();///�k�b��
            glTranslatef(+.3, 0, 0);///(3)�A����ʤ������u,����ӤW
            glRotatef(angle[2], 0,0,1);///(2)�A��ʥ�
            glTranslatef(+.3, .1, 0);///(1)���ʱ��त��,�񥿤���
            glutSolidTeapot(0.3);///�k���u
            glPushMatrix();
                glTranslatef(+.3, 0, 0);///(3)�A����ʤ������u,����ӤW
                glRotatef(angle[3], 0,0,1);///(2)�A��ʥ�
                glTranslatef(+.3, 0, 0);///(1)���ʱ��त��,�񥿤���
                glutSolidTeapot(0.3);///�k��y
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
int main( int argc, char ** argv )
{
    glutInit( &argc, argv);
    glutInitWindowSize(300,300);
    glutInitWindowPosition(700,200);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("08161080");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
