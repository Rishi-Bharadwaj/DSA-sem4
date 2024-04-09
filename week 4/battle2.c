#include<stdio.h>

void main()
{
    float n, a, b;
    scanf("%f %f %f",&n,&a,&b);
    float t=a/(b+1);
    int norm=t;
    int kcount=(int)a%(int)(b+1);
    int ocount=b;
    while(kcount>0)
    {
        for(int i=0;i<=norm;i++)
        {
            printf("K");
        }
        printf("O");
        kcount--;
        ocount--;
    }
    while(ocount>0)
    {
        for(int i=0;i<norm;i++)
        {
            printf("K");
        }
        printf("O");
        ocount--;
    }
    for(int i=0;i<norm;i++)
        {
            printf("K");
        }
}