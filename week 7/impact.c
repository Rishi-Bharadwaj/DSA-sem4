#include<stdio.h>

void heapify(int arr[], int n, int i)
{
    int left=2*i+1;
    int right =2*i+2;
    int max = i;
    if(arr[left]> arr[max] && left<n)
    {
        max=left;
    }
    if(arr[right] > arr[max] && right<n)
    {
        max=right;
    }
    if(max!=i)
    {
        int temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
        heapify(arr,n,max);
    }
}

void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    char a[n];
    for(int i=0;i<n;i++)
    {
        scanf(" %c",&a[i]);
    }

    int count[26];
    for(int i=0;i<26;i++)
    count[i]=0;
    for (int i=0;i<n;i++)
    {
        count[a[i]-'a']++;
    }
    int t=0;
    for(int i=0;i<26;i++)
    {
        if(count[i]!=0)
        t++;
    }
    int heap[t];
    int s=0;
    for(int i=0;i<26;i++)
    {
        if(count[i]!=0)
        heap[s++]=count[i];
    }
    for(int i=t/2-1;i>=0;i--)
    heapify(heap,t,i);
    for(int i=0;i<n-k;i++)
    {
        heap[0]--;
        heapify(heap,t,0);
    }

    int sum=0;

    for(int i=0;i<t;i++)
    {
        sum+=(heap[i]*heap[i]);
    }
    printf("%d",sum);
}