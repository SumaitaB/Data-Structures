#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
void printall(node *root)
{
    for( node *temp=root; temp!=NULL; temp=temp->next)
    {
        printf("%d ", temp->data);
    }
    puts(" ");
}
node* poptop(node *root)
{
    return root->next;
}
node* printtop(node *root)
{
    cout<<root->data<<endl;
}
node* inserttop(node *root,int value)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=root;
    root=newnode;
    return newnode;
}
void option()
{
    cout<<"1 for insertion"<<endl;
    cout<<"2 for print-top"<<endl;
    cout<<"3 for pop-top"<<endl;
    cout<<"4 for view all"<<endl;
    cout<<"5 for exit"<<endl;
}
int main()
{
    node* head=NULL;
    int n,x;
    do
    {
        option();
        cin>>n;

        if(n==1)
        {
            system("cls");
            cin>>x;
            head=inserttop(head,x);

        }
        else if(n==2)
        {
            system("cls");
            printtop(head);
        }
        else if(n==3)
        {
            system("cls");
            head=poptop(head);
        }
        else if(n==4)
        {
            system("cls");
            printall(head);
        }
        else if(n==5)
            return 0;
    }
    while(1);


    return 0;
}
