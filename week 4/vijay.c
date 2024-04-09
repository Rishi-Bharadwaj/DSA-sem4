#include<stdio.h>

void main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    char b[n][m];
    for(int i=0;i<n;i++)
    {
        scanf("%s",b[i]);
    }

    for(int k=0;k<n;k++)
    {
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                if(b[i][j]=='*')
                {
                    if(b[i+1][j]=='.')
                    {
                        b[i+1][j]='*';
                        b[i][j]='.';
                    }
                }
            }
        }
    }
    printf("\n\n\n\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%c",b[i][j]);
        }
        printf("\n");
    }
}