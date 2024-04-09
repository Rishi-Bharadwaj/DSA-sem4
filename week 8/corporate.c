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


void main()
{
    int n;
    scanf("%d",&n);
    stack * a =(stack*)malloc(sizeof(stack));
    stack * b =(stack*)malloc(sizeof(stack));
    stack * c =(stack*)malloc(sizeof(stack));
    stack * d =(stack*)malloc(sizeof(stack));
    a->top=-1;
    b->top=-1;
    c->top=-1;
    d->top=-1;
    int array[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        push(a,array[i]);
    }
    ;
    int max_area=0;
    for(int i=0;i<n;i++)
    {
        int area=0,count=1;
        int current=pop(a);
        while(peak(a)>=current)
        {
                push(c,pop(a));
                count++;
        }
        while(peak(b)>=current)
        {
                push(d,pop(b));
                count++;
        }
        area=count*current;
        if(area>max_area)
        max_area=area;
        while(peak(c)!=-1)
        push(a,pop(c));
        while(peak(d)!=-1)
        push(b,pop(d));
        push(b,current);
    }

    printf("%d",max_area);
}
