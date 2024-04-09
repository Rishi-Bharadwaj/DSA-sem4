#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    int a[2*n];
    for(int i=0;i<2*n;i+=2)
    {
        scanf("%d %d",&a[i],&a[i+1]);
    }
    for(int i=2;i<2*n;i+=2)
    {
        int j=i-2;
        int temp_s=a[i];
        int temp_end=a[i+1];
        while(temp_s<a[j]&&j>=0)
        {
            a[j+2]=a[j];
            a[j+3]=a[j+1];
            j-=2;
        }
        a[j+2]=temp_s;
        a[j+3]=temp_end;
    }

    for(int p=0;p<n;p++)
    {
        for(int i=0;i<2*n-2;i+=2)
        {
            int j=i+2;
            if(a[j]<=a[i+1])
            {
                int end=a[i+1]>a[j+1]?a[i+1]:a[j+1];
                for(int k=i+1;k<2*n-2;k++)
                {
                    a[k]=a[k+2];
                }
                a[i+1]=end;
                n=n-1;
                break;
            }
        }
    }
    for(int i=0;i<2*n;i+=2)
    {
        printf("%d %d\n",a[i],a[i+1]);
    }
}