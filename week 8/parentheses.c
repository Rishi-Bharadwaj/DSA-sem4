#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack{
    int top;
    char arr[1000];
};
typedef struct stack stack;

int push(stack* s,char a)
{
    if(s->top==999)
    return 0;
    s->top++;
    s->arr[s->top]=a;
    return 1;
}

char pop(stack* s)
{
    if(s->top==-1)
    return 0;
    char x = s->arr[s->top];
    s->top--;
    return x;
}


void main()
{
    char s[1000];
    scanf("%s",&s);
    int n = strlen(s);
    stack* a = (stack *)malloc(sizeof(stack));
    a->top=-1;
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        push(a,s[i]);
        if(s[i]==')'||s[i]==']'||s[i]=='}')
        {
            char m = pop(a);
            if(s[i]==')'&& m!='(' )
            break;
            else if(s[i]==']' && m!='[')
            break;
            else if(s[i]=='}' && m!='{')
            break;
        }
        i++;
    }

    if(a->top==-1)
    printf("YES");
    else printf("NO");
}
