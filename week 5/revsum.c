#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* previous;
};
typedef struct node node;

void insert(int data, node** head)
{
    node *node_ptr=(node*)malloc(sizeof(node));
    node_ptr->data=data;
    node_ptr->next=*head;
    node_ptr->previous=NULL;
     if (*head != NULL) {
        (*head)->previous=node_ptr;
    }
    *head=node_ptr;
}

void main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    node* head1 = NULL;
    node* head2= NULL;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        insert(a,&head1);
    }
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        insert(a,&head2);
    }
    node* ptr1=head1;
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
    }
    node* ptr2=head2;
    while(ptr2->next!=NULL)
    {
        ptr2=ptr2->next;
    }
    int carry=0;
    int sum=0;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        sum=ptr1->data+ptr2->data+carry;
        carry=sum/10;
        sum=sum%10;
        ptr1=ptr1->previous;
        ptr2=ptr2->previous;
        printf("%d",sum);
    }

    while(ptr1!=NULL)
    {
        sum=ptr1->data+carry;
        carry=sum/10;
        sum=sum%10;
        ptr1=ptr1->previous;
        printf("%d",sum);
    }
    while(ptr2!=NULL)
    {
        sum=ptr2->data+carry;
        carry=sum/10;
        sum=sum%10;
        ptr2=ptr2->previous;
        printf("%d",sum);
    }
}