#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* a;
void show()
{
    struct node* pt=a;
    while(pt!=NULL)
    {
        printf("%d ",pt->data);
        pt=pt->next;
    } printf("\n");
}
void refill()
{
    printf("Enter data: "); int i; scanf("%d",&i);
    if(a==NULL)
    {
        a=(struct node*)malloc(sizeof(struct node));
        a->data=i; a->next=NULL; return;
    }
    struct node* y=(struct node*)malloc(sizeof(struct node));
    y->data=i; y->next=a; a=y;
}
void delete()
{
    if(a==NULL) return; if(a->next==NULL) a=NULL;
    while(a->next!=NULL)
    {
        if(a->next->data==3) {a->next=a->next->next; break;}
        a=a->next;
    }
    if(a!=NULL) {if(a->data==3) a=NULL;}
}
int main()
{
    a=NULL;
    int opt; printf("Enter 1 to start and continue,-1 to stop : ");
    scanf("%d",&opt);
    while(opt!=-1)
    {
        refill(); show();
        printf("Enter 1 to start and continue,-1 to stop : ");
        scanf("%d",&opt);
    }
    delete(); show();
}