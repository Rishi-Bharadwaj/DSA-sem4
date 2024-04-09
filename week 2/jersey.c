#include<stdio.h>

void main()
{
    int p;
    scanf("%d",&p);
    int n=p-1;
    int a[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int ans=-1;
    int  beg=0, end= n-1, mid=(beg+end)/2,l =(end-beg)/2;
    while(l!=0){
        if(a[mid]==7)
        {
            ans=mid;
            break;
        }
        else if (a[mid]>p-7+mid)
        {
            beg=mid+1;
            mid=(beg+end)/2;
            l =(end-beg)/2;
        }
        
        else if(a[mid]<=p-7+mid)
        {
            end=mid-1;
            mid=(beg+end)/2;
            l =(end-beg)/2;
        }
        if(a[mid]==7)
        {
            ans=mid;
            break;
        }
    }
    printf("%d",ans);
}