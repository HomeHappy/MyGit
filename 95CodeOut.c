#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1;//��ȡ���ܶ������ļ�
    FILE *fp2;//д������ı��ļ�
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
        //ÿ�ζ�ȡ�˸����ֵ�Fp1[]������,Fp[0]Ϊ���λ
        m=1;
        s=0;
        for(j=7;j>=0;j--)
        {
            k=Fp1[j]^Code[j];
            s+=m*k;
            m*=2;
        }
        //�����ܵİ�λ���ֽ��ܣ����õ���Ӧ��ʮ������
        right=(char)s;
        fprintf(fp2, "%c", right);
        printf("%c\n",right);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
