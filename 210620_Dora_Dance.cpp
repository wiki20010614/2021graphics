#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include "glm.h"

FILE * fout = NULL;
FILE * fin = NULL;

GLMmodel*pmodel1=NULL;
GLMmodel*body=NULL;
GLMmodel*head=NULL;
GLMmodel*handl=NULL;
GLMmodel*handr=NULL;
GLMmodel*footl=NULL;
GLMmodel*footr=NULL;
IplImage*img=NULL;

GLuint id1,id2;///�K��ID

///����
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 2.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

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

float angle[20]={},angleOld[20],angleNew[20];
int angleID=0;

void timer(int t)
{
    glutTimerFunc( 20, timer, t+1);
    if(t%25==0)
        {
            for(int i=0;i<20;i++) angleOld[i]=angleNew[i];
            if(fin==NULL) fin=fopen("angle.txt","r");
            for(int i=0;i<20;i++) fscanf(fin,"%f",&angleNew[i]);
            printf("read angle.txt\n");
        }
    float alpha=(t%25)/25.0;
    for(int i=0;i<20;i++) angle[i]=alpha*angleNew[i]+(1-alpha)*angleOld[i];
    glutPostRedisplay();///���e�e��
}

void keyboard(unsigned char key, int x, int y)
{
    ///����xyz
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    ///�Yxyz
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    ///����xyz
    if(key=='6') angleID=6;
    if(key=='7') angleID=7;
    if(key=='8') angleID=8;
    ///�k��xyz
    if(key=='a') angleID=9;
    if(key=='b') angleID=10;
    if(key=='c') angleID=11;
    ///���}xyz
    if(key=='d') angleID=12;
    if(key=='e') angleID=13;
    if(key=='f') angleID=14;
    ///�k�}xyz
    if(key=='g') angleID=15;
    if(key=='h') angleID=16;
    if(key=='i') angleID=17;

    ///���ʧ@&����
    if(key=='p'||key=='P')
    {
        glutTimerFunc(0,timer,0);
        PlaySound("Papepipupo.wav",NULL,SND_ASYNC);
    }

    ///�s���ɮ�
    if(key=='s')
    {
        if( fout==NULL ) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++) fprintf(fout, "%.2f ", angle[i]);
        fprintf(fout, "\n");
        printf("save angle.txt\n");
    }
    else if(key=='r'){///Ū�ɮ�
        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angle[i]);
        glutPostRedisplay();///���e�e��
        printf("read angle.txt\n");
    }
}

float oldX=0;
void mouse(int button, int state, int x, int y)
{
    oldX = x;
}

void motion( int x, int y )
{
    angle[angleID] += x-oldX;
    oldX = x;
    glutPostRedisplay();///���e�e��
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D,id1);

    glPushMatrix();///�e����
        glRotatef(angle[2],0,0,1);
        glRotatef(angle[1],0,1,0);
        glRotatef(angle[0],1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(body,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e�Y
        glRotatef(angle[5],0,0,1);
        glRotatef(angle[4],0,1,0);
        glRotatef(angle[3],1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(0,-0.4,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(head,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e����
        glTranslatef(0,0,0);
        glRotatef(angle[8],0,0,1);
        glRotatef(angle[7],0,1,0);
        glRotatef(angle[6],1,0,0);
        glTranslatef(0,-0.4,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(handl,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e�k��
        glTranslatef(0,0,0);
        glRotatef(angle[11],0,0,1);
        glRotatef(angle[10],0,1,0);
        glRotatef(angle[9],1,0,0);
        glTranslatef(0,-0.4,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(handr,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e���}
        glTranslatef(0,0,0);
        glRotatef(angle[14],0,0,1);
        glRotatef(angle[13],0,1,0);
        glRotatef(angle[12],1,0,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(footl,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///�e�k�}
        glTranslatef(0,0,0);
        glRotatef(angle[17],0,0,1);
        glRotatef(angle[16],0,1,0);
        glRotatef(angle[15],1,0,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.25,0.25,0.25);
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
}

int main(int argc, char** argv)
{
    img=cvLoadImage("Dora.jpg");
    cvShowImage("08161080",img);///�q�X�@�i��
    cvWaitKey(0);///�������N��,�~�వ���U�Ӫ��ʧ@

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);///�����j�p
    glutInitWindowPosition(200,200);///������m
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Dance");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    id1 = myTexture("blue.png");///�ҫ�
    id2 = myTexture("shin.png");///�I��

    body=glmReadOBJ("body.obj");
    head=glmReadOBJ("head.obj");
    handl=glmReadOBJ("handl.obj");
    handr=glmReadOBJ("handr.obj");
    footl=glmReadOBJ("footl.obj");
    footr=glmReadOBJ("footr.obj");

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
