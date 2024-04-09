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
    {
        (*head)=new;
    }
    if((*tail)!=NULL)
    {
        (*tail)->next=new;
        new->prev=(*tail);
    }
    (*tail)=new;
    (*tail)->next=(*head);
    (*head)->prev=(*tail);
}
void insert_front(int data, node **head,node **tail,node**ptr)
{
    node* new= (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if((*tail)==NULL)
    (*tail)=new;
    if((*head)==NULL)
    {
        (*head)=new;
    }
    else
    {
        new->next=(*ptr)->next;
        (*ptr)->next=new;
        new->prev=(*ptr);
    }
    if((*ptr)==(*tail))
    {
        (*head)=new;
    }
    (*tail)->next=(*head);
    (*head)->prev=(*tail);
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

    node* ptr =head;

    for(int i=0;i<q;i++)
    {
        int r;
        scanf("%d",&r);
        if(r==1)
        {
            printf("%d",ptr->data);
            if(i!=q-1)
            printf("\n");
        }
        if(r==2)
        {
            int s;
            scanf("%d",&s);
            insert_front(s, &head,&tail,&ptr);
        }
        if(r==3)
        {
            int s;
            scanf("%d",&s);
            insert_back(s, &head,&tail);
        }
        if(r==4)
        {
            if(ptr->next!=NULL)
            ptr=ptr->next;
        }
        if(r==5)
        {
            if(ptr->prev!=NULL)
            ptr=ptr->prev;
        }
        if(r==6)
        {
            if(ptr->next!=NULL){

            node* temp=ptr;
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            ptr=ptr->next;
            temp->prev=NULL;
            temp->next=NULL;
            }
        }
        if(r==7)
        {
            node* temp=head;
            printf("%d ",temp->data);
            temp=temp->next;
            while(temp!=head)
            {
                printf("%d ",temp->data);
                temp=temp->next;
            }
            printf("\n");
        }
    }
}