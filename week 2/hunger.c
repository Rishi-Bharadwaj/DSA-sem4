#include<stdio.h>

void main()
{
    int n, x;
    scanf("%d %d",&n,&x);
    int a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=-1;
    int  beg=0, end= n-1, mid=(beg+end)/2;
    while(ans==-1){
        if (x<a[mid])
        {
            end=mid-1;
            mid=(beg+end)/2;
        }
        else if(x==a[mid])
        {
            ans=mid+1;
        }
        else if(x>a[mid])
        {
            beg=mid+1;
            mid=(beg+end)/2;
        }
    }
    printf("%d",ans);
}