#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int profit=0,max_prof=0;
    int price=a[0];
    for(int i=1;i<n;i++)
    {
        profit=a[i]-price;
        if(profit>max_prof)
        {
            max_prof=profit;
        }
        if(a[i]<price)
        {
            price=a[i];
        }
        
    }
    printf("%d",max_prof);
}