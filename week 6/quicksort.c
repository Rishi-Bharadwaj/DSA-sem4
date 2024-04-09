#include<stdio.h>
void swap(int arr[],int i,int j)
{
    int x=arr[i];
    arr[i]=arr[j];
    arr[j]=x;
}

void partition(int arr[], int low, int high)
{
    if(low>=high)
    return;
    int j=low;
    int i=low-1;
    while(j<high)
    {
        if(arr[j]<arr[high])
        {
            i++;
            swap(arr,i,j);
        }
        j++;
    }
    swap(arr,i+1,high);
    partition(arr,low,i);
    partition(arr,i+2,high);
}
void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    partition(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}