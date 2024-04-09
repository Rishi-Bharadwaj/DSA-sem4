#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack{
    int top;
    int arr[1000];
};
typedef struct stack stack;

int push(stack* s,int a)
{
    if(s->top==999)
    return 0;
    s->top++;
    s->arr[s->top]=a;
    return 1;
}

int pop(stack* s)
{
    if(s->top==-1)
    return 0;
    int x = s->arr[s->top];
    s->top--;
    return x;
}

int peak(stack* s)
{
    return s->arr[s->top];
}


void main()
{

    int n;
    scanf("%d ",&n);
    stack * a =(stack*)malloc(sizeof(stack));
    stack * b =(stack*)malloc(sizeof(stack));
    a->top=-1;
    b->top=-1;
    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        push(a,array[i]);
    }
    long long int ans=0;
    int size=n;
    for(int i=0;i<n;i++)
    {
        int smallest= pop(a);
        size--;
        ans+=smallest;
        ans=ans%1000000007;
        for(int i=0;i<size;i++)
        {
            int m =pop(a);
            if(m<smallest)
            {
                smallest=m;
            }
            ans+=smallest;
            ans=ans%1000000007;
            push(b,m);
        }
        for(int i=0;i<size;i++)
        {
            push(a,pop(b));
        }
    }
    printf("%lld",ans);
}
