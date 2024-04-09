#include<stdio.h>

void swap(int *a, int*b)
{
    int y=*a;
    *a=*b;
    *b=y;
}

void heapify(int a[], int n, int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n && a[left]>a[largest])
    {
        largest=left;
    }
    if(right<n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&a[largest],&a[i]);
        heapify(a,n,largest);
    }
}

void sum(int a[], int n, int k)
{
    for(int i=k/2-1;i>=0;i--)
    {
        heapify(a,k,i);
    }

    for(int i=k;i<n;i++)
    {
        if(a[i]<a[0])
        {
            a[0]=a[i];
            heapify(a,k,0);
        }
    }
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=a[i];
    }
    printf("%d",sum);
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
    sum(a,n,k);
}