#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=-1;
    int  beg=0, end= n-1, mid=(beg+end)/2;
    while(1){
        if (a[mid+1]>a[mid])
        {
            beg=mid+1;
            mid=(beg+end)/2;
        }
        else if(a[mid]>a[mid+1]&&a[mid]>a[mid-1])
        {
            ans=mid+1;
            break;
        }
        else if(a[mid-1]>a[mid])
        {
            end=mid-1;
            mid=(beg+end)/2;
        }
    }
    printf("%d",ans);
}