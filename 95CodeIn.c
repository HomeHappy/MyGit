#include <stdio.h>
#include <stdlib.h>
int fun1(int a);//将十进制数转化为二进制数
int fun2(int b);//将二进制数转化为十进制数
int fun3(int b, int c);//二进制数b中位于第c位的数字
//95:10010101

int main()
{
    FILE *fp;
    char ch;
    int in10, in2, num2;
    int num[10000];
    int j=0;
    if((fp=fopen("G:\\ASCII.txt","r")) == NULL)//判断文件是否为空文件
    {
        printf("Error!\n");
        exit(0);
    }
    while((ch=fgetc(fp)) != EOF)//依次读出文件中的所有字符
    {
        int m=1;
        int k;
        num2=0;
        in10=(int)ch;//将字符转化为十进制数
        in2=fun1(in10);//将字符表示的十进制数转化为二进制数

        for(k=0; k<8; k++)//将二进制数进行异或加密,从低位开始
        {
            num2+=(fun3(in2, k+1)^fun3(10010101, k+1))*m;
            m*=10;
        }
        num[j]=num2;//将加密后的二进制数存入数组中
        j++;
    }
    fclose(fp);
    if((fp=fopen("G:\\ASCII2.txt","w"))==NULL)
    {
        printf("Error!\n");
        exit(0);
    }
    j=0;
    while(num[j]!='\0')
    {
        fprintf(fp, "%d", num[j]);
        j++;
    }
    fclose(fp);
    return 0;
}

int fun1(int a)
{
    int bin=0;
    int m,p=1;
    for(m=1;a>=p;m*=10)
    {
        bin+=((a%(p*2))/p)*m;
        p*=2;
    }
    return bin;
}

int fun2(int b)
{
    int num=0;
    int k,p=1;
    for(k=1;b>=k;k*=10)
    {
        num+=((b%(k*10))/k)*p;
        p*=2;
    }
    return num;
}

int fun3(int b,int c)//87654321
{
    int m=1;
    int o,i;
    for(i=1;i<c;i++)
    {
        m*=10;
    }
    o=(b%(m*10))/m;
    return o;
}
