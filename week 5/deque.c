#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

void insert_back(int data, node **head,node **tail)
{
    node* new= (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if(*head==NULL)
    (*head)=new;
    if((*tail)!=NULL)
    {
        (*tail)->next=new;
        new->prev=(*tail);
    }
    (*tail)=new;
}
void insert_front(int data, node **head,node **tail)
{
    node* new= (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if((*head)!=NULL)
    {
        new->next=(*head);
        (*head)->prev=new;
    }
    if((*tail)==NULL)
    (*tail)=new;
    (*head)=new;
}
void delete_front(node** head,node**tail)
{
    if((*head)==NULL)
    return;
    if((*head)->next==NULL)
    {
        (*head)=NULL;
        (*tail)=NULL;
        return;
    }
    
    (*head)=(*head)->next;
    (*head)->prev=NULL;
}

void delete_back(node** head,node** tail)
{
    if((*tail)==NULL)
    return;
    if((*tail)->prev==NULL)
    {
        //printf("in loop\n");
        (*tail)=NULL;
        (*head)=NULL;
        return;
    }
    
    (*tail)=(*tail)->prev;
    (*tail)->next=NULL;
}
void print_forward(node** head)
{
    if((*head)==NULL)
    {
        printf("-1");
        return;
    }
    node* ptr=(*head);
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}
void print_backward(node** tail)
{
    if((*tail)==NULL)
    {
        printf("-1");
        return;
    }
    node* ptr=(*tail);
    while(ptr->prev!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->prev;
    }
    printf("%d",ptr->data);
}

void main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    node* head=NULL;
    node* tail=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        insert_back(a,&head,&tail);
    }

    for(int i=0;i<q;i++)
    {
        int r;
        scanf("%d",&r);
        if(r==1)
        {
            int s;
            scanf("%d",&s);
            insert_front(s, &head,&tail);
        }
        if(r==2)
        {
            int s;
            scanf("%d",&s);
            insert_back(s, &head,&tail);
        }
        if(r==3)
        {
            delete_front(&head,&tail);
        }
        if(r==4)
        {
            delete_back(&head,&tail);
        }
        if(r==5)
        {
            print_forward(&head);
        }
        if(r==6)
        {
            print_backward(&tail);
        }
        if(i!=q-1 && (r==5 || r==6))
        printf("\n");
    }
}