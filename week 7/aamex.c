#include<stdio.h>


void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int count[n+1];
    for(int i=0;i<n+1;i++)
    {
        count[i]=0;
    }
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }
    int flag=0;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(count[i]==0 && count[j]==0)
            {
                if(i+j==k)
                flag=1;
            }
        }
    }
    if(flag==1)
    printf("yes");
    else
    printf("no");
}