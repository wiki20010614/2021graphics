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
