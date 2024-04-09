#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;   
    struct node* next;
    struct node* prev;
};
typedef struct node node;

void insert(int data, node** head, node** tail)
{
    node* new= (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if((*head)==NULL)
    {
        (*head)=new;
    }
    if((*tail)!=NULL)
    {
        new->prev=(*tail);
        (*tail)->next=new;
    }
    (*tail)=new;
}

void main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    int count[n+1];
    for(int i=0;i<n+1;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        count[a[i]]++;
    }
    node* buckets[n+1][2];
    for(int i=0;i<(n+1);i++)
    {
        buckets[i][0]=NULL;
        buckets[i][1]=NULL;
    }
    for(int i=0;i<n;i++)
    {
        if(count[a[i]]!=0)
        {
            insert(a[i],&buckets[count[a[i]]][0],&buckets[count[a[i]]][1]);
            count[a[i]]=0;
        }
    }
    for(int i=0;i<(n+1);i++)
    {
        node* ptr=buckets[i][0];
        while(ptr!=NULL)
        {
            for(int k=0;k<i;k++)
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
