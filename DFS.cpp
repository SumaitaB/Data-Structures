#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define MAXNODE 100
vector<int>graph[MAXNODE];
int nodes, edges;

int main()
{
    int u,v;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    return 0;
}

