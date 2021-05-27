#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"///�ϥΥ~��

GLMmodel*pmodel1=NULL;
GLMmodel*body=NULL;
GLMmodel*head=NULL;
GLMmodel*handl=NULL;
GLMmodel*handr=NULL;
GLMmodel*footl=NULL;
GLMmodel*footr=NULL;

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

GLuint id1, id2;///�W�[2�ӶK��ID
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float anglehl=-10;
float anglehr=10;
float anglefl=-10;///��l����=0
float anglefr=10;///��l����=0

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, id1);

    glPushMatrix();///�e����
        glTranslatef(0,-0.3,0);
        glScalef(0.3,0.3,0.3);
        glmDraw(body,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e�Y
        glTranslatef(0,-0.3,0);
        glScalef(0.3,0.3,0.3);
        glmDraw(head,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e����
        glTranslatef(0,0,0.2);
        glRotatef(anglehl,1,0,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.3,0.3,0.3);
        glmDraw(handl,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e�k��
        glTranslatef(0,0,0.2);
        glRotatef(anglehr,1,0,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.3,0.3,0.3);
        glmDraw(handr,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e���}
        glTranslatef(0,0,0.2);
        glRotatef(anglefl,1,0,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.3,0.3,0.3);
        glmDraw(footl,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e�k�}
        glTranslatef(0,0,0.2);
        glRotatef(anglefr,1,0,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.3,0.3,0.3);
        glmDraw(footr,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f( 0, 0 ); glVertex3f( -1, +1 ,0.8);
        glTexCoord2f( 0, 1 ); glVertex3f( -1, -1 ,0.8);
        glTexCoord2f( 1, 1 ); glVertex3f( +1, -1 ,0.8);
        glTexCoord2f( 1, 0 ); glVertex3f( +1, +1 ,0.8);
    glEnd();
    glutSwapBuffers();
    anglehl+=0.05;
    anglehr+=0.05;
    anglefl+=0.05;///�W�[����
    anglefr+=0.05;///�W�[����
    if(anglefl>25)anglehr=0;
    if(anglefr>25)anglehl=0;
    if(anglefl>25)anglefl=-anglefl;
    if(anglefr>25)anglefr=-anglefr;
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("HW4_08161080");
    glutDisplayFunc(display);
    glutIdleFunc(display);

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

    id1 = myTexture("blue.png");///�K��
    id2 = myTexture("shin.png");///�I��

    body=glmReadOBJ("body.obj");
    head=glmReadOBJ("head.obj");
    handl=glmReadOBJ("handl.obj");
    handr=glmReadOBJ("handr.obj");
    footl=glmReadOBJ("footl.obj");
    footr=glmReadOBJ("footr.obj");

    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
