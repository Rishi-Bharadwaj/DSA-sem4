#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* karat(char *a, char*b);
char* add(char* a, char*b);
char* subtract(char *a,char*b);
void make_equal(char*a,char*b);

void main()
{
    char a[100000];
    char b[100000];

    scanf("%s",a);
    scanf("%s",b);
    int len=strlen(a);
    char * ans=karat(a,b);
    printf("%s",ans);
}


char* karat(char*x, char*y)
{
    make_equal(x,y);
    int n= strlen(x);
    char* ans= (char*)malloc(100000*sizeof(char));
    if(n==1)
    {
        int r=x[0]-48;
        int t=y[0]-48;
        r=r*t;
        sprintf(ans,"%d",r);
        return ans;
    }
    else
    {
        char* a= (char*)malloc(100000*sizeof(char));
        char* b= (char*)malloc(100000*sizeof(char));
        char* c= (char*)malloc(100000*sizeof(char));
        char* d= (char*)malloc(100000*sizeof(char));
        char* p= (char*)malloc(100000*sizeof(char));
        char* q= (char*)malloc(100000*sizeof(char));
        char* ac= (char*)malloc(100000*sizeof(char));
        char* bd= (char*)malloc(100000*sizeof(char));
        char* pq= (char*)malloc(100000*sizeof(char));
        char* adbc= (char*)malloc(100000*sizeof(char));
        for(int i=0;i<(n)/2;i++)
        {
            a[i]=x[i];
            c[i]=y[i];
        }
        for(int i=(n)/2;i<n;i++)
        {
            b[i-(n/2)]=x[i];
            d[i-(n/2)]=y[i];
        }
        a[n/2]='\0';b[(n+1)/2]='\0';c[n/2]='\0';d[(n+1)/2]='\0';
        p=add(a,b);
        q=add(c,d);
        ac=karat(a,c);
        bd=karat(b,d);
        pq=karat(p,q);
        adbc=subtract(pq,ac);
        adbc=subtract(adbc,bd);
        int len_ac=strlen(ac),len_adbc=strlen(adbc);
        int m=n%2==0?n/2:(n+1)/2;
        for(int i=len_ac;i<len_ac+(2*m);i++)
        {
            ac[i]=48;
        }
        ac[len_ac+2*m]='\0';
        for(int i=len_adbc;i<len_adbc+m;i++)
        {
            adbc[i]=48;
        }
        adbc[len_adbc+m]='\0';
        ans=add(ac,bd);
        ans=add(ans,adbc);
        int len_a=strlen(ans);
        while (ans[0] == '0' && len_a > 1) {
        for (int m = 0; m < len_a; m++) {
            ans[m] = ans[m + 1];
        }
        len_a--;
    }
    ans[len_a]='\0';
        return ans;
    }
}

char* add(char* a, char* b)
{
    char *sum=(char*)malloc(100000*sizeof(char));
    int len_a=strlen(a);
    int len_b=strlen(b);
    if(len_b>len_a)
    {
        sum=add(b,a);
        return sum;
    }
    else
    {
        char *sum=(char*)malloc(100000*sizeof(char));
        int len_a=strlen(a);
        int len_b=strlen(b);
        int carry =0;
        int i=len_a-1;
        int j=len_b-1;
            while(j>=0)
            {
                int x =a[i]-48+b[j]-48+carry;
                carry=x/10;
                x=x%10;
                sum[i]=x+48;
                j--;
                i--;
            }
            while(i>=0)
            {
                int x =a[i]-48+carry;
                carry=x/10;
                x=x%10;
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