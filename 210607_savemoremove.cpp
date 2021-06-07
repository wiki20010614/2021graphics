#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;///����
int angleID=0;
void timer(int t)
{
    /*glutTimerFunc(30,timer,t+1);///�]�w�U�@�ӭp�ɾ�
    angle[angleID]+=diff;
    if(angle[angleID]>90) diff=-2;
    if(angle[angleID]<0) diff=2;
    glutPostRedisplay();*/
}
int oldX=0,oldY=0;
void mouse(int button,int state,int x,int y)
{
    oldX=x;
    oldY=y;
}
FILE*fout=NULL;
FILE*fin=NULL;
void motion(int x,int y)
{
    angle[angleID]+=x-oldX;
    oldX=x;
    glutPostRedisplay();
    if(fout==NULL) fout=fopen("angle.txt","w+");
    for(int i=0;i<20;i++) printf("%.2f",angle[i]);
    printf("\n");
    for(int i=0;i<20;i++) fprintf(fout,"%.2f",angle[i]);
    fprintf(fout,"\n");

}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='s')
    {
        if(fout==NULL) fout=fopen("angle.txt","w+");
        for(int i=0;i<20;i++) printf("%.2f",angle[i]);
        printf("\n");
        for(int i=0;i<20;i++) fprintf(fout,"%.2f",angle[i]);
        fprintf(fout,"\n");
    }
    if(key=='r')
    {
        if(fin==NULL) fin=fopen("angle.txt","r");
        for(int i=0;i<20;i++) fscanf(fin,"%f",&angle[i]);
        glutPostRedisplay();
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///����
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle[0],0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///���W�u
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle[1],0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///���U�u
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle[2],0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///�k�W�u
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle[3],0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///�k�U�u
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
}
