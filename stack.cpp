#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
string stck[100];
const int sz=100;
int top=0;

void push(string word)
{
    if(sz==top)
    {
        puts("OVERFLOW");
        return;
    }
    stck[top]=word;
    top++;
}

string getTop()
{
    if(top==0)
    {
        return "NULL";
    }
    return stck[top-1];
}
void pop()
{
    if(top==0)
    {
        puts("UNDERFLOW");
        return;
    }
    top=top-1;
}

void interface()
{
    puts("Enter 1 for push");
    puts("Enter 2 for pop");
    puts("Enter 3 for getTop");
    puts("Enter 4 for exit\n");
}

int main()
{
    int option;
    string word;
    do
    {
        interface();
        cin>>option;
        if(option==1)
        {
            cin>>word;
            push(word);
        }
        else if(option==2)
        {
            pop();
        }
        else if(option==3)
        {
            cout<<"TOP: "<<getTop()<<endl;
        }
        else if(option==4) break;
        else puts("INVALID OPTION");
    }while(1);
    return 0;
}
