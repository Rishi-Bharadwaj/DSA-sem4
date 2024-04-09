#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[n-1];
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans;
    int stolen=a[0]-1;
    if(stolen==7)
    {
        ans=-1;
    }
    else if(stolen<7)
    {
        ans=7-1-stolen;
    }
    else if (stolen>7)
    {
        ans=n-stolen+7-1;
    }
    printf("%d",ans);
}