#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* previous;
};
typedef struct node node;

void insert(int data, node** tail,node** head)
{
    node *node_ptr=(node*)malloc(sizeof(node));
    node_ptr->data=data;
    node_ptr->next=NULL;
    if(*head==NULL)
    {
        *head=node_ptr;
    }
    if((*tail)!=NULL)
    {
        (*tail)->next=node_ptr;
    }
    node_ptr->previous=*tail;
    *tail=node_ptr;

}

void main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    node* head1 = NULL;
    node* head2= NULL;
    node* tail1 = NULL;
    node* tail2= NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        insert(a,&tail1,&head1);
    }
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        insert(a,&tail2,&head2);
    }
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* temp;
    int k=0;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->data < ptr2->data)
        {
            temp=ptr1->next;
            ptr1->next=ptr2;
            ptr1=temp;
        }
        else if(ptr1->data>ptr2->data )
        {
            temp=ptr2->next;
            ptr2->next=ptr1;
            ptr2=temp;
        }
        else if(ptr1->data==ptr2->data)
        {
            ptr1=ptr1->next;
        }

    }

    if(ptr1->data>ptr2->data)
    ptr2->next=ptr1;
    else 
    ptr1->next=ptr2;
    
    ptr1= head1->data<head2->data?head1:head2;
    while(ptr1!=NULL)
    {
       printf("%d ",ptr1->data);
       ptr1=ptr1->next;
    }
}