#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string stackk[100];
const int size=100;
int top=0;

void push(string value)
{
    if(size==top)
    {
        cout<<"OVERFLOW"<<endl;;
        return ;
    }
    stackk[top]=value;
    top++;
}
void pop()
{
    if(top==0)
    {
        cout<<"UNDERFLOW"<<endl;;
        return;
    }
    top=top-1;
}
string gettop()
{
    string p="STACK EMPTY";
    if(top==0)
    {
        return p;
    }
    else
    {
        return stackk[top-1];
    }


}
void interface()
{
    //cout<<"-----------------------------"<<endl;
    cout<<"Press 1 to push a word"<<endl;
    cout<<"Press 2 to pop a word"<<endl;
    cout<<"Press 3 to access the top word"<<endl;
    cout<<"Press 4 to Exit"<<endl;
        cout<<"-----------------------------"<<endl;


}
int main()
{
    cout<<"\n                           *****************STACK IMPLEMENTATION*****************\n"<<endl;
    int op;
    string value;
    do
    {
        interface();
        cin>>op;
        if(op==1)
        {
            cout<<"ENTER A WORD\n";
            cin>>value;
            push(value);
        }
        else if(op==2)
        {
            pop();
        }
        else if(op==3)
        {
            cout<<"\nTOP WORD: "<<gettop()<<"\n"<<endl;
        }
        else if(op==4)
        {
            break;
        }
        else
        {
            cout<<"INVALID OPERATION\nENTER A VALID OPERATION\n";
        }
    }
    while(1);
    return 0;
}
