#include<stdio.h>

void main()
{
    int n, q;
    scanf("%d %d",&n,&q);
    int a[n];
    int que[2*q];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<2*q;i++)
    {
        scanf("%d",&que[i]);
    }
    for(int i=0;i<2*q;i=i+2)
    {
        int l= que[i],r=que[i+1];
        int sum=0;
        for(int j=l-1;j<=r-1;j++)
        {
            sum+=a[j];
        }
        printf("%d\n",sum);
    }
}