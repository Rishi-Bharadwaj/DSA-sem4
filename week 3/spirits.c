#include<stdio.h>

void main()
{
    int n, k, x;
    scanf("%d %d %d",&n,&k,&x);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int count=0;
    for(int i=0;i<=n-k;i++)
    {
        int sum=0;
        for(int j=i;j<k+i;j++)
        {
            sum+=a[j];
        }
        sum=sum/k;
        if(sum>=x)
        {
            count++;
        }
    }
    printf("%d",count);
    
}