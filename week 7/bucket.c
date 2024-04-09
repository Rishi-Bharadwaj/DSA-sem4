#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    float data;
    struct node * next;
    struct node* prev;
};
typedef struct node node;

void insert(node**head,float data)
{

    node* new = (node*)malloc(sizeof(node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
    if((*head)!=NULL)
    {
        new->next=(*head);
        (*head)->prev=new;
    }
    (*head)=new;
    
}

void bucket(float a[], int n)
{
    node* arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=NULL;
    }
    int m;
    for(int i=0;i<n;i++)
    {
        m=a[i]*n;
        insert(&arr[m],a[i]);
    }
 
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=NULL){
        node* ptr=arr[i]->next;
        while(ptr != NULL) {
            node* temp = ptr->next;
            node* past = ptr->prev;
            float c = ptr->data;
            int flag=1;
            while(past != NULL && c < past->data) {
                if(flag==1)
                {
                    past->next=temp;
                    if(temp!=NULL)
                    temp->prev=past;
                    flag=0;
                }
                past = past->prev;
            }
            if(flag==0){
                if (past == NULL) {
                    // Assign as head if past is NULL
                    ptr->next = arr[i];
                    ptr->prev = NULL;
                    arr[i]->prev = ptr;
                    arr[i] = ptr;
                } else {
                    node* future = past->next;
                    past->next = ptr;
                    ptr->prev = past;
                    if (future != NULL) {
                        future->prev = ptr;
                    } 
                    ptr->next=future;
                }}
            ptr = temp;
        }
    }
}
    int count[n];
    for(int i=0;i<n;i++)
    count[i]=0;
    char buffer[10];
    for(int i=0;i<n;i++)
    {
        node*ptr = arr[i];
        while(ptr!=NULL)
        {
            sprintf(buffer,"%f",ptr->data);
             int len = strlen(buffer);
            for (int i = len - 1; i >= 0; i--) {
                if (buffer[i] == '0') {
                    buffer[i] = '\0';
                } else if (buffer[i] == '.') {
                    buffer[i] = '\0'; // Remove the decimal point if it's trailing
                    break;
                } else {
                    break;
                }
            }
            printf("%s ",buffer);
            count[i]++;
            ptr=ptr->next;
        }
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",count[i]);
    }
}

void main()
{
    int n;
    scanf("%d",&n);
    float a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
    bucket(a,n);
}