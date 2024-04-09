#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int count[n+1];
    int index[n];
    int output[n];
    for(int i=0;i<n+1;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        index[i]=0;
        output[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    for(int i=1;i<n+1;i++)
    {
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--)
    {
        output[count[a[i]] -1]=a[i];
        index[count[a[i]]-- -1]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",output[i]);
    }
    printf("\n");
     for(int i=0;i<n;i++)
    {
        printf("%d ",index[i]);
    }
}