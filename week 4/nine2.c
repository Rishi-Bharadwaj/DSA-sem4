#include<stdio.h>

int count=0;

void check(int n, int k,long long  int l, long long int r,char a[n],int w);

long long int convert(char a[], int n)
{
    long long int counter=1;
    long long int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        long long int c= a[i]-'0';
        c=c*counter;
        ans+=c;
        counter*=10;
    }
    return ans;
}

int sum(char a[], int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]!='?')
        {
        int c = a[i]-'0';
        ans+=c;
    }}
    return ans;
}


void main()
{
    long long int n,k,l,r;
    scanf("%lld %lld %lld %lld",&n, &k, &l, &r);
    char a[n];
    scanf("%s",&a);

    check(n,k,l,r,a,n-1);
    printf("%d",count);

}

void check(int n, int k,long long  int l, long long int r,char a[n],int w)
{
    if(w>0 && a[w]!='?')
    {
        check(n,k,l,r,a,w-1);
        printf("%s\n",a);
    }
    else
    {
        if(w>0)
    {
        for(int i='0';i<='9';i++)
        {
            a[w]=i;
            check(n,k,l,r,a,w-1);
            printf("%s\n",a);
        }
    }
    }
    if(w==0)
    {
        if(a[w]=='?')
        {
            for(int i='0';i<='9';i++)
            {
                a[w]=i;
                printf("%s\n",a);
                if((sum(a,n))==k)
                {
                    if(convert(a,n)>=l && convert(a,n)<=r)
                    count++;
                }
            }
        }
        else
        {
            if((sum(a,n))==k)
                {
                    if(convert(a,n)>=l && convert(a,n)<=r)
                    count++;
                }
        }
    }
}