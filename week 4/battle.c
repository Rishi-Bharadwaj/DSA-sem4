#include<stdio.h>

void main()
{
    float n, a, b;
    scanf("%f %f %f",&n,&a,&b);
    float t=a/(b+1);
    int max=t;
    if (t>(int)(a/(b+1)))
    max=t+1;
    int kcount=(int)a%(int)(b+1);
    int ocount=b;
    if(kcount>0)
    {
        while(kcount>0)
    {
        for(int i=0;i<max;i++)
        {
            printf("K");
        }
        printf("O");
        kcount--;
        ocount--;
    }
    while(ocount>0)
    {
        for(int i=0;i<max-1;i++)
        {
            printf("K");
        }
        printf("O");
        ocount--;
    }
    for(int i=0;i<max-1;i++)
        {
            printf("K");
        }
    }
    else
    {
       while(ocount>0)
    {
        for(int i=0;i<max;i++)
        {
            printf("K");
        }
        printf("O");
        ocount--;
    }
    for(int i=0;i<max;i++)
        {
            printf("K");
        }
    }

}