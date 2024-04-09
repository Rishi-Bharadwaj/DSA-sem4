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
    (*tail)->next=new;
    (*tail)=new;
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
    node* ptr1= head;
    node* prev=NULL;
    node* future=NULL;

    prev=ptr1;
    ptr1=ptr1->next;
    prev->next=NULL;
    
    while(ptr1->next!=NULL)
    {
        future=ptr1->next;
        ptr1->next=prev;
        prev=ptr1;
        ptr1=future;
    }
    ptr1->next=prev;
    head=ptr1;
    while(ptr1->next!=NULL)
    {
        printf("%d ",ptr1->data);
        ptr1=ptr1->next;
    }
    printf("%d",ptr1->data);
}