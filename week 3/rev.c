#include<stdio.h>

void main()
{
    int n;
    scanf("%d",&n);
    char a[n+10];
    scanf(" %[^\n]s",a);
    char vowels[n][2];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='a' || a[i]=='e'||a[i]=='o'||a[i]=='u'||a[i]=='i')
        {
            vowels[k][0]=a[i];
            vowels[k++][1]=i;
        }
    }
    for(int i=0;i<k/2;i++)
    {
        char p =vowels[i][0];
        char q = vowels[k-i-1][0];
        int x = vowels[i][1];
        int y = vowels[k-i-1][1];
        a[x]=q;
        a[y]=p;
    }
    printf("%s",a);
}