#include <stdio.h>
int main(int argc,char** argv)
{
    /*FILE*fout=NULL;///�ɮ׫��� file output �ܼ�
    fout=fopen("�ɦW.txt","w+");///�}���ɮ�(�ɦW.txt,�Ҧ�write+)

    printf("Hello World\n");
    fprintf(fout,"Hello World\n");*/

    FILE*fin=NULL;
    fin=fopen("�ɦW.txt","r");///Ū���ɮ�(�ɦW.txt,�Ҧ�read)

    char line[1000];
    fscanf(fin,"%s",line);///Ū�J�r��
    printf("�{�bŪ�쪺�O:%s\n",line);///�L�X�r��
    fscanf(fin,"%s",line);///Ū�J�r��
    printf("�{�bŪ�쪺�O:%s\n",line);///�L�X�r��
}
