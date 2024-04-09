#include<stdio.h>
int dist(int a,int x)
{
    int ans= a>x?a-x:x-a;
    return ans;
}
void heapify(int arr[], int n, int i,int x)
{
    int left=2*i+1;
    int right =2*i+2;
    int max = i;
    if(dist(arr[left],x) > dist(arr[max],x) && left<n)
    {
        max=left;
    }
    if(dist(arr[right],x) > dist(arr[max],x) && right<n)
    {
        max=right;
    }
    if(max!=i)
    {
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
        heapify(arr,n,max,x);
    }
}

void main()
{
    int n,k,x;
    scanf("%d %d %d",&n,&k,&x);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int heap[k];
    int distance[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=dist(a[i],x);
    }
    for(int i=0;i<k;i++)
    heap[i]=a[i];
    for(int i=k/2-1;i>=0;i--)
    {
        heapify(heap,k,i,x);
    }

    for(int i=k;i<n;i++)
    {
        if(dist(a[i],x) < dist(heap[0],x))
        {
            heap[0]=a[i];
            heapify(heap,k,0,x);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            if(a[i]==heap[j])
            {
                printf("%d ",a[i]);
                for(int l=j;l<k-1;l++)
                {
                    heap[l]=heap[l+1];
                }
                k--;
            }
            
        }
    }
}