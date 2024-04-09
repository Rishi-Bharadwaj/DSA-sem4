#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void make_equal(char *a,char*b);

void main()
{
    char a[100000];
    char b[100000];

    scanf("%s",a);
    scanf("%s",b);
    int len=strlen(a);
    make_equal(a,b);
    printf("%s\n",a);
    printf("%s\n",b);
}




void make_equal(char*a,char*b)
{
    int len_a=strlen(a), len_b=strlen(b);
    if(len_a>len_b)
    {
        for(int i=0;i<len_a-len_b;i++)
        {
            for(int j=strlen(b)-1;j>=0;j--)
            {
                b[j+1]=b[j];
            }
            b[i]=48;
        }
        b[len_a]='\0';
    }
    else if (len_b>len_a)
    {
       for(int i=0;i<len_b-len_a;i++)
        {
            for(int j=strlen(a)-1;j>=0;j--)
            {
                a[j+1]=a[j];
            }
            a[i]=48;
        } 
        a[len_b]='\0';
    }
}