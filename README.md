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

Week06
======

Week06-1
------
```C++
#include <GL/glut.h>///使用GLUT外掛
#include <stdio.h>
int N=0,vx[3000],vy[3000];///用陣列存頂點
float angle=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);///清空
    glPushMatrix();///備份矩陣
        glRotatef(angle,0,0,1);
        glScalef(0.5,0.1,0.1);
        glColor3f(0.3,0.3,1.0);
        glutSolidCube(1);
    glPopMatrix();///還原矩陣
    glutSwapBuffers();///交換2倍的buffers
}

void mouse(int button,int state,int x,int y)///控制滑鼠
{

}

void keyboard(unsigned char key,int x,int y)
{

}

void motion(int x,int y)///移動
{
    angle++;
    display();
    /*
    printf("%d %d\n",x,y);///把頂點記下來
    vx[N]=(x-150)/150.0;///換算座標
    vy[N]=-(y-150)/150.0;
    N++;
    display();///即時更新
    */
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);///GULT初始設定
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);///顯示模式
    glutCreateWindow("Move");///開視窗

    glutDisplayFunc(display);///要顯示的函式
    glutMouseFunc(mouse);///使用滑鼠函式
    glutKeyboardFunc(keyboard);///移動的函式
    glutMotionFunc(motion);///移動的函式
    glutMainLoop();///主要的迴圈
}
```

Week06-2
------
```C++
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
```

Week08
======

Week08-1
------
```C++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
void init()
{
    IplImage * img = cvLoadImage("Dora.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week08 Texture");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
}
```

Week08-2
------
```C++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
void init()
{
    IplImage * img = cvLoadImage("Dora.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glTexCoord2f(0,1); glVertex3f(-1,-1,0);
        glTexCoord2f(1,1); glVertex3f(1,-1,0);
        glTexCoord2f(1,0); glVertex3f(1,1,0);
        glTexCoord2f(0,0); glVertex3f(-1,1,0);
    glEnd();
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week08 Texture");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
}

```

Week08-3
------
```C++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad;///TODO: Quad
void init()///copy 自 http://hackmd.io/@jsyeh/opengl
{
    IplImage * img = cvLoadImage("Dora.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    quad = gluNewQuadric();///TODO: Quad
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好
float angle=0;///TODO:
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();///自動轉很帥///TODO:
        glRotatef(90, 1,0,0);///TODO:
        glRotatef(angle, 0,0,1);///自動轉很帥///TODO:
        gluQuadricTexture(quad, 1);///TODO:
        gluSphere(quad, 0.5, 30, 30);///glutSolidTeapot(0.3);///TODO:
    glPopMatrix();///自動轉很帥///TODO:
    ///glutSolidTeapot(0.3);
    glutSwapBuffers();
    angle++;///TODO:
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week08 texture_ball");
    glutDisplayFunc(display);
    glutIdleFunc(display);///TODO:
    glEnable(GL_DEPTH_TEST);///TODO: 有3D的深度測試(前面會蓋掉後面)
    init();///上面把OpenGL都設好後, 才設定 OpenCV 的貼圖到 OpenGL上面
    glutMainLoop();
}
```

Week10
======

Week10-1
------
```C++
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
```

Week10-2
------
```C++
#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 light");

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

    glutDisplayFunc(display);
    glutMainLoop();
}
```

Week11
======

Week11-1
------
```C++
#include "glm.h"///使用glm.cpp的外掛
GLMmodel* pmodel=NULL;///pmodel指標

void drawmodel(void)
{///使用範例程式
    if (!pmodel) {
        pmodel=glmReadOBJ("data/porsche.obj");///porsche模型
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel,GLM_SMOOTH|GLM_MATERIAL);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawmodel();///使用範例程式
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("08161080");

    glutDisplayFunc(display);
    glutMainLoop();
}
```

Week11-2
------
```C++
#include "glm.h"///使用glm.cpp的外掛
GLMmodel* pmodel=NULL;///pmodel指標

void drawmodel(void)
{///使用範例程式
    if (!pmodel) {
        pmodel=glmReadOBJ("data/porsche.obj");///porsche模型
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel,GLM_SMOOTH|GLM_MATERIAL);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(180,0,1,0);///旋轉
        drawmodel();///使用範例程式
    glPopMatrix();
    glutSwapBuffers();
}

///打光的陣列
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("08161080");

    ///打光的設定
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

    glutDisplayFunc(display);
    glutMainLoop();
}
```

Week12
======

Week12-1
------
```C++
#include <GL/glut.h>
#include <stdio.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 all");

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

    glutDisplayFunc(display);
    glutMainLoop();
}
```

Week13
======

Week13-1
------
```C++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>

GLuint id1, id2; ///TODO:增加2個 貼圖ID
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, id1);
    glutSolidTeapot(0.3);

    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f( 0, 0 ); glVertex2f( -1, +1 );
        glTexCoord2f( 0, 1 ); glVertex2f( -1, -1 );
        glTexCoord2f( 1, 1 ); glVertex2f( +1, -1 );
        glTexCoord2f( 1, 0 ); glVertex2f( +1, +1 );
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week13 texture");
    glutDisplayFunc(display);

    id1 = myTexture("Diffuse.jpg");///鋼彈貼圖
    id2 = myTexture("shin.png");///背景
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
```

Week13-2
------
```C++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"   ///使用外掛

GLMmodel*pmodel1=NULL;   ///glm模型指標

void drawmodel(void)    ///函式讀取鋼彈
{
    if(!pmodel1)
    {
        pmodel1=glmReadOBJ("Gundam.obj");
        if(!pmodel1)exit(0);
        glmUnitize(pmodel1);
        glmFacetNormals(pmodel1);
        glmVertexNormals(pmodel1, 90.0);
    }
    glmDraw(pmodel1,GLM_SMOOTH | GLM_TEXTURE);   ///參數
}

GLuint id1, id2; ///TODO:增加2個 貼圖ID
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, id1);
    drawmodel();

    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f( 0, 0 ); glVertex2f( -1, +1 );
        glTexCoord2f( 0, 1 ); glVertex2f( -1, -1 );
        glTexCoord2f( 1, 1 ); glVertex2f( +1, -1 );
        glTexCoord2f( 1, 0 ); glVertex2f( +1, +1 );
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week13 texture");
    glutDisplayFunc(display);

    id1 = myTexture("Diffuse.jpg");///鋼彈貼圖
    id2 = myTexture("shin.png");///背景
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
```

Week13-3
------
```C++
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
#include "glm.h"   ///使用外掛

GLMmodel*pmodel1=NULL;   ///glm模型指標

void drawmodel(void)    ///函式讀取鋼彈
{
    if(!pmodel1)
    {
        pmodel1=glmReadOBJ("Gundam.obj");
        if(!pmodel1)exit(0);
        glmUnitize(pmodel1);
        glmFacetNormals(pmodel1);
        glmVertexNormals(pmodel1, 90.0);
    }
    glmDraw(pmodel1,GLM_SMOOTH | GLM_TEXTURE);   ///參數
}

GLuint id1, id2; ///TODO:增加2個 貼圖ID
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float angle=0;///初始角度=0

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, id1);
    glPushMatrix();///畫鋼彈
        glRotatef(angle,0,1,0);///軸心旋轉
        drawmodel();
    glPopMatrix();

    glBindTexture(GL_TEXTURE_2D, id2);
    glBegin(GL_POLYGON);
        glTexCoord2f( 0, 0 ); glVertex3f( -1, +1 ,0.8);
        glTexCoord2f( 0, 1 ); glVertex3f( -1, -1 ,0.8);
        glTexCoord2f( 1, 1 ); glVertex3f( +1, -1 ,0.8);
        glTexCoord2f( 1, 0 ); glVertex3f( +1, +1 ,0.8);
    glEnd();
    glutSwapBuffers();
    angle++;///增加角度
}
int main(int argc, char** argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH );
    glutCreateWindow("week13 texture");
    glutDisplayFunc(display);
    glutIdleFunc(display);

    id1 = myTexture("Diffuse.jpg");///鋼彈貼圖
    id2 = myTexture("shin.png");///背景
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
```

Week14
======

Week14-1
------
```C++
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glutSolidSphere(0.3,30,30);///實心圓球(半徑,縱切,橫切)
    glutSwapBuffers();
}
void timer(int t)
{
    glClearColor(1,0,0,0);///清除背景色彩(紅色)
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutTimerFunc(4000,timer,0);///時間,使用的函式,參數

    glutMainLoop();
}
```

Week14-2
------
```C++
#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidCube(0.3);///glutSolidSphere(0.3,30,30);///實心圓球(半徑,縱切,橫切)
    glPopMatrix();
    glutSwapBuffers();
}
void timer(int t)///timer執行
{
    glutTimerFunc(30,timer,t+1);///設定下一個timer
    angle++;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutTimerFunc(3000,timer,0);///第1個timer///時間,使用的函式,參數

    glutMainLoop();
}
```

Week14-3
------
```C++
#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidCube(0.3);///glutSolidSphere(0.3,30,30);///實心圓球(半徑,縱切,橫切)
    glPopMatrix();
    glutSwapBuffers();
}
int diff=1;
void timer(int t)///timer執行
{
    glutTimerFunc(20,timer,t+1);///設定下一個timer
    angle+=diff;
    if(angle>180) diff=-diff;
    if(angle<0) diff=-diff;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutTimerFunc(3000,timer,0);///第1個timer///時間,使用的函式,參數

    glutMainLoop();
}
```
