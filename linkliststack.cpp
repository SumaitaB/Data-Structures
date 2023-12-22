#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    node *next;
};

void printall(node *root)
{
    for( node *temp=root;temp!=NULL;temp=temp->next)
    {
        printf("%d ", temp->data);
    }
    puts(" ");
}

void insertat(node* root,int pos)
{
    node *tmp=root;
    for(int i=1;i<pos;i++)
    {
        tmp=tmp->next;
    }
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=-5;
    newnode->next=tmp->next;
    tmp->next=newnode;
}

node* poptop(node *root)
{
    return root->next;
}

node* inserttop(node *root,int value)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=root;
    root=newnode;
    return newnode;
}

int main()
{
    node* head=NULL;
    for(int i=0;i<10;i++)
    {
       head=inserttop(head,i+1);
    }
    printall(head);
    head=poptop(head);
    printall(head);
    insertat(head,3);
    printall(head);
}
