#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int l= n*n;
    int x;
    scanf("%d",&x);
    int a[l];
    for(int i=0;i<l;i++)
    {
        scanf("%d",&a[i]);
    }
    int beg=0,end=l-1,ans=-1;
    while(beg<=end)
    {
        int mid=(beg+end)/2;
        if(a[mid]==x)
        {
            ans=1;
            break;
        }
        else if(a[mid]>x)
        {
            end=mid-1;
        }
        else 
        {
            beg=mid+1;
        }
    }
    if(ans==1)
    printf("Yes");
    else 
    printf("NO");
}