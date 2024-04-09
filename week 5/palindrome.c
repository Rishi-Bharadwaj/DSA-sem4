#include<stdio.h>
#include<stdlib.h>

struct node
{
    char data;
    struct node* next;
    struct node* prev;
};
typedef struct node node;

void insert(char data, node** head, node** tail)
{
    node* new = (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if((*head)==NULL)
    (*head)=new;
    if((*tail)!=NULL)
    {
        (*tail)->next=new;
        new->prev=(*tail);
    }
    (*tail)=new;
}

void main()
{
    int n;
    scanf("%d",&n);
    node* head=NULL;
    node* tail=NULL;
    char str[n];
    scanf("%s",str);
    for(int i=0;i<n;i++)
    {
        insert(str[i],&head,&tail);
    }
    node* front = head;
    node* back = tail;
    int flag=1;
    int k=0;
    while(k<n/2)
    {
        if(front->data!=back->data)
        {
            flag=0;
            break;
        }
        front=front->next;
        back=back->prev;
        k++;
    }
    if(flag==1)
    printf("YES");
    else
    printf("NO");
}