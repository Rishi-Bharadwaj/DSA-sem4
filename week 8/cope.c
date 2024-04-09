#include<stdio.h>

struct node
{
    int time;
    int data;
};
typedef struct node node;

min_heapify(node a[],int n, int i)
{
    int left =2*i;
    int right =2*i+1;
    int first =i;

    if(a[left].time <a[first].time && left<n)
    first=left;
    if(a[right].time <a[first].time && right<n)
    first=right;

    if(i!=first)
    {
        int temp_t=a[first].time;
        int temp_d=a[first].data;
        a[first].time=a[i].time;
        a[first].data=a[i].data;
        a[i].time=temp_t;
        a[i].data=temp_d;
        min_heapify(a,n,first);
    }
}
max_heapify(node a[],int n, int i)
{
    int left =2*i;
    int right =2*i+1;
    int last =i;

    if(a[left].time >a[last].time && left<n)
    last=left;
    if(a[right].time >a[last].time && right<n)
    last=right;

    if(i!=last)
    {
        int temp_t=a[last].time;
        int temp_d=a[last].data;
        a[last].time=a[i].time;
        a[last].data=a[i].data;
        a[i].time=temp_t;
        a[i].data=temp_d;
        max_heapify(a,n,last);
    }
}

void main()
{
    int q;
    scanf("%d",&q);
    node queue[q];


}