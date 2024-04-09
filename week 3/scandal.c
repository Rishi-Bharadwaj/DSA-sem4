#include<stdio.h>

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int clients[60];

    int max=0;
    int size = sizeof(long long int)*8;

    for(int i=0;i<=n-k;i++)
    {
        for(int i=0;i<60;i++)
        {
            clients[i]=0;
        }
        int count=0;
        for(int j=i;j<k+i;j++)
        {
            long long int num= a[j];
            for(int r=0;r<60;r++)
            {
                int bit = (num>>r)&1;
                if(bit==1)
                {
                    clients[r]=1;
                }
            }
        }
        for(int i=0;i<60;i++)
        {
            if(clients[i]==1)
            {
                count++;
            }
        }
        if (count>max)
        max=count;
    }
    printf("%d",max);
}