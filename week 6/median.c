#include<stdio.h>
int max_length=0;
int min_length=0;

void swap(int *a, int*b)
{
    int y=*a;
    *a=*b;
    *b=y;
}

void max_heapify(int a[], int n, int i)
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
        max_heapify(a,n,largest);
    }
}
void min_heapify(int a[], int n, int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int min=i;
    if(left<n && a[left]<a[min])
    {
        min=left;
    }
    if(right<n && a[right]<a[min])
    {
        min=right;
    }
    if(min!=i)
    {
        swap(&a[min],&a[i]);
        min_heapify(a,n,min);
    }
}

int median(int old_med,int x, int* min_heap, int* max_heap)
{
         if(x>old_med)
         {
            min_heap[min_length++]=x;
            int p=min_length-1;
            while(min_heap[p]<min_heap[(p-1)/2])
            {
                swap(&min_heap[p],&min_heap[(p-1)/2]);
                p=(p-1)/2;
            }
         }
         else if(x<old_med)
         {
            max_heap[max_length++]=x;
            int p=max_length-1;
            while(max_heap[p]>max_heap[(p-1)/2])
            {
                swap(&max_heap[p],&max_heap[(p-1)/2]);
                p=(p-1)/2;
            }
         }
         if(min_length-max_length>1 || min_length-max_length<-1)
         {
            if(min_length>max_length)
            {
                max_heap[max_length++]=min_heap[0];
                int p=max_length-1;
                while(max_heap[p]>max_heap[(p-1)/2])
                {
                    swap(&max_heap[p],&max_heap[(p-1)/2]);
                    p=(p-1)/2;
                }
                swap(&min_heap[0], &min_heap[min_length-1]);
                min_length--;
                min_heapify(min_heap,min_length,0);
            }
            else
            {
                min_heap[min_length++]=max_heap[0];
                int p=min_length-1;
                while(min_heap[p]<min_heap[(p-1)/2])
                {
                    swap(&min_heap[p],&min_heap[(p-1)/2]);
                    p=(p-1)/2;
                }
                swap(&max_heap[0],&max_heap[max_length-1]);
                max_length--;
                max_heapify(max_heap,max_length,0);
            }
         }
    if(min_length>max_length)
    return min_heap[0];
    else return max_heap[0];        
}

void main()
{
    int q;
    scanf("%d",&q);
    int med=0;
    int min_heap[1000];
    int max_heap[1000];
    for(int i=0;i<q;i++)
    {
        int r;
        scanf("%d",&r);
        if(r==1)
        {
            scanf("%d",&r);
            med=median(med,r,&min_heap,&max_heap);
        }
        else if(r==2)
        printf("%d\n",med);
    }
}