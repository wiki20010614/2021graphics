#include <windows.h>
#include <GL/glut.h>
#include "CMP3_MCI.h"///引用CMP3_MCI.h
CMP3_MCI mp3;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{///按下鍵盤即可播放聲音(wav檔)
    if(key=='1') PlaySound("do.wav",NULL,SND_ASYNC);
    if(key=='2') PlaySound("re.wav",NULL,SND_ASYNC);
    if(key=='3') PlaySound("mi.wav",NULL,SND_ASYNC);
}
void mouse(int button,int state,int x,int y)
{///按下滑鼠即可播放聲音(wav檔)
    if(state==GLUT_DOWN) PlaySound("shot.wav",NULL,SND_ASYNC);
}
int main(int argc, char** argv)
{
    mp3.Load("music.mp3");///載入mp3檔
    mp3.Play();///播放mp3檔
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 sound");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
}
