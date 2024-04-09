#include<stdio.h>
#include<stdlib.h>

void heapify(int a[][2], int n, int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int min=i;
    if(left<n && a[left][0]<a[min][0])
    {
        min=left;
    }
    if(right<n && a[right][0]<a[min][0])
    {
        min=right;
    }
    if(min!=i)
    {
        int temp_value=a[i][0], temp_n0=a[i][1];
        a[i][0]=a[min][0];
        a[i][1]=a[min][1];
        a[min][0]=temp_value;
        a[min][1]=temp_n0;
        heapify(a,n,min);
    }
}

void merge(int arr[][1000], int k)
{
    int heap[k][2];
    for(int j=0;j<k;j++)
    {
        heap[j][0]=arr[j][0];
        heap[j][1]=j;
    }
    for(int i=k/2-1;i>=0;i--)
    {
        heapify(heap, k,i);
    }

    int counter[k];
    for(int i=0;i<k;i++)
    counter[i]=1;


    int* result = (int*)malloc(1000000*sizeof(int));
    int s=0;

    while(heap[0][0]!=10000)
    {
        result[s++]=heap[0][0];
        heap[0][0]=arr[heap[0][1]][counter[heap[0][1]]++];
        heapify(heap,k,0);
    }

    for(int i=0;i<s;i++)
    {
        printf("%d ",result[i]);
    }

}

void main()
{
    int k;
    scanf("%d",&k);
    int arr[k][1000];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<1000;j++)
        {
            arr[i][j]=10000;
        }
    }
    for(int i=0;i<k;i++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    merge(arr,k);
}