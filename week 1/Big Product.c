#include<stdio.h>
#include<stdlib.h>

char* multiply(char *a, char b,int n,int count);

char* add(char* a, char* b);
void main()
{
    char a[1000];
    char b[1000];
    char* result = (char*)malloc(10000*sizeof(char));
    result[0]=48;
    result[1]='\0';
    scanf("%s",&a);
    scanf("%s",&b);
    int i=0,len_a=0,len_b=0;
    while(a[i]!='\0')
    {
        len_a++;
        i++;
    }
    i=0;
    while(b[i]!='\0')
    {
        len_b++;
        i++;
    }
    int count=-1;
    for(int k=len_b-1;k>=0;k--)
    {
        char * temp = multiply(a,b[k],len_a,count);
        count++;
        result=add(temp,result);
    }
    printf("%s",result);

}

char* multiply(char *a, char b,int n,int count)
{
    char *product=(char *)malloc((n+2)*sizeof(char));
    int carry=0;
    int i=n-1;
    while(i>=0)
    {
        int x = (b-48)*(a[i]-48)+carry;
        carry=x/10;
        x=x%10;
        product[i+1]=x+48;
        i--;
    }
    if(carry>=1)
    {
        product[0]=carry+48;
        n=n+1;
    }
    
    else
    for(i=0;i<=n-1;i++)
    {
        product[i]=product[i+1];
    }

    for(int i=n;i<=count+n;i++)
    {
        product[i]=0+48;
    }
    product[count+n+1]='\0';
    return product;
}

char* add(char* a, char* b)
{
    char *sum=(char*)malloc(1001*sizeof(char));
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
    i=len_a>len_b?len_a-1:len_b-1;
    int j=len_a<=len_b?len_a-1:len_b-1;

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
    return sum;
}
