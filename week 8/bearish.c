#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
char* subtract(char *a,char*b)
{
    int len_a=strlen(a);
    char* result=(char*)malloc((len_a+1)*sizeof(char));
    int len_b=strlen(b);
    int borrow=0;
    int j=len_b-1, i=len_a-1;
    while(j>=0)
    {
        int x =a[i]-48-(b[j]-48)+borrow;
        if(x<0)
        {
            x=x+10;
            borrow=-1;
        }
        else
        borrow=0;
        result[i]=x+48;
        j--;
        i--;
    }
    while(i>=0)
    {
        int x =a[i]-48+borrow;
        if(x<0)
        {
            x=x+10;
            borrow=-1;
        }
        else
        borrow=0;
        result[i]=x+48;
        i--;
    }
    while (result[0] == '0' && len_a > 1) {
        for (int m = 0; m < len_a; m++) {
            result[m] = result[m + 1];
        }
        len_a--;
    }
    result[len_a]='\0';
    return result;
}


void main()
{

    int n,k;
    scanf("%d %d",&n,&k);
    stack * a =(stack*)malloc(sizeof(stack));
    stack * b =(stack*)malloc(sizeof(stack));
    a->top=-1;
    b->top=-1;
    char array[n];
    scanf("%s",&array);

    for(int i=n-1;i>=0;i--)
    {
        push(a,array[i]-'0');
    }
    int count=k;
    push(b,pop(a));
    for(int i=0;i<n-1;i++)
    {
        if(count==0)
        break;
        int x = pop(a);
        while(x<peak(b)&&b->top!=-1 && count>0)
        {
            pop(b);
            count--;
        }
        if(x!=0 || b->top!=-1)
        push(b,x);
    }
    while(count>0 && b->top!=-1)
    {
        pop(b);
        count--;
    }

    while(b->top!=-1)
    {
        push(a,pop(b));
    }

    char min[n];
    int i=0;
    while(a->top!=-1)
    {
        min[i++]=pop(a)+'0';
    }
    min[i]='\0';
    char* ans = subtract(array,min);
    printf("%s",ans);
}
