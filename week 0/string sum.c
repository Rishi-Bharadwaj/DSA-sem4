#include<stdio.h>

void main()
{
    char a [1000];
    char b [1000];
    scanf("%s",&a);
    scanf("%s",&b);
    int i=0;
    while(a[i]!='\0')
    {
        i++;
    }
    int len_a=i;
    i=0;
    while(b[i]!='\0')
    {
        i++;
    }
    int len_b=i;

    int carry =0;
    char sum[1001];
    int j=len_b-1;
    i=len_a-1;
        while(j>=0)
        {
            int x =a[i]-48+b[j]-48+carry;
            if(x>=10)
            {
                x=x-10;
                carry=1;
            }
            else
            carry=0;
            sum[i]=x+48;
            j--;
            i--;
        }
        while(i>=0)
        {
            int x =a[i]-48+carry;
            if(x>=10)
            {
                x=x-10;
                carry=1;
            }
            else
            carry=0;
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
    printf("%s",sum);
}