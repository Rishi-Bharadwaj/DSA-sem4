#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* subtract(char *a,char*b);

void main()
{
    char a[100000];
    char b[100000];

    scanf("%s",a);
    scanf("%s",b);
    int len=strlen(a);
    char * ans=subtract(a,b);
    printf("%s",ans);
}

char* subtract(char *a,char*b)
{
    int len_a=strlen(a);
    char* result=(char*)malloc(len_a+1*sizeof(char));
    int len_b=strlen(b);
    int borrow=0;
    int j=len_b-1, i=len_a-1;
    while(j>=0)
    {
        int x =a[i]-48-(b[j]-48)+borrow;
        if(x<0)
        {
            x=x+10;
            borrow=-1;
        }
        else
        borrow=0;
        result[i]=x+48;
        j--;
        i--;
    }
    while(i>=0)
    {
        int x =a[i]-48+borrow;
        if(x<0)
        {
            x=x+10;
            borrow=-1;
        }
        else
        borrow=0;
        result[i]=x+48;
        i--;
    }
    while (result[0] == '0' && len_a > 1) {
        for (int m = 0; m < len_a; m++) {
            result[m] = result[m + 1];
        }
        len_a--;
    }
    result[len_a]='\0';
    return result;
}