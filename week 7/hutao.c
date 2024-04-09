#include<stdio.h>

void heapify(int arr[], int n, int i)
{
    int left=2*i+1;
    int right =2*i+2;
    int min = i;
    if(arr[left]<arr[min] && left<n)
    {
        min=left;
    }
    if(arr[right] < arr[min] && right<n)
    {
        min=right;
    }
    if(min!=i)
    {
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
        heapify(arr,n,min);
    }
}
int goodness(int arr[],int n,int k)
{
    int heap[k];
    for(int i=0;i<k;i++)
    heap[i]=arr[i];
    for(int i=k/2-1;i>=0;i--)
    heapify(heap,k,i);
    for(int i=k;i<n;i++)
    {
        if(arr[i]>heap[0])
        {
            heap[0]=arr[i];
            heapify(heap,k,0);
        }
    }
    int ans=0;
    for(int i=0;i<k;i++)
    ans+=heap[i];
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
    
    for(int i=0;i<n;i++)
    {
        int b;
        scanf("%d",&b);
        a[i]+=b;
    }

    int max=0;
    for(int i=1;i<=k;i++)
    {
        int s= goodness(a,n,i);
        if(s>max)
        max=s;
    }
    printf("%d",max);
    
}