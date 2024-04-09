#include<stdio.h>
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
    return -1;
    int x = s->arr[s->top];
    s->top--;
    return x;
}

int peak(stack* s)
{
    if(s->top==-1)
    return -1;
    return s->arr[s->top];
}

int dif(int a, int b)
{
    int x  = a>b?a-b:b-a;
    return x;
}


void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
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

    int total_count=0;
    for(int i=0;i<n;i++)
    {
        int count=1;
        int current=pop(a);
        while(dif(peak(a),current)<=k && a->top!=-1)
        {
            count++;
            push(b,pop(a));
        }
        while(b->top!=-1)
        push(a,pop(b));
        total_count+=count;
    }

    printf("%d ",total_count);
}
