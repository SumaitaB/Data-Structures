#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define V 100000

vector<int> graph[V];
int dist[V], path[V];

bool BFS(int s, int e){
    queue<int> Q; Q.push(s);
    bool visited[V];
    memset(visited, false, sizeof(visited));
    visited[s] = true;

    while (!Q.empty()){
        s = Q.front(); Q.pop();

        for (int i = 0; i < graph[s].size(); i++){
            int p = graph[s][i];

            if (!visited[p]){
                visited[p] = true;
                Q.push(p);
                dist[p] = dist[s]+1;
                path[p] = s;
            }
        }
    }

    if (!dist[e]) cout << -1 << endl;
    else {
        cout << dist[e] << endl;
        cout << e << ' ';

        int i = e;
        while (path[i]){
            cout << path[i] << ' ';
            i = path[i];
        } cout << endl;
    }
}

int main(){
    int n, m; cin >> n >> m;
    int a, b; cin >> a >> b;

    while (m--){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BFS(a, b);

    return 0;
}
