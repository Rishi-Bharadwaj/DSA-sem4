#include<stdio.h>
#include<stdlib.h>

void main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long int max=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>max)
        max=a[i];
    }
    int* dict = (int*)malloc((max+1)*sizeof(int));
    for(int i=0;i<=max;i++)
    {
        dict[i]=1;
    }
    dict[0]=dict[1]=0;
    for(long long int i=2;i*i<=max;i++)
    {
        if(dict[i]==1)
        {
            for(long long int j=i*i;j<=max;j+=i)
            {
                dict[j]=0;
            }
        }
    }
    long long int result=1;
    for(int i=0;i<n;i++)
    {
        if(dict[a[i]]==0)
        {
            result = (result * a[i]) % 1000000007;
        }
    }
    
    result=result%1000000007;
    if(result==1)
    result=-1;
    printf("%lld",result);
}