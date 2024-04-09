#include<stdio.h>
int min=900000;
void greedy(int w[],int sums[],int k,int r);

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int w[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    int sums[k];
    for(int i=0;i<k;i++)
    {
        sums[i]=0;
    }
    greedy(w,sums,k,n-1);
    printf("%d",min);
}

void greedy(int w[],int sums[],int k,int r)
{
    if(r>0)
    {
        for(int i=0;i<k;i++)
        {
            sums[i]+=w[r];
            greedy(w,sums,k,r-1);
            sums[i]-=w[r];
        }
    }
    if(r==0)
    {
        for(int i=0;i<k;i++)
        {
            sums[i]+=w[r];
            int max=0;
            for(int j=0;j<k;j++)
            {
                if(sums[j]>max)
                {
                    max=sums[j];
                }
            }
            if(max<min)
            {
                min=max;
            }
            sums[i]-=w[r];
        }
    }
}