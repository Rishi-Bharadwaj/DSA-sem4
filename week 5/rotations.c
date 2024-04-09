#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

void insert(int data, node **head_ptr,node **tail)
{
    node* new= (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head_ptr==NULL)
    (*head_ptr)=new;
    if((*tail)!=NULL)
    {
        (*tail)->next=new;
        new->prev=(*tail);
    }
    (*tail)=new;
}
void rotate(node *head_ptr)
{
    node* ptr =head_ptr;
    int t= ptr->data;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    while(ptr->prev!=NULL)
    {
        int q=ptr->data;
        ptr->data=t;
        t=q;
        ptr=ptr->prev;
    }
    ptr->data=t;
    
}
void main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        insert(a,&head,&tail);
    }
    for(int i=0;i<k;i++)
    {
        rotate(head);
    }

    node* ptr=head;
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
    
}