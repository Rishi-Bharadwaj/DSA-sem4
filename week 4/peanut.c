#include<stdio.h>
int tc=0;
void greedy(int a[],int t[], int n, int k,int w,int table[]);
int sum(int n, int a[],int t[])
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=(a[i]*t[i]);
    }
    return ans;
}

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int t[n];
    for(int i=0;i<n;i++)
    {
        t[i]=0;
    }
    int table[n*1000];
    for(int i=0;i<n*1000;i++)
    {
        table[i]=0;
    }
    greedy(a,t,n,k,n-1,table);
    printf("%d",tc);
}

void greedy(int a[],int t[], int n, int k,int w,int table[])
{
    if(w>0)
    {
        for(int i=0;i<=25;i++)
        {
            t[w]=i;
            // if(sum(n,a,t)<=k)
            // {
            //     for(int p=0;p<n;p++)
            //     {
            //         printf("%d",t[p]);
            //     }
            //     printf("\n");
                greedy(a,t,n,k,w-1,table);
            // }
        }
    }
    if(w==0)
    {
        for(int i=0;i<=25;i++)
        {
            t[w]=i;
            
            if(sum(n,a,t)==k)
            {
                // for(int p=0;p<n;p++)
                // {
                //     printf("%d",t[p]);
                // }
                // printf("\n");
                // int flag1=0;
                // for(int ii=0;ii<tc;ii=ii*n)
                // {
                //     for(int j=ii;j<ii+n;j++)
                //     {
                //         if(t[j-ii]!=table[j])
                //         {
                //             break;
                //         }
                //         flag1=1;
                //     }
                // }
                // if(flag1==1)
                // break;
                // else 
                // {
                //     for(int j=tc*n;j<tc+n;j++)
                //     {
                //         table[j]=t[j-tc*n];
                //     }
                //     tc++;
                // }
                tc++;
            }
            t[w]=0;
        }
    }
}