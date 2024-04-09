#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int sum=0,max=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>max)
            max=sum;
        if(sum<0)
        {
            sum=0;
        }
    }
    printf("%d",max);
}