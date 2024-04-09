#include<stdio.h>
#include<math.h>

void swap(int arr[],int i,int j)
{
    int x=arr[i];
    arr[i]=arr[j];
    arr[j]=x;
}
void merge(int arr[], int l, int m, int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i]=arr[m+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            arr[k]=a1[i];
            i++;
        }
        else
        {
            arr[k]=a2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k++]=a1[i++];
    }
    while(j<n2)
    {
        arr[k++]=a2[j++];
    }
}
void merge_sort(int arr[], int l, int h)
{
    if(h<=l)
    return;
    int m= (h+l)/2;
    merge_sort(arr,l,m);
    merge_sort(arr,m+1,h);
    merge(arr,l,m,h);
}

void partition(int arr[], int l, int h,int depth)
{
    if(l>=h)
    return;
    if(depth==0)
    {
        merge_sort(arr,l,h);
    }
    else
    {
        int j=l;
        int i=l-1;
        while(j<h)
        {
            if(arr[j]<arr[h])
            {
                i++;
                swap(arr,i,j);
            }
            j++;
        }
        swap(arr,i+1,h);
        depth--;
        partition(arr,l,i,depth);
        partition(arr,i+2,h,depth);
    }
    
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
    int depth=ciel(2*log2(n));
    printf("%d\n",depth);
    partition(a,0,n-1,depth);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}