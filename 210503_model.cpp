#include "glm.h"///�ϥ�glm.cpp���~��
GLMmodel* pmodel=NULL;///pmodel����

void drawmodel(void)
{///�ϥνd�ҵ{��
    if (!pmodel) {
        pmodel=glmReadOBJ("data/dolphins.obj");///dolphins�ҫ�
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
    drawmodel();///�ϥνd�ҵ{��
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
