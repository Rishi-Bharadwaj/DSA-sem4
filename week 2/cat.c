#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[n][n];
    int b=1;
    int top=0,bottom=n-1,right=n-1,left=0;
    while(b<=n*n)
    {
        for(int i=left;i<=right;i++)
        {
            a[top][i]=b++;
        }
        top++;
        for(int i=top;i<=bottom;i++)
        {
            a[i][right]=b++;
        }
        right--;
        for(int i=right;i>=left;i--)
        {
            a[bottom][i]=b++;
        }
        bottom--;
        for(int i=bottom;i>=top;i--)
        {
            a[i][left]=b++;
        }
        left++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}