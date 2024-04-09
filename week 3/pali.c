#include<stdio.h>


void main()
{
    int n;
    scanf("%d",&n);
    char a[n];
    scanf("%s",a);
    int i;
    int max=1;
    int j;
    int r=0;
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if ((a[j]==a[i+n-1-j])&&j>r&&j!=i+n-1-j)
            {
                r=j;
            }
            else if(!(a[j]==a[i+n-1-j]))
            {
                r=-1;
            }
        }
        if(r-i+1>max)
        max=r-i+1;
    }
    printf("%d",max);
}