#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    char a[n+1];
    scanf(" %[^\n]s",a);
    int start=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==' ')
        {
            int len= i-start;
            for(int j=start;j<start+len/2;j++)
            {
                char temp=a[j];
                a[j]=a[2*start+len-1-j];
                a[2*start+len-1-j]=temp;
            }
            start=i+1;
        }
    }
    int len= n-start;
    for(int j=start;j<start+len/2;j++)
        {
            char temp=a[j];
            a[j]=a[2*start+len-j-1];
            a[2*start+len-j-1]=temp;
        }
    printf("%s",a);
}