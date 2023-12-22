#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    string data;
    node *next;
};
node* push(node *root)

{

    node *temp=root;
    node *newnode=new node;
    string x;
    cout<<"ENTER WORD\n";
    cin>>x;
    newnode->data=x;
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
    return root;
}
node* poptop(node *root)
{
    if(root==NULL)
    {
        cout<<"UNDERFLOW\n";
        return root;
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
        cout<<temp->data<<endl;
        //printf("%s ", temp->data);
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
    //string x;
    do
    {
        option();
        cin>>n;
        if(n==1)
        {
            head=push(head);

        }
        else if(n==3)
        {
            head=getfront(head);
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
