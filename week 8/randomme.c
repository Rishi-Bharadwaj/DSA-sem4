#include<stdlib.h>
#include<stdio.h>

void swap(int arr[], int a, int b)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

int partition(int arr[], int l, int h)
{
    int high=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<=high)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,h,i+1);
    return i+1;
}

int randomized(int arr[], int l, int h)
{
    int q= rand() %(h-l+1)+l;
    swap(arr,h,q);
    return partition(arr,l,h);
}

int select(int arr[], int l,int h, int i)
{
    if(l==h)
    return arr[l];
    int q= partition(arr,l,h);
    int k=q-l+1;
    if(i==k)
    return arr[q];

    if(i<k)
     return select(arr,l,q-1,i);
    else
    return select(arr,q+1,h,i-k);
}

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int x = select(arr,0,n-1,n+1-k);
    printf("%d",x);
}