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

    a->top=-1;
    b->top=-1;

    int array[n];
    int large[n];
    int small[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(int i=n-1;i>=0;i--)
    {
        push(a,array[i]);
    }

    for(int i=0;i<n;i++)
    {
        int larger=1,smaller=1;

        int l_found=0,s_found=0;

        int current=pop(a);
        while(a->top!=-1)
        {
            int x = pop(a);
            if(x>current && l_found==0)
            {
                l_found=1;
            }
            else if(x<current && s_found==0)
            {
                s_found=1;
            }
            if(!l_found)
            larger++;
            if(!s_found)
            smaller++;
            push(b,x);
        }
        if(l_found==1)
        large[i]=larger;
        else
        large[i]=0;
        if(s_found==1)
        small[i]=smaller;
        else
        small[i]=0;

        while(b->top!=-1)
        push(a,pop(b));
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",large[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",small[i]);
    }
}
