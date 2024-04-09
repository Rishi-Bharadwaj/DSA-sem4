#include<stdio.h>

void main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n];
    int b[m];
    int ans[n+m];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    int k=0;
    int p=0,q=0;
    while(k<n+m )
    {
        if(a[p]>b[q] && p<n && q<m)
        {
            ans[k++]=b[q++];
        }
        else if(a[p]<=b[q] && p<n && q<m)
        {
            ans[k++]=a[p++];
        }
        else if(p==n)
        {
            ans[k++]=b[q++];
        }
        else if(q==m)
        {
            ans[k++]=a[p++];
        }
    }
    for(int i=0;i<m+n;i++)
    {
        printf("%d ",ans[i]);
    }
}