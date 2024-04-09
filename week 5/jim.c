#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node node;

void insert(int data, node **head_ptr,node **tail)
{
    node* new= (node*)malloc(sizeof(node));
    new->data=data;
    if(*head_ptr==NULL)
    (*head_ptr)=new;
    if((*tail)!=NULL)
    {
        (*tail)->next=new;
    }
    (*tail)=new;
    new->next=(*head_ptr);
}
int rotate(node *head_ptr, int a, int b)
{
    node* ptr =head_ptr;
    node* dwight=head_ptr;
    node* jim=head_ptr;
    while(dwight->data!=a)
    dwight=dwight->next;
    while(jim->data!=b)
    jim=jim->next;
    while(dwight->data!=jim->data)
    {
        dwight=dwight->next->next;
        jim=jim->next;
    }
    return dwight->data;
    
}
void main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    node* head=NULL;
    node* tail=NULL;
    for(int i=1;i<=n;i++)
    {
        insert(i,&head,&tail);
    }

    printf("%d",rotate(head,a,b));
}