#include <iostream>
using namespace std;

int adj[10][10], visited[10], n;

void dfs(int u) {
    cout<<u<<" ";
    visited[u]=1;

    for(int v=0;v<n;v++)
        if(adj[u][v] && !visited[v])
            dfs(v);
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) cin>>adj[i][j];

    dfs(0);
}
