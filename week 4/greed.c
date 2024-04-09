#include<stdio.h>

void main()
{
    int m, k;
    scanf("%d %d",&m ,&k);
    char large[m+1];
    char small[m+1];
    for(int i=0;i<m;i++)
    {
        large[i]='0';
        small[i]='0';
    }
    large[m]='\0';
    small[m]='\0';
    if(m>1&&k==0)
    {
        printf("-1 -1 ");
        return;
    }
    else if(k>(m*9))
    {
        printf("-1 -1");
        return;
    }

    int kl=k, i=0;
    while(kl>=9)
    {
        large[i]=9+'0';
        kl-=9;
        i++;
    }
    if(kl>0)
    {
        large[i]=kl+'0';
        kl=0;
        i++;
    }
    while(i<m)
    {
        large[i]='0';
        i++;
    }
    int ks=k;
    i=m-1;
    while(ks>9)
    {
        small[i]=9+'0';
        ks-=9;
        i--;
    }

    if(i>=1)
    {
        small[i]=ks+'0'-1;
        ks=1;
        i--;
    }
    while(i>0)
    {
        small[i]='0';
        i--;
    }
    small[i]=ks+'0';
    printf("%s ",small);
    printf("%s",large);
}