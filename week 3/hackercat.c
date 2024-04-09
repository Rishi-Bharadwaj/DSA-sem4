#include<stdio.h>

long long int power(long long a, long long b) {
    long long int result = 1;
    while (b > 0) {
        if ( b&1 ) {
            result = (result * a)%1000000007;
        }
        a = (a * a)%1000000007;
        b /= 2;
    }
    return result;
}

void main()
{
    int n;
    scanf("%d",&n);
    long long int a[n];
    long long int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
    }
    long long int result=1;
    for(int i=0;i<n;i++)
    {
        result=(result*power(a[i],b[i]));
        result=result%1000000007;
    }
    printf("%lld",result);
}