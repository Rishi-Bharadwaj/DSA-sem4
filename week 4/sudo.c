#include<stdio.h>
int solve(int b[9][9]);
int place(int b[9][9], int i, int j, int k)
{
    
    for(int r=0;r<9;r++)
    {
        if(b[r][j]==k || b[i][r]==k||b[i-(i%3)+r/3][j-j%3+r%3]==k)
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
     int b[9][9];
     for(int i=0;i<9;i++)
     {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&b[i][j]);
        }
     }
    int a= solve(b);
    printf("\n\n\n\n");
    for(int i=0;i<9;i++)
     {
        for(int j=0;j<8;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("%d",b[i][8]);
        printf("\n");
     }
}

int solve(int b[9][9])
{
    int flag=0;
    int i=0,j=0;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(b[i][j]==-1)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        break;
    }

     if(flag==0)
     {
        return 1;
     }

     for(int k=1;k<=9;k++)
     {
        if(place(b,i,j,k))
        {
            b[i][j]=k;
            if(solve(b))
            {
                return 1;
            }
        }
     }
     return 0;
}