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
    new->next=NULL;
    if(*head_ptr==NULL)
    (*head_ptr)=new;
    if((*tail)!=NULL)
    {
        (*tail)->next=new;
    }
    (*tail)=new;
}
void clear(node *head_ptr)
{
    node* ptr =head_ptr;
    node* prev;
    if(ptr->next==NULL)
    return;
    node* future=ptr->next;
    while(future->next!=NULL)
    {
        if(ptr->data==future->data)
        {
            prev=ptr;
            ptr=future;
            future=future->next;
            prev->next=future;
        }
        else
        {
            prev=ptr;
            ptr=future;
            future=future->next;
        }
    }
    if(ptr->data==future->data)
    {
        ptr->next=NULL;
    }
}
void main()
{
    int n;
    scanf("%d",&n);
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        insert(a,&head,&tail);
    }
    for(int i=0;i<n;i++)
    clear(head);

    node* ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}