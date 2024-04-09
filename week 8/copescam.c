#include<stdio.h>
#include<stdlib.h>

struct stack{
    int arr[100];
    int top;
};
typedef struct stack stack;

void min_heapify(int arr[], int n, int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(arr[left]<arr[largest] && left<n)
    largest=left;
    if(arr[right]<arr[largest] && right<n)
    largest=right;

    if(largest!=i)
    {
        int temp=largest;
        arr[largest]=arr[i];
        arr[i]=temp;
        min_heapify(arr,n,largest);
    }
}

void push(stack *s, int l)
{
    s->top++;
    s->arr[s->top]=l;
}

int pop(stack* s)
{
    return s->arr[s->top--];
}

void push_q(stack*s, int data)
{
    stack* b = (stack *)malloc(sizeof(stack));
    b->top=-1;
    while(s->top!=-1)
    {
        push(b,pop(s));
    }
    push(b,data);
    while(b->top!=-1)
    {
        push(s,pop(b));
    }
}
int pop_q(stack*s)
{
    stack* b = (stack *)malloc(sizeof(stack));
    b->top=-1;
    while(s->top!=-1)
    {
        push(b,pop(s));
    }
    int x= pop(b);
    while(b->top!=-1)
    {
        push(s,pop(b));
    }
    return x;
}

void main()
{
    int r;
    scanf("%d ",&r);

    stack* s = (stack *)malloc(sizeof(stack));
    stack* q = (stack *)malloc(sizeof(stack));
    s->top=-1;
    q->top=-1;
    
    int sum=0,num=0;

    for(int i=0;i<r;i++)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            int x;
            scanf("%d",&x);
            num++;
            sum+=x;
            push(s,x);
            push_q(q,x);
        }
        if(t==2)
        {
            pop(s);
            int x=pop_q(q);
            num--;
            sum-=x;
        }
        if(t==3)
        {
            int n=s->top+1;
            int heap[n];
            for(int i=0;i<n;i++)
            {
                heap[i]=s->arr[i];
            }
           
            for(int i=n/2-1;i>=0;i--)
            {
                min_heapify(heap,n,i);
            }
            printf("%d ",heap[0]);
            printf("%d",sum/num);
        }
    }
}