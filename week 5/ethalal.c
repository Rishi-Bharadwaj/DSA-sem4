#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
typedef struct node node;

void insert(int data, node **head_ptr)
{
    node* new= (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    if(*head_ptr!=NULL)
    new->next=(*head_ptr);
    (*head_ptr)=new;
}
void main()
{
    int n;
    scanf("%d",&n);
    node* head=NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        insert(a,&head);
    }
    node* ptr= head;
    while(ptr->next!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}