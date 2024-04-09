#include<stdio.h>
int count=0;

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
        {count+=n1-i;
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

void sort(int arr[], int l, int h)
{
    if(h<=l)
    return;
    int m= (h+l)/2;
    sort(arr,l,m);
    sort(arr,m+1,h);
    merge(arr,l,m,h);
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
    sort(a,0,n-1);
    printf("%d",count);
}