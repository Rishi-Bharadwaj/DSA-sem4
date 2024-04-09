#include<stdio.h>

void merge(int a[], int l, int m, int h)
{
    int n1=m-l+1;
    int n2=h-m;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        a2[j]=a[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            a[k]=a1[i];
            i++;
        }
        else
        {
            a[k]=a2[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k++]=a1[i++];
    }
    while(j<n2)
    {
        a[k++]=a2[j++];
    }
}

void insertion(int a[], int l,int h)
{
    for(int i=l+1;i<=h;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(temp<a[j]&&j>=l)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

void sort(int a[],int l,int h,int k)
{
    if(h-l+1<=k)
    {
        insertion(a,l,h);
    }
    else
    {
        int m= (l+h)/2;
        sort(a,l,m,k);
        sort(a,m+1,h,k);
        merge(a,l,m,h);
    }
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
    sort(a,0,n-1,k);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
