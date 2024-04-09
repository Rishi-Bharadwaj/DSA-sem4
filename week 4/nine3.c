#include<stdio.h>
#include<string.h>

int count=0;

void check(int n, int k,long long  int l, long long int r,char a[n],int x[],int w);

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
    int qs=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='?')
        qs++;
    }
    int x[qs];
    int w=qs-1;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]=='?')
        x[w--]=i;
    }
    check(n,k,l,r,a,x,qs-1);
    printf("%d",count);

}

void check(int n, int k,long long  int l, long long int r,char a[n],int x[],int w)
{
    if(w>0)
    {
        for(int i='0';i<='9';i++)
        {
            a[x[w]]=i;
            check(n,k,l,r,a,x,w-1);
        }
    }
    if(w==0)
    {
        for(int i='0';i<='9';i++)
        {
            a[x[w]]=i;
            if((sum(a,n))==k)
            {
                if(convert(a,n)>=l && convert(a,n)<=r)
                count++;
            }
        }
    }
}