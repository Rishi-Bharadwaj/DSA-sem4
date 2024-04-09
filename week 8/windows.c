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

    int n,k;
    scanf("%d %d",&n,&k);
    stack * a =(stack*)malloc(sizeof(stack));
    stack * b =(stack*)malloc(sizeof(stack));
    a->top=-1;
    b->top=-1;
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        push(a,t);
    }
    for(int i=0;i<n;i++)
    {
        int t=pop(a);
        push(b,t);
    }
    for(int i=0;i<n-k+1;i++)
    {
        int largest=pop(b);
        for(int i=0;i<k-1;i++)
        {
            int m= pop(b);
            if(m>largest)
            largest =m;
            push(a,m);
        }
        for(int i=0;i<k-1;i++)
        {
            push(b,pop(a));
        }
        printf("%d ",largest);
    }
}
