#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    Node *next;
};

Node* insertTop(Node *root,int value)
{
    Node *newNode=(Node*) malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=root;
    root=newNode;
    return newNode;
}
Node* popTop(Node *root)
{
    return root->next;
}
void printAll(Node *root)
{
    for(Node *tmp=root; tmp!=NULL; tmp=tmp->next)
    {
        printf("%d ",tmp->data);
    }
    puts("");
}
void insertAtPostion(Node* root, int pos,int value)
{
    Node *tmp=root;
    for(int i=1; i<pos; i++)
    {
        tmp=tmp->next;
    }
    Node *newNode=(Node *)malloc(sizeof(Node*));
    newNode->data=value;
    newNode->next=tmp->next;

    tmp->next=newNode;

}
int main()
{
    Node* head=NULL;
    for(int i=0; i<10; i++)
    {
        head=insertTop(head,i+1);
    }
    printAll(head);
    head=popTop(head);
    printAll(head);
    insertAtPostion(head,3,-5);
    printAll(head);

}
