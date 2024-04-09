#include<stdio.h>
#include<string.h>


void radix(char a[][100], int n,int max)
{
    int count[16];
    
    char output[n][100];
    for(int k=1;k<=max;k++)
    {
        for(int i=0;i<16;i++)
        count[i]=0;
        for(int i=0;i<n;i++)
        {
            int j = strlen(a[i])-k;
            if(j>=0){
            if(a[i][j]>='0' && a[i][j]<='9')
            {
                count[a[i][j]-'0']++;
            }
            else
            {
                count[a[i][j]-'A'+10]++;
            }
            }
            else count[0]++;
        }

        for(int i=1;i<16;i++)
        {
            count[i]+=count[i-1];
        }

        for(int i=n-1;i>=0;i--)
        {
            int j = strlen(a[i])-k;
            if(j>=0)
            {
                if(a[i][j]>='0' && a[i][j]<='9')
                {
                    strcpy(output[count[a[i][j]-'0']-1],a[i]);
                    count[a[i][j]-'0']--;
                }
                else
                {
                    strcpy(output[count[a[i][j]-'A'+10] -1],a[i]);
                    count[a[i][j]-'A'+10]--;
                }
            }
            else
            {
                strcpy(output[count[0]-1],a[i]);
                count[0]--;
            }
        }
        for(int i=0;i<n;i++)
        strcpy(a[i],output[i]);
    }

    for(int i=0;i<n;i++)
    {
        printf("%s ",a[i]);
    }
    
}

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    char a[n][100];
    int s;
    for(int i=0;i<n;i++)
    {
        scanf("%s",&a[i]);
    }
    radix(a,n,k);
}