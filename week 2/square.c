#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    double prec =1.0e-7;
    double ans=-1;
    double  beg=0, end= n, mid=(beg+end)/2;
    while(end-beg>=prec){
        double square=mid*mid;
        if (square==n)
        {
            ans=mid;
            break;
        }
        else if(square>n)
        {
            end=mid;
            mid=(beg+end)/2;
        }
        else if(square<n)
        {
            beg=mid;
            mid=(beg+end)/2;
        }
        ans=mid;
    }
    int r=ans*1.0e6;
    ans=r/1.0e6;
    printf("%lf",ans);
}