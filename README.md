# 2021電腦圖學

Week03_210308
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

Week04_210315
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

Week05_210322
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

Week06_210329
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

Week08_210412
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

Week10_210426
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

Week11_210503
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

Week12_210510
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

Week13_210517
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

Week14_210524
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

Week14-4
------
```C++
#include <GL/glut.h>
int angle=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);///白色
        glutSolidCube(0.4);///身體
        glPushMatrix();
            glTranslatef(-0.2,+0.2,0);///放到左上角
            glRotatef(angle,0,0,1);///左手旋轉
            glColor3f(1,0,0);///紅色
            glutSolidCube(0.3);///左手
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int diff=2;
void timer(int t)///timer執行
{
    glutTimerFunc(20,timer,t+1);///設定下一個timer
    angle+=diff;
    if(angle>90||angle<0) diff=-diff;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);///第1個timer///時間,使用的函式,參數
    glutMainLoop();
}
```

Week14-5
------
```C++
#include <GL/glut.h>
int angle=0;
void drawArm1()
{
    glPushMatrix();
        glScalef(1,0.5,0.5);
        glColor3f(1,0,0);
        glutSolidCube(0.3);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);///白色
        glutSolidCube(0.4);///身體
        glPushMatrix();
            glTranslatef(-0.2,+0.2,0);///放到左上角
            glRotatef(angle,0,0,1);///旋轉
            glTranslatef(-0.15,0,0);///手臂頂端放到身體邊緣
            drawArm1();///畫手臂
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int diff=2;
void timer(int t)///timer執行
{
    glutTimerFunc(20,timer,t+1);///設定下一個timer
    angle+=diff;
    if(angle>90||angle<0) diff=-diff;
    display();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);///第1個timer///時間,使用的函式,參數
    glutMainLoop();
}
```

Week15_210531
======

Week15-1
------
```C++
#include <stdio.h>
int main(int argc,char** argv)
{
    /*FILE*fout=NULL;///檔案指標 file output 變數
    fout=fopen("檔名.txt","w+");///開啟檔案(檔名.txt,模式write+)
    printf("Hello World\n");
    fprintf(fout,"Hello World\n");*/

    FILE*fin=NULL;
    fin=fopen("檔名.txt","r");///讀取檔案(檔名.txt,模式read)

    char line[1000];
    fscanf(fin,"%s",line);///讀入字串
    printf("現在讀到的是:%s\n",line);///印出字串
    fscanf(fin,"%s",line);///讀入字串
    printf("現在讀到的是:%s\n",line);///印出字串
}
```

Week15-2
------
```C++
#include <stdio.h>
#include <GL/glut.h>
float angle=0,diff=2;///角度
///float angle[20]={};
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);///設定下一個計時器
    angle+=diff;///改變角度
    if(angle>90) diff=-2;
    if(angle<0) diff=2;
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle,0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///左上臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle,0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///左下臂
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle,0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///右上臂
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle,0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///右下臂
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week15");

    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
}
```

Week16_210607
======

Week16-1
------
```C++
#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;///角度
int angleID=0;
void timer(int t)
{
    glutTimerFunc(30,timer,t+1);///設定下一個計時器
    angle[angleID]+=diff;
    if(angle[angleID]>90) diff=-2;
    if(angle[angleID]<0) diff=2;
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle[0],0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///左上臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle[1],0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///左下臂
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle[2],0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///右上臂
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle[3],0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///右下臂
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

    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    glutTimerFunc(0,timer,0);
    glutMainLoop();
}
```

Week16-2
------
```C++
#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;///角度
int angleID=0;
void timer(int t)
{
    /*glutTimerFunc(30,timer,t+1);///設定下一個計時器
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
void motion(int x,int y)
{
    angle[angleID]+=x-oldX;
    oldX=x;
    glutPostRedisplay();
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle[0],0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///左上臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle[1],0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///左下臂
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle[2],0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///右上臂
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle[3],0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///右下臂
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
```

Week16-3
------
```C++
#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;///角度
int angleID=0;
void timer(int t)
{
    /*glutTimerFunc(30,timer,t+1);///設定下一個計時器
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
void motion(int x,int y)
{
    angle[angleID]+=x-oldX;
    oldX=x;
    glutPostRedisplay();
}
FILE*fout=NULL;
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
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle[0],0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///左上臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle[1],0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///左下臂
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle[2],0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///右上臂
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle[3],0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///右下臂
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
```

Week16-4
------
```C++
#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;///角度
int angleID=0;
void timer(int t)
{
    /*glutTimerFunc(30,timer,t+1);///設定下一個計時器
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
void motion(int x,int y)
{
    angle[angleID]+=x-oldX;
    oldX=x;
    glutPostRedisplay();
}
FILE*fout=NULL;
FILE*fin=NULL;
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
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle[0],0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///左上臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle[1],0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///左下臂
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle[2],0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///右上臂
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle[3],0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///右下臂
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
```

Week16-5
------
```C++
#include <stdio.h>
#include <GL/glut.h>
float angle[20]={},diff=2;///角度
int angleID=0;
void timer(int t)
{
    /*glutTimerFunc(30,timer,t+1);///設定下一個計時器
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
        glutSolidTeapot(0.3);///身體
        glPushMatrix();
            glTranslatef(-0.3,0,0);
            glRotatef(angle[0],0,0,1);
            glTranslatef(-0.3,0,0);
            glutSolidTeapot(0.3);///左上臂
            glPushMatrix();
                glTranslatef(-0.3,0,0);
                glRotatef(angle[1],0,0,1);
                glTranslatef(-0.3,0,0);
                glutSolidTeapot(0.3);///左下臂
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.3,0,0);
            glRotatef(-angle[2],0,0,1);
            glTranslatef(0.3,0,0);
            glutSolidTeapot(0.3);///右上臂
            glPushMatrix();
                glTranslatef(0.3,0,0);
                glRotatef(-angle[3],0,0,1);
                glTranslatef(0.3,0,0);
                glutSolidTeapot(0.3);///右下臂
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
```

Week17_210614
======

Week17-1
------
```C++
#include <GL/glut.h>
void display(){
    glClearColor( 1,0,0,0);///用來Clear的Color 用紅色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glColor3f( 1,1,0 );
        glutSolidTeapot( 0.3 );
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
```

Week17-2
------
```C++
#include <GL/glut.h>
#include <stdio.h>
FILE * fout = NULL;
FILE * fin = NULL;
float angle[20]={};///先都設成0
int angleID=0;///現在要動的關節是誰?
void keyboard(unsigned char key, int x, int y){
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
    if(key=='s'){///存檔
        if( fout==NULL ) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++) fprintf(fout, "%.2f ", angle[i]);
        fprintf(fout, "\n");
        printf("save angle.txt\n");
    }else if(key=='r'){///讀檔 (不能和存檔同時做,因angle.txt不能開2次)
        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angle[i]);
        glutPostRedisplay();///重畫畫面
        printf("read angle.txt\n");
    }
}///如果關節很多, 可能要用迴圈來讓程式只要2行 for(int i=0; i<10; i++)
///可能也要用到英文字母
float oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion( int x, int y ){
    angle[angleID] += x-oldX;///0: angle[0], 1: angle[1]..
    oldX = x;
    glutPostRedisplay();///重畫畫面
}
void display(){
    glClearColor( 1,0,0,0);///用來Clear的Color 用紅色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f( 1,1,0 );
        glutSolidTeapot( 0.3 );///身體先註解掉身體,只看手臂
        glPushMatrix();///左半邊
            glTranslatef(-.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
            glRotatef(angle[0], 0,0,1);///(2)再轉動它
            glTranslatef(-.3, .1, 0);///(1)移動旋轉中心,放正中心
            glutSolidTeapot(0.3);///左手臂
            glPushMatrix();
                glTranslatef(-.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
                glRotatef(angle[1], 0,0,1);///(2)再轉動它
                glTranslatef(-.3, 0, 0);///(1)移動旋轉中心,放正中心
                glutSolidTeapot(0.3);///左手肘
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();///右半邊
            glTranslatef(+.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
            glRotatef(angle[2], 0,0,1);///(2)再轉動它
            glTranslatef(+.3, .1, 0);///(1)移動旋轉中心,放正中心
            glutSolidTeapot(0.3);///右手臂
            glPushMatrix();
                glTranslatef(+.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
                glRotatef(angle[3], 0,0,1);///(2)再轉動它
                glTranslatef(+.3, 0, 0);///(1)移動旋轉中心,放正中心
                glutSolidTeapot(0.3);///右手肘
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
```

Week17-3
------
```C++
#include <GL/glut.h>
#include <stdio.h>
FILE * fout = NULL;
FILE * fin = NULL;
float angle[20]={}, angleOld[20], angleNew[20];///先都設成0
int angleID=0;///現在要動的關節是誰?
void timer(int t){
    glutTimerFunc( 20, timer, t+1);
    if(t%25==0){
        for(int i=0; i<20; i++) angleOld[i] = angleNew[i];

        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angleNew[i]);
        printf("read angle.txt\n");
    }
    float alpha = (t%25)/25.0;///介於 0.0 舊 - 1.0 新 之間 (請代入 0, 0.5, 1 觀察)
    for(int i=0; i<20; i++) angle[i] = alpha*angleNew[i]+(1-alpha)*angleOld[i];
    glutPostRedisplay();///重畫畫面
}
void keyboard(unsigned char key, int x, int y){
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    if(key=='6') angleID=6;
    if(key=='p'){///Play播放
        glutTimerFunc(0, timer, 0);///一開始的第1個timer
    }
    if(key=='s'){///存檔
        if( fout==NULL ) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++) fprintf(fout, "%.2f ", angle[i]);
        fprintf(fout, "\n");
        printf("save angle.txt\n");
    }else if(key=='r'){///讀檔 (不能和存檔同時做,因angle.txt不能開2次)
        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angle[i]);
        glutPostRedisplay();///重畫畫面
        printf("read angle.txt\n");
    }
}///如果關節很多, 可能要用迴圈來讓程式只要2行 for(int i=0; i<10; i++)
///可能也要用到英文字母
float oldX=0;
void mouse(int button, int state, int x, int y){
    oldX = x;
}
void motion( int x, int y ){
    angle[angleID] += x-oldX;///0: angle[0], 1: angle[1]..
    oldX = x;
    glutPostRedisplay();///重畫畫面
}
void display(){
    glClearColor( 1,0,0,0);///用來Clear的Color 用紅色
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f( 1,1,0 );
        glutSolidTeapot( 0.3 );///身體先註解掉身體,只看手臂
        glPushMatrix();///左半邊
            glTranslatef(-.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
            glRotatef(angle[0], 0,0,1);///(2)再轉動它
            glTranslatef(-.3, .1, 0);///(1)移動旋轉中心,放正中心
            glutSolidTeapot(0.3);///左手臂
            glPushMatrix();
                glTranslatef(-.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
                glRotatef(angle[1], 0,0,1);///(2)再轉動它
                glTranslatef(-.3, 0, 0);///(1)移動旋轉中心,放正中心
                glutSolidTeapot(0.3);///左手肘
            glPopMatrix();
        glPopMatrix();
        glPushMatrix();///右半邊
            glTranslatef(+.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
            glRotatef(angle[2], 0,0,1);///(2)再轉動它
            glTranslatef(+.3, .1, 0);///(1)移動旋轉中心,放正中心
            glutSolidTeapot(0.3);///右手臂
            glPushMatrix();
                glTranslatef(+.3, 0, 0);///(3)再把轉動中的手臂,掛到肩上
                glRotatef(angle[3], 0,0,1);///(2)再轉動它
                glTranslatef(+.3, 0, 0);///(1)移動旋轉中心,放正中心
                glutSolidTeapot(0.3);///右手肘
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
```

Week17-4
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
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main( int argc, char ** argv )
{
    glutInit( &argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("08161080");

    glutDisplayFunc(display);

    id2 = myTexture("shin.png");
    glEnable(GL_DEPTH_TEST);///3D的深度測試功能要開起來,3D才會正確
    glutMainLoop();
}
```

Week17-5
------
```C++
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

GLuint id1,id2;///貼圖ID

///打光
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
    glutPostRedisplay();///重畫畫面
}

void keyboard(unsigned char key, int x, int y)
{
    ///身體xyz
    if(key=='0') angleID=0;
    if(key=='1') angleID=1;
    if(key=='2') angleID=2;
    ///頭xyz
    if(key=='3') angleID=3;
    if(key=='4') angleID=4;
    if(key=='5') angleID=5;
    ///左手xyz
    if(key=='6') angleID=6;
    if(key=='7') angleID=7;
    if(key=='8') angleID=8;
    ///右手xyz
    if(key=='a') angleID=9;
    if(key=='b') angleID=10;
    if(key=='c') angleID=11;
    ///左腳xyz
    if(key=='d') angleID=12;
    if(key=='e') angleID=13;
    if(key=='f') angleID=14;
    ///右腳xyz
    if(key=='g') angleID=15;
    if(key=='h') angleID=16;
    if(key=='i') angleID=17;

    ///播動作&音樂
    if(key=='p'||key=='P')
    {
        glutTimerFunc(0,timer,0);
        PlaySound("Papepipupo.wav",NULL,SND_ASYNC);
    }

    ///存取檔案
    if(key=='s')
    {
        if( fout==NULL ) fout = fopen("angle.txt", "w+");
        for(int i=0; i<20; i++) fprintf(fout, "%.2f ", angle[i]);
        fprintf(fout, "\n");
        printf("save angle.txt\n");
    }
    else if(key=='r'){///讀檔案
        if( fin==NULL ) fin = fopen("angle.txt", "r");
        for(int i=0; i<20; i++) fscanf(fin, "%f", &angle[i]);
        glutPostRedisplay();///重畫畫面
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
    glutPostRedisplay();///重畫畫面
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBindTexture(GL_TEXTURE_2D,id1);

    glPushMatrix();///畫身體
        glRotatef(angle[2],0,0,1);
        glRotatef(angle[1],0,1,0);
        glRotatef(angle[0],1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(body,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///畫頭
        glRotatef(angle[5],0,0,1);
        glRotatef(angle[4],0,1,0);
        glRotatef(angle[3],1,0,0);
        glRotatef(180,0,1,0);
        glTranslatef(0,-0.4,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(head,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///畫左手
        glTranslatef(0,0,0);
        glRotatef(angle[8],0,0,1);
        glRotatef(angle[7],0,1,0);
        glRotatef(angle[6],1,0,0);
        glTranslatef(0,-0.4,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(handl,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///畫右手
        glTranslatef(0,0,0);
        glRotatef(angle[11],0,0,1);
        glRotatef(angle[10],0,1,0);
        glRotatef(angle[9],1,0,0);
        glTranslatef(0,-0.4,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(handr,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///畫左腳
        glTranslatef(0,0,0);
        glRotatef(angle[14],0,0,1);
        glRotatef(angle[13],0,1,0);
        glRotatef(angle[12],1,0,0);
        glTranslatef(0,-0.3,0);
        glScalef(0.25,0.25,0.25);
        glmDraw(footl,GLM_SMOOTH|GLM_TEXTURE);
    glPopMatrix();

    glPushMatrix();///畫右腳
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
    cvShowImage("08161080",img);///秀出一張圖
    cvWaitKey(0);///等按任意鍵,才能做接下來的動作

    glutInit(&argc,argv);
    glutInitWindowSize(500,500);///視窗大小
    glutInitWindowPosition(200,200);///視窗位置
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("Dance");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);

    id1 = myTexture("blue.png");///模型
    id2 = myTexture("shin.png");///背景

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
```

Week17-6
------
```C++
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

2.00 87.00 0.00 0.00 91.00 0.00 0.00 47.00 0.00 0.00 104.00 0.00 0.00 64.00 0.00 0.00 41.00 9.00 0.00 0.00 
2.00 2.00 0.00 0.00 2.00 0.00 0.00 -9.00 0.00 0.00 15.00 0.00 0.00 -16.00 0.00 0.00 -24.00 0.00 0.00 0.00 
-15.00 2.00 0.00 -20.00 2.00 0.00 -181.00 -9.00 0.00 -186.00 15.00 0.00 0.00 -16.00 0.00 0.00 -24.00 0.00 0.00 0.00 
2.00 -68.00 0.00 -2.00 -71.00 0.00 3.00 -96.00 0.00 9.00 -45.00 0.00 0.00 -59.00 -9.00 0.00 -18.00 0.00 0.00 0.00 

2.00 -3.00 0.00 -1.00 -1.00 0.00 -174.00 -1.00 0.00 -179.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -362.00 -1.00 0.00 -349.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -542.00 -1.00 0.00 -534.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -722.00 -1.00 0.00 -714.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 

2.00 -2.00 0.00 -1.00 -1.00 0.00 -808.00 -55.00 -1.00 -808.00 56.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -2.00 0.00 -20.00 2.00 0.00 -913.00 16.00 -1.00 -878.00 -23.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -2.00 0.00 -1.00 -1.00 0.00 -799.00 -55.00 -1.00 -801.00 52.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 

5.00 0.00 0.00 11.00 -5.00 0.00 -718.00 4.00 0.00 -733.00 -24.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
-18.00 2.00 -1.00 -17.00 1.00 0.00 -718.00 4.00 0.00 -733.00 -24.00 0.00 -8.00 10.00 -7.00 -9.00 0.00 5.00 0.00 0.00 
-6.00 2.00 -1.00 -2.00 1.00 0.00 -805.00 -53.00 0.00 -806.00 57.00 0.00 1.00 10.00 0.00 0.00 0.00 2.00 0.00 0.00 
-6.00 2.00 -1.00 -2.00 1.00 0.00 -728.00 16.00 0.00 -720.00 -1.00 0.00 1.00 10.00 0.00 0.00 0.00 2.00 0.00 0.00 
6.00 0.00 0.00 7.00 0.00 0.00 -748.00 -54.00 0.00 -745.00 64.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

-6.00 2.00 -1.00 -2.00 1.00 0.00 -548.00 16.00 0.00 -525.00 -1.00 0.00 1.00 10.00 0.00 0.00 0.00 2.00 0.00 0.00 
-6.00 2.00 -1.00 -2.00 1.00 0.00 -366.00 16.00 0.00 -374.00 -1.00 0.00 1.00 10.00 0.00 0.00 0.00 2.00 0.00 0.00 
-6.00 2.00 -1.00 -2.00 1.00 0.00 -168.00 16.00 0.00 -179.00 -1.00 0.00 1.00 10.00 0.00 0.00 0.00 2.00 0.00 0.00 
-6.00 2.00 -1.00 -2.00 1.00 0.00 -11.00 16.00 0.00 22.00 -1.00 0.00 1.00 10.00 0.00 0.00 0.00 2.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 4.00 0.00 0.00 -167.00 0.00 0.00 -33.00 0.00 0.00 13.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -186.00 0.00 0.00 12.00 0.00 0.00 9.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -10.00 0.00 0.00 -8.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -36.00 0.00 0.00 -37.00 0.00 0.00 0.00 0.00 
-12.00 1.00 0.00 -12.00 0.00 0.00 -192.00 0.00 0.00 -184.00 0.00 0.00 -9.00 0.00 0.00 -10.00 0.00 0.00 0.00 0.00 
-3.00 1.00 0.00 3.00 0.00 0.00 -31.00 0.00 0.00 -9.00 0.00 0.00 -34.00 0.00 0.00 -34.00 0.00 0.00 0.00 0.00 
-20.00 1.00 0.00 -20.00 0.00 0.00 -190.00 0.00 0.00 -170.00 0.00 0.00 -11.00 0.00 0.00 -7.00 0.00 0.00 0.00 0.00 
2.00 1.00 0.00 7.00 0.00 0.00 13.00 0.00 0.00 -12.00 0.00 0.00 -41.00 0.00 0.00 -41.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 4.00 0.00 0.00 -167.00 0.00 0.00 -33.00 0.00 0.00 13.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -186.00 0.00 0.00 12.00 0.00 0.00 9.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -10.00 0.00 0.00 -8.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -36.00 0.00 0.00 -37.00 0.00 0.00 0.00 0.00 
-12.00 1.00 0.00 -12.00 0.00 0.00 -192.00 0.00 0.00 -184.00 0.00 0.00 -9.00 0.00 0.00 -10.00 0.00 0.00 0.00 0.00 
-3.00 1.00 0.00 3.00 0.00 0.00 -31.00 0.00 0.00 -9.00 0.00 0.00 -34.00 0.00 0.00 -34.00 0.00 0.00 0.00 0.00 
-20.00 1.00 0.00 -20.00 0.00 0.00 -190.00 0.00 0.00 -170.00 0.00 0.00 -11.00 0.00 0.00 -7.00 0.00 0.00 0.00 0.00 
2.00 1.00 0.00 7.00 0.00 0.00 13.00 0.00 0.00 -12.00 0.00 0.00 -41.00 0.00 0.00 -41.00 0.00 0.00 0.00 0.00 
-20.00 1.00 0.00 -20.00 0.00 0.00 -190.00 0.00 0.00 -170.00 0.00 0.00 -11.00 0.00 0.00 -7.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 -2.00 -4.00 0.00 0.00 -8.00 2.00 0.00 0.00 -188.00 0.00 0.00 -4.00 0.00 -8.00 0.00 0.00 0.00 0.00 0.00 
0.00 -2.00 7.00 0.00 0.00 5.00 -193.00 0.00 0.00 10.00 0.00 0.00 -4.00 0.00 -1.00 0.00 0.00 14.00 0.00 0.00 
0.00 -2.00 -9.00 0.00 0.00 -10.00 2.00 0.00 0.00 -144.00 0.00 0.00 -4.00 0.00 -16.00 0.00 0.00 -1.00 0.00 0.00 
0.00 -2.00 6.00 0.00 0.00 6.00 -181.00 0.00 0.00 16.00 0.00 0.00 -4.00 0.00 -2.00 0.00 0.00 6.00 0.00 0.00 

0.00 -2.00 -4.00 0.00 0.00 -8.00 2.00 0.00 0.00 -188.00 0.00 0.00 -4.00 0.00 -8.00 0.00 0.00 0.00 0.00 0.00 
0.00 -2.00 7.00 0.00 0.00 5.00 -193.00 0.00 0.00 10.00 0.00 0.00 -4.00 0.00 -1.00 0.00 0.00 14.00 0.00 0.00 
0.00 -2.00 -9.00 0.00 0.00 -10.00 2.00 0.00 0.00 -144.00 0.00 0.00 -4.00 0.00 -16.00 0.00 0.00 -1.00 0.00 0.00 
0.00 -2.00 6.00 0.00 0.00 6.00 -181.00 0.00 0.00 16.00 0.00 0.00 -4.00 0.00 -2.00 0.00 0.00 6.00 0.00 0.00 

0.00 -2.00 -4.00 0.00 0.00 -8.00 2.00 0.00 0.00 -188.00 0.00 0.00 -4.00 0.00 -8.00 0.00 0.00 0.00 0.00 0.00 
0.00 -2.00 7.00 0.00 0.00 5.00 -193.00 0.00 0.00 10.00 0.00 0.00 -4.00 0.00 -1.00 0.00 0.00 14.00 0.00 0.00 
0.00 -2.00 -9.00 0.00 0.00 -10.00 2.00 0.00 0.00 -144.00 0.00 0.00 -4.00 0.00 -16.00 0.00 0.00 -1.00 0.00 0.00 
0.00 -2.00 6.00 0.00 0.00 6.00 -181.00 0.00 0.00 16.00 0.00 0.00 -4.00 0.00 -2.00 0.00 0.00 6.00 0.00 0.00 

0.00 -2.00 -4.00 0.00 0.00 -8.00 2.00 0.00 0.00 -188.00 0.00 0.00 -4.00 0.00 -8.00 0.00 0.00 0.00 0.00 0.00 
0.00 -2.00 7.00 0.00 0.00 5.00 -193.00 0.00 0.00 10.00 0.00 0.00 -4.00 0.00 -1.00 0.00 0.00 14.00 0.00 0.00 
0.00 -2.00 -9.00 0.00 0.00 -10.00 2.00 0.00 0.00 -144.00 0.00 0.00 -4.00 0.00 -16.00 0.00 0.00 -1.00 0.00 0.00 
0.00 -2.00 6.00 0.00 0.00 6.00 -181.00 0.00 0.00 16.00 0.00 0.00 -4.00 0.00 -2.00 0.00 0.00 6.00 0.00 0.00 

0.00 -2.00 -4.00 0.00 0.00 -8.00 2.00 0.00 0.00 -188.00 0.00 0.00 -4.00 0.00 -8.00 0.00 0.00 0.00 0.00 0.00 
0.00 -2.00 7.00 0.00 0.00 5.00 -193.00 0.00 0.00 10.00 0.00 0.00 -4.00 0.00 -1.00 0.00 0.00 14.00 0.00 0.00 
0.00 -2.00 -9.00 0.00 0.00 -10.00 2.00 0.00 0.00 -144.00 0.00 0.00 -4.00 0.00 -16.00 0.00 0.00 -1.00 0.00 0.00 
0.00 -2.00 6.00 0.00 0.00 6.00 -181.00 0.00 0.00 16.00 0.00 0.00 -4.00 0.00 -2.00 0.00 0.00 6.00 0.00 0.00 

0.00 -2.00 -4.00 0.00 0.00 -8.00 2.00 0.00 0.00 -188.00 0.00 0.00 -4.00 0.00 -8.00 0.00 0.00 0.00 0.00 0.00 
0.00 -2.00 7.00 0.00 0.00 5.00 -193.00 0.00 0.00 10.00 0.00 0.00 -4.00 0.00 -1.00 0.00 0.00 14.00 0.00 0.00 

2.00 87.00 0.00 0.00 91.00 0.00 0.00 47.00 0.00 0.00 104.00 0.00 0.00 64.00 0.00 0.00 41.00 9.00 0.00 0.00 
2.00 2.00 0.00 0.00 2.00 0.00 0.00 -9.00 0.00 0.00 15.00 0.00 0.00 -16.00 0.00 0.00 -24.00 0.00 0.00 0.00 
-15.00 2.00 0.00 -20.00 2.00 0.00 -181.00 -9.00 0.00 -186.00 15.00 0.00 0.00 -16.00 0.00 0.00 -24.00 0.00 0.00 0.00 
2.00 -68.00 0.00 -2.00 -71.00 0.00 3.00 -96.00 0.00 9.00 -45.00 0.00 0.00 -59.00 -9.00 0.00 -18.00 0.00 0.00 0.00 

2.00 -3.00 0.00 -1.00 -1.00 0.00 -174.00 -1.00 0.00 -179.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -362.00 -1.00 0.00 -349.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -542.00 -1.00 0.00 -534.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -722.00 -1.00 0.00 -714.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 

2.00 -2.00 0.00 -1.00 -1.00 0.00 -808.00 -55.00 -1.00 -808.00 56.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -2.00 0.00 -20.00 2.00 0.00 -913.00 16.00 -1.00 -878.00 -23.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -2.00 0.00 -1.00 -1.00 0.00 -799.00 -55.00 -1.00 -801.00 52.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00
0.00 0.00 0.00 0.00 0.00 0.00 -802.00 19.00 0.00 -794.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 

0.00 72.00 1.00 -10.00 67.00 0.00 -755.00 63.00 0.00 -756.00 86.00 0.00 -12.00 82.00 0.00 16.00 81.00 0.00 0.00 0.00 
0.00 -68.00 1.00 10.00 -64.00 0.00 -730.00 -111.00 0.00 -744.00 -54.00 0.00 -17.00 -109.00 0.00 0.00 -30.00 0.00 0.00 0.00 
0.00 72.00 1.00 -10.00 67.00 0.00 -755.00 63.00 0.00 -756.00 86.00 0.00 -12.00 82.00 0.00 16.00 81.00 0.00 0.00 0.00 
0.00 -68.00 1.00 10.00 -64.00 0.00 -730.00 -111.00 0.00 -744.00 -54.00 0.00 -17.00 -109.00 0.00 0.00 -30.00 0.00 0.00 0.00 
0.00 72.00 1.00 -10.00 67.00 0.00 -755.00 63.00 0.00 -756.00 86.00 0.00 -12.00 82.00 0.00 16.00 81.00 0.00 0.00 0.00 
0.00 -68.00 1.00 10.00 -64.00 0.00 -730.00 -111.00 0.00 -744.00 -54.00 0.00 -17.00 -109.00 0.00 0.00 -30.00 0.00 0.00 0.00 
0.00 72.00 1.00 -10.00 67.00 0.00 -755.00 63.00 0.00 -756.00 86.00 0.00 -12.00 82.00 0.00 16.00 81.00 0.00 0.00 0.00 
0.00 -68.00 1.00 10.00 -64.00 0.00 -730.00 -111.00 0.00 -744.00 -54.00 0.00 -17.00 -109.00 0.00 0.00 -30.00 0.00 0.00 0.00 
0.00 72.00 1.00 -10.00 67.00 0.00 -755.00 63.00 0.00 -756.00 86.00 0.00 -12.00 82.00 0.00 16.00 81.00 0.00 0.00 0.00 
0.00 -68.00 1.00 10.00 -64.00 0.00 -730.00 -111.00 0.00 -744.00 -54.00 0.00 -17.00 -109.00 0.00 0.00 -30.00 0.00 0.00 0.00 
0.00 72.00 1.00 -10.00 67.00 0.00 -755.00 63.00 0.00 -756.00 86.00 0.00 -12.00 82.00 0.00 16.00 81.00 0.00 0.00 0.00 
0.00 -68.00 1.00 10.00 -64.00 0.00 -730.00 -111.00 0.00 -744.00 -54.00 0.00 -17.00 -109.00 0.00 0.00 -30.00 0.00 0.00 0.00 

0.00 -82.00 7.00 7.00 -61.00 0.00 -741.00 -108.00 0.00 -764.00 -68.00 0.00 0.00 -109.00 -15.00 0.00 0.00 0.00 0.00 0.00 
0.00 2.00 -6.00 -2.00 4.00 -10.00 -736.00 24.00 0.00 -900.00 -12.00 0.00 0.00 3.00 -8.00 0.00 0.00 0.00 0.00 0.00 
0.00 2.00 4.00 -2.00 4.00 5.00 -902.00 24.00 0.00 -726.00 -12.00 0.00 0.00 3.00 3.00 0.00 0.00 13.00 0.00 0.00 
0.00 2.00 -7.00 -2.00 2.00 -8.00 -748.00 24.00 0.00 -886.00 -12.00 0.00 0.00 3.00 -12.00 0.00 0.00 -3.00 0.00 0.00 
0.00 2.00 6.00 -2.00 2.00 6.00 -891.00 24.00 0.00 -712.00 -12.00 0.00 0.00 3.00 1.00 0.00 0.00 7.00 0.00 0.00 
0.00 2.00 1.00 -2.00 2.00 0.00 -734.00 24.00 0.00 -712.00 -12.00 0.00 0.00 3.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 2.00 1.00 -2.00 2.00 0.00 -546.00 24.00 0.00 -554.00 -12.00 0.00 0.00 3.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 2.00 1.00 -2.00 2.00 0.00 -384.00 24.00 0.00 -392.00 -12.00 0.00 0.00 3.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 2.00 1.00 -2.00 2.00 0.00 -181.00 24.00 0.00 -176.00 -12.00 0.00 0.00 3.00 0.00 0.00 0.00 0.00 0.00 0.00 
0.00 2.00 1.00 -2.00 2.00 0.00 -8.00 24.00 0.00 0.00 -12.00 0.00 0.00 3.00 0.00 0.00 0.00 0.00 0.00 0.00 

-14.00 2.00 0.00 -13.00 3.00 0.00 -85.00 -48.00 0.00 -81.00 53.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
-1.00 2.00 0.00 5.00 3.00 0.00 -33.00 22.00 0.00 -5.00 4.00 0.00 -41.00 0.00 0.00 -41.00 0.00 0.00 0.00 0.00 

0.00 -65.00 -9.00 0.00 -68.00 -11.00 1.00 -110.00 0.00 0.00 -36.00 0.00 -21.00 -79.00 0.00 -4.00 60.00 0.00 0.00 0.00 
0.00 78.00 -9.00 0.00 76.00 -11.00 22.00 37.00 0.00 0.00 114.00 0.00 13.00 50.00 -7.00 -4.00 93.00 0.00 0.00 0.00 
0.00 -65.00 -9.00 0.00 -68.00 -11.00 1.00 -110.00 0.00 0.00 -36.00 0.00 -21.00 -79.00 0.00 -4.00 60.00 0.00 0.00 0.00 
0.00 78.00 -9.00 0.00 76.00 -11.00 22.00 37.00 0.00 0.00 114.00 0.00 13.00 50.00 -7.00 -4.00 93.00 0.00 0.00 0.00 
0.00 -65.00 -9.00 0.00 -68.00 -11.00 1.00 -110.00 0.00 0.00 -36.00 0.00 -21.00 -79.00 0.00 -4.00 60.00 0.00 0.00 0.00 
0.00 78.00 -9.00 0.00 76.00 -11.00 22.00 37.00 0.00 0.00 114.00 0.00 13.00 50.00 -7.00 -4.00 93.00 0.00 0.00 0.00 
0.00 -65.00 -9.00 0.00 -68.00 -11.00 1.00 -110.00 0.00 0.00 -36.00 0.00 -21.00 -79.00 0.00 -4.00 60.00 0.00 0.00 0.00 
0.00 78.00 -9.00 0.00 76.00 -11.00 22.00 37.00 0.00 0.00 114.00 0.00 13.00 50.00 -7.00 -4.00 93.00 0.00 0.00 0.00 
0.00 -65.00 -9.00 0.00 -68.00 -11.00 1.00 -110.00 0.00 0.00 -36.00 0.00 -21.00 -79.00 0.00 -4.00 60.00 0.00 0.00 0.00 
0.00 78.00 -9.00 0.00 76.00 -11.00 22.00 37.00 0.00 0.00 114.00 0.00 13.00 50.00 -7.00 -4.00 93.00 0.00 0.00 0.00 
0.00 -65.00 -9.00 0.00 -68.00 -11.00 1.00 -110.00 0.00 0.00 -36.00 0.00 -21.00 -79.00 0.00 -4.00 60.00 0.00 0.00 0.00 
0.00 78.00 -9.00 0.00 76.00 -11.00 22.00 37.00 0.00 0.00 114.00 0.00 13.00 50.00 -7.00 -4.00 93.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
-19.00 0.00 0.00 -14.00 0.00 0.00 -121.00 0.00 0.00 -117.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
-4.00 0.00 0.00 5.00 0.00 0.00 -10.00 0.00 0.00 -1.00 0.00 0.00 -42.00 0.00 0.00 -39.00 0.00 0.00 0.00 0.00 
-22.00 0.00 0.00 -20.00 0.00 0.00 -115.00 0.00 0.00 -120.00 0.00 0.00 -16.00 0.00 0.00 -20.00 0.00 0.00 0.00 0.00 
4.00 0.00 0.00 11.00 0.00 0.00 12.00 0.00 0.00 6.00 0.00 0.00 -33.00 0.00 0.00 -34.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 0.00 
-3.00 1.00 -11.00 0.00 0.00 -10.00 0.00 0.00 0.00 -85.00 55.00 0.00 0.00 0.00 -15.00 0.00 0.00 0.00 0.00 0.00 
-3.00 1.00 7.00 0.00 0.00 7.00 -87.00 -53.00 0.00 19.00 10.00 0.00 0.00 0.00 1.00 0.00 0.00 10.00 0.00 0.00 
-3.00 1.00 -11.00 0.00 0.00 -10.00 0.00 0.00 0.00 -85.00 55.00 0.00 0.00 0.00 -15.00 0.00 0.00 0.00 0.00 0.00 
-3.00 1.00 7.00 0.00 0.00 7.00 -87.00 -53.00 0.00 19.00 10.00 0.00 0.00 0.00 1.00 0.00 0.00 10.00 0.00 0.00 
-3.00 1.00 -11.00 0.00 0.00 -10.00 0.00 0.00 0.00 -85.00 55.00 0.00 0.00 0.00 -15.00 0.00 0.00 0.00 0.00 0.00 
-3.00 1.00 7.00 0.00 0.00 7.00 -87.00 -53.00 0.00 19.00 10.00 0.00 0.00 0.00 1.00 0.00 0.00 10.00 0.00 0.00 
-3.00 1.00 -11.00 0.00 0.00 -10.00 0.00 0.00 0.00 -85.00 55.00 0.00 0.00 0.00 -15.00 0.00 0.00 0.00 0.00 0.00 
-3.00 1.00 7.00 0.00 0.00 7.00 -87.00 -53.00 0.00 19.00 10.00 0.00 0.00 0.00 1.00 0.00 0.00 10.00 0.00 0.00 


0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 4.00 0.00 0.00 -167.00 0.00 0.00 -33.00 0.00 0.00 13.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -186.00 0.00 0.00 12.00 0.00 0.00 9.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -10.00 0.00 0.00 -8.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -36.00 0.00 0.00 -37.00 0.00 0.00 0.00 0.00 
-12.00 1.00 0.00 -12.00 0.00 0.00 -192.00 0.00 0.00 -184.00 0.00 0.00 -9.00 0.00 0.00 -10.00 0.00 0.00 0.00 0.00 
-3.00 1.00 0.00 3.00 0.00 0.00 -31.00 0.00 0.00 -9.00 0.00 0.00 -34.00 0.00 0.00 -34.00 0.00 0.00 0.00 0.00 
-20.00 1.00 0.00 -20.00 0.00 0.00 -190.00 0.00 0.00 -170.00 0.00 0.00 -11.00 0.00 0.00 -7.00 0.00 0.00 0.00 0.00 
2.00 1.00 0.00 7.00 0.00 0.00 13.00 0.00 0.00 -12.00 0.00 0.00 -41.00 0.00 0.00 -41.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 4.00 0.00 0.00 -167.00 0.00 0.00 -33.00 0.00 0.00 13.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -186.00 0.00 0.00 12.00 0.00 0.00 9.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 9.00 0.00 0.00 -196.00 0.00 0.00 -36.00 0.00 0.00 2.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 -178.00 0.00 0.00 -14.00 0.00 0.00 -5.00 0.00 0.00 -33.00 0.00 0.00 0.00 0.00 

0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -10.00 0.00 0.00 -8.00 0.00 0.00 0.00 0.00 
0.00 0.00 0.00 0.00 0.00 0.00 7.00 0.00 0.00 12.00 0.00 0.00 -36.00 0.00 0.00 -37.00 0.00 0.00 0.00 0.00 
-12.00 1.00 0.00 -12.00 0.00 0.00 -192.00 0.00 0.00 -184.00 0.00 0.00 -9.00 0.00 0.00 -10.00 0.00 0.00 0.00 0.00 
-3.00 1.00 0.00 3.00 0.00 0.00 -31.00 0.00 0.00 -9.00 0.00 0.00 -34.00 0.00 0.00 -34.00 0.00 0.00 0.00 0.00 
-20.00 1.00 0.00 -20.00 0.00 0.00 -190.00 0.00 0.00 -170.00 0.00 0.00 -11.00 0.00 0.00 -7.00 0.00 0.00 0.00 0.00 

2.00 87.00 0.00 0.00 91.00 0.00 0.00 47.00 0.00 0.00 104.00 0.00 0.00 64.00 0.00 0.00 41.00 9.00 0.00 0.00 
2.00 2.00 0.00 0.00 2.00 0.00 0.00 -9.00 0.00 0.00 15.00 0.00 0.00 -16.00 0.00 0.00 -24.00 0.00 0.00 0.00 
-15.00 2.00 0.00 -20.00 2.00 0.00 -181.00 -9.00 0.00 -186.00 15.00 0.00 0.00 -16.00 0.00 0.00 -24.00 0.00 0.00 0.00 
2.00 -68.00 0.00 -2.00 -71.00 0.00 3.00 -96.00 0.00 9.00 -45.00 0.00 0.00 -59.00 -9.00 0.00 -18.00 0.00 0.00 0.00 

2.00 -3.00 0.00 -1.00 -1.00 0.00 -174.00 -1.00 0.00 -179.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -362.00 -1.00 0.00 -349.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -542.00 -1.00 0.00 -534.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -3.00 0.00 -1.00 -1.00 0.00 -722.00 -1.00 0.00 -714.00 3.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 

2.00 -2.00 0.00 -1.00 -1.00 0.00 -808.00 -55.00 -1.00 -808.00 56.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -2.00 0.00 -20.00 2.00 0.00 -913.00 16.00 -1.00 -878.00 -23.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 
2.00 -2.00 0.00 -1.00 -1.00 0.00 -799.00 -55.00 -1.00 -801.00 52.00 0.00 0.00 23.00 1.00 0.00 -18.00 0.00 0.00 0.00 

4.00 0.00 -1.00 12.00 0.00 0.00 -730.00 12.00 0.00 -733.00 -29.00 0.00 -39.00 0.00 0.00 -41.00 0.00 1.00 0.00 0.00 
-21.00 0.00 -1.00 -14.00 0.00 0.00 -917.00 12.00 0.00 -884.00 -29.00 0.00 -12.00 0.00 0.00 -15.00 0.00 1.00 0.00 0.00 
-3.00 0.00 -1.00 7.00 0.00 0.00 -751.00 12.00 0.00 -739.00 -29.00 0.00 -42.00 0.00 0.00 -40.00 0.00 1.00 0.00 0.00 
-10.00 0.00 -15.00 -8.00 2.00 -16.00 -828.00 -55.00 0.00 -784.00 -29.00 0.00 -21.00 0.00 -16.00 -17.00 0.00 -8.00 0.00 0.00 
-10.00 0.00 11.00 -8.00 2.00 14.00 -770.00 5.00 0.00 -798.00 53.00 0.00 -21.00 0.00 3.00 -17.00 0.00 15.00 0.00 0.00 
-10.00 0.00 2.00 -5.00 5.00 1.00 -768.00 5.00 0.00 -747.00 1.00 0.00 -21.00 0.00 -3.00 -13.00 0.00 4.00 0.00 0.00
```
