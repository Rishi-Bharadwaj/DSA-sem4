#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* multiply(char* a, int n)
{
    char * temp=(char*)malloc(strlen(a)*sizeof(char)*n);
    for(int i=0;i<strlen(temp);i++)
    {
        temp[i]='\0';
    }
    for(int i=0;i<n;i++)
    {
        strcat(temp,a);
    }
    return temp;
}

void main()
{
    char a[1000];
    char b[1000];
    scanf("%s",a);
    scanf("%s",b);
    int len_a=strlen(a), len_b=strlen(b);
    int i=1;
    char * temp1=(char*)malloc(strlen(a)*sizeof(char)*len_a*len_b);
    char * temp2=(char*)malloc(strlen(a)*sizeof(char)*len_a*len_b);
    while(i*len_a<=len_a*len_b)
    {
        temp1=multiply(a,i);
        int j=1;
        while(j*len_b<=len_a*len_b)
        {
            temp2=multiply(b,j);
            if(strcmp(temp1,temp2)==0)
            {
                printf("%s",temp1);
                return;
            }
            j++;
        }
        i++;
    }
    printf("%d",-1);
}