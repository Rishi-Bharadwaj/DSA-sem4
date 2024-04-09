#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* add(char *a,char*b);

void main()
{
    char a[100000];
    char b[100000];

    scanf("%s",a);
    scanf("%s",b);
    int len=strlen(a);
    char * ans=add(a,b);
    printf("%s",ans);
}

char* add(char* a, char* b)
{
    char *sum=(char*)malloc(1001*sizeof(char));
    int len_a=strlen(a);
    int len_b=strlen(b);
    int carry =0;
    int i=len_a-1;
    int j=len_b-1;
        while(j>=0)
        {
            int x =a[i]-48+b[j]-48+carry;
            x=x%10;
            carry=x/10;
            sum[i]=x+48;
            j--;
            i--;
        }
        while(i>=0)
        {
            int x =a[i]-48+carry;
            x=x%10;
            carry=x/10;
            sum[i]=x+48;
            i--;
        }

    if(carry==1)
    {
        for(int i=len_a-1;i>=0;i--)
        {
            sum[i+1]=sum[i];
        }
        sum[0]=1+48;
        sum[len_a+1]='\0';
    }
    else
    sum[len_a]='\0';
    return sum;
}