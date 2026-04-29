#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, adj[10][10], visited[10]={0}, start;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> adj[i][j];

    cout << "Enter starting vertex: ";
    cin >> start;

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(int v=0; v<n; v++) {
            if(adj[u][v] && !visited[v]) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }

    return 0;
}
