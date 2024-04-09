#include<stdio.h>
int max=0;
void greedy(int time, int weight ,int a[], int t[],int r,int k);
void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    int t[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&t[i]);
    }
    greedy(0,0,a,t,n-1,k);
    printf("%d",max);
}

void greedy(int time, int weight ,int a[], int t[],int r,int k)
{
    if(r>0)
    {
        if(time+t[r]<=k)
        {
            weight+=a[r];
            time+=t[r];
            if(weight>max)
            max=weight;
            greedy(time,weight,a,t,r-1,k);
        }
        greedy(time,weight,a,t,r-1,k);
    }
    if(r==0)
    {
        if(time+t[r]<=k)
        {
            weight+=a[r];
            time+=t[r];
            if(weight>max)
            max=weight;
        }
    }
}