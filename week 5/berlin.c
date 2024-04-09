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
node* throw(node *head_ptr,int k)
{
    node* ptr =(head_ptr);
    for(int i=1;i<k-1;i++)
    {
        ptr=ptr->next;
    }
    node * prev= ptr;
    //printf("%d ",prev->data);
    node* future =ptr->next->next;
    //printf("%d ",future->data);
    prev->next=future;
    return future;
}
void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    node* head=NULL;
    node* tail=NULL;
    for(int i=1;i<=n;i++)
    {
        insert(i,&head,&tail);
    }
    node * future=head;
    while(future->next!=future)
    {
        future=throw(future,k);
    }
    
printf("%d",future->data);
} 