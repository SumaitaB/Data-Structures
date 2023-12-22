#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    char data[100];
    node *next;
};
node* push(node *root,char value[])

{
    node *temp=root;
    node *newnode=(node*)malloc(sizeof(node));
    strcpy(newnode->data,value);
    newnode->next=NULL;
    if(root==NULL)
    {
        return newnode;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return root;
}
node* getfront(node *root)
{
    if(root==NULL)
    {
        cout<<"UNDERFLOW\n";
    }
    else
    {
         cout<<root->data<<endl;
    }
}
node* poptop(node *root)
{
    if(root==NULL)
    {
        cout<<"UNDERFLOW\n";
    }
    else
    {
        return root->next;
    }
}
void printall(node *root)
{
    for( node *temp=root; temp!=NULL; temp=temp->next)
    {
        printf("%s ", temp->data);
    }
    puts(" ");
}

void option()
{
    cout<<"1 for push"<<endl;
    cout<<"2 for pop"<<endl;
    cout<<"3 for getfront"<<endl;
    cout<<"4 for print all"<<endl;
    cout<<"5 for exit"<<endl;
    cout<<"-----------------------------"<<endl;
}
int main()
{
    cout<<"\n                           *****************LINKED LIST QUEUE IMPLEMENTATION*****************\n"<<endl;
    node* head=NULL;
    int n;
    char x[10];
    do
    {
        option();
        cin>>n;
        if(n==1)
        {
            cout<<"ENTER WORD\n";
            scanf("%s", x);
            head=push(head,x);

        }
        else if(n==3)
        {

            getfront(head);
        }
        else if(n==2)
        {
            head=poptop(head);
        }
        else if(n==4)
        {

            printall(head);
        }
        else if(n==5)
            break;
    }
    while(1);


    return 0;
}
