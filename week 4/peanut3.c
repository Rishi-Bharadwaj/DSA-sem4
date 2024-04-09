#include<stdio.h>
int tc=0;
void greedy(int a[],int t[], int n, int k,int w);
int sum(int n, int a[],int t[])
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(a[i]*t[i]);
    }
    return ans;
}

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int t[n];
    for(int i=0;i<n;i++)
    {
        t[i]=0;
    }
    greedy(a,t,n,k,n-1);
    printf("%d",tc);
}

void greedy(int a[],int t[], int n, int k,int w)
{
    if(w>0)
    {
        for(int i=0;i<=25;i++)
        {
            for(int s=w-1;s>=0;s--)
            {
                t[s]=0;
            }
            if(sum(n,a,t)<=k)
            {
            t[w]=i;
            greedy(a,t,n,k,w-1);
            }
        }
    }
    if(w==0)
    {
        for(int i=0;i<=25;i++)
        {
            t[w]=i;
            if(sum(n,a,t)==k)
            {
                tc++;
            }
        }
    }
}