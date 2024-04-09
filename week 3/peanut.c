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
    int nom=0,psy=0;
    int max=0;
    int left=0, right=n-1;
    while(left<=right)
    {
        if(nom==psy)
        {
            if(nom>max)
            max=nom;
            nom+=a[left++];
        }
        else if (nom<psy)
        {
             nom+=a[left++];
        }
        else if (nom>psy)
        {
            psy+=a[right--];
        }
    }
    if(nom==psy)
        {
            if(nom>max)
            max=nom;
        }
    printf("%d",max);
}