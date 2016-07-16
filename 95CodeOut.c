#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1;//读取加密二进制文件
    FILE *fp2;//写入解密文本文件
    char ch,right;
    int Fp1[8]={0,0,0,0,0,0,0,0};
    int Code[8]={1,0,0,1,0,1,0,1};
    int i,j,k,m,s;

    if((fp1=fopen("G:\\ASCII2.txt","r")) == NULL)
    {
        printf("Error!\n");
        exit(0);
    }
    if((fp2=fopen("G:\\ASCII3.txt","w")) == NULL)
    {
        printf("Error!\n");
        exit(0);
    }

    while((ch=fgetc(fp1)) != EOF)
    {
        Fp1[0]=(int)ch%2;
        for(i=1;i<8;i++)
        {
            ch=fgetc(fp1);
            Fp1[i]=(int)ch%2;
        }
        //每次读取八个数字到Fp1[]数组中,Fp[0]为最高位
        m=1;
        s=0;
        for(j=7;j>=0;j--)
        {
            k=Fp1[j]^Code[j];
            s+=m*k;
            m*=2;
        }
        //将加密的八位数字解密，并得到相应的十进制数
        right=(char)s;
        fprintf(fp2, "%c", right);
        printf("%c\n",right);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
