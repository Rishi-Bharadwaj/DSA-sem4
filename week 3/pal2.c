#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    char a[n];
    scanf("%s",a);
    int max=1;
    for(int i=0;i<n;i++)
    {
        int left=i,right=i;
        int j=i;
        int count=0;
        while(left>=0&&right<n)
        {
            if(a[left]==a[right])
            {
                count=right-left+1;
                if(count>max)
                max=count;
            }
            else
            break;
            left--;
            right++;
        }
    }
    printf("%d",max);
}
