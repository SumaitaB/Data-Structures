#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define MAXNODE 101

using namespace std;

vector<int>graph[MAXNODE];
int vis[MAXNODE];
int nodes, edges;
int p=0;

void printAdjacencyList()
{
    int i,j;
    cout<<"ADJACENCY LIST: \n";
    for(int i=1; i<=nodes; i++)
    {
        cout<<i<<": ";

        for(int j=0; j<graph[i].size(); j++)
        {
            cout<<graph[i][j]<<" ";

        }
        cout<<endl;
    }
}

bool bfs(int s,int d)
{
    int x,y;
    for(int i=0; i<MAXNODE; i++)
    {
        vis[i]=0;
    }

    queue<int>que;
    que.push(s);
    vis[s]=1;
    while(!que.empty())
    {
        x=que.front();
        que.pop();
        vis[x]=2;

        for(int i=0; i<graph[x].size(); i++)
        {
            y=graph[x][i];
            if(vis[y]==0)
            {
                que.push(y);
                vis[y]=1;
            }
        }
    }
    if(vis[d]==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int path(int s,int d)
{
    int x,y,pl=0;
    for(int i=0; i<MAXNODE; i++)
    {
        vis[i]=0;
    }
    queue<int>que;
    que.push(s);
    vis[s]=1;
    while(!que.empty())
    {
        x=que.front();
        que.pop();
        vis[x]=2;
        for(int i=0; i<graph[x].size(); i++)
        {
            y=graph[x][i];
            if(vis[y]==0)
            {
                que.push(y);
                vis[y]=1;
            }
            else
            {
                pl++;
            }
        }
    }
    return pl;
}

int main()
{
    int u,v,q,t,flag=0;
    cin>>nodes>>edges;
    for(int i=0; i<edges; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);

    }
    printAdjacencyList();
    cout<<endl;
    cout<<"ENTER THE NUMBER OF QUERIES\n";
    cin>>q;

    while(q--)
    {
        cout<<endl;
        cout<<"Press 1 ---> to see if there's a direct connection between two nodes."<<endl;
        cout<<"Press 2 ---> to see if node v is reachable from node u and vice-versa."<<endl;
        cout<<"Press 3 ---> to see the shortest path between two nodes."<<endl;
        cin>>t;
        if(t==1)
        {
            flag=0;
            cin>>u>>v;
            for(int i=0; i<graph[u].size(); i++)
            {
                if(graph[u][i]==v)
                {
                    flag=1;
                }
            }
            if(flag==1)
            {
                cout<<"There is a direct connection between "<<u<<" and "<<v<<endl;
            }
            else
            {
                cout<<"There is NO direct connection between "<<u<<" and "<<v<<endl;
            }
        }
        else if(t==2)
        {
            cin>>u>>v;
            if(bfs(u,v))
            {
                cout<<v<<" IS REACHABLE FROM "<<u<<endl;
            }
            else
            {
                cout<<v<<" IS NOT REACHABLE FROM "<<u<<endl;
            }
        }

        else if(t==3)
        {
            cin>>u>>v;
            cout<<path(u,v)<<endl;
        }
    }
    return 0;
}

/*
7 7
1 2
2 5
2 3
1 3
4 1
5 3
6 7
*/


/*
7 6
1 2
6 7
2 3
1 3
4 1
5 3
*/

