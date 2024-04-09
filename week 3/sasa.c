#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    char a[n];
    scanf("%s",a);
    int dict[26];
    for(int i=0;i<26;i++)
    {
        dict[i]=-1;
    }
    int max=0;
    int start=0;
    for(int i=0;i<n;i++)
    {
        int r=a[i]-'a';
        if(dict[r]!=-1 && dict[r]>=start)
        {
            start=dict[r]+1;
        }
        dict[r]=i;
        int current=i-start+1;
        if(current>max)
        max=current;
    }
    printf("%d",max);
}