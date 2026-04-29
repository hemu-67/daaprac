#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Prim {
public:
    int spanningTree(int V, vector<vector<int> > adj[]) {

        priority_queue<
            pair<int, pair<int, int> >,
            vector<pair<int, pair<int, int> > >,
            greater<pair<int, pair<int, int> > >
        > pq;

        vector<bool> isMST(V, false);
        vector<int> parent(V, -1);

        pq.push(make_pair(0, make_pair(0, -1))); // Start from node 0

        int cost = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int par = pq.top().second.second;
            pq.pop();

            if (!isMST[node]) {
                isMST[node] = true;
                cost += wt;
                parent[node] = par;

                for (int j = 0; j < adj[node].size(); j++) {
                    int adjNode = adj[node][j][0];
                    int edgeWt = adj[node][j][1];

                    if (!isMST[adjNode]) {
                        pq.push(make_pair(edgeWt, make_pair(adjNode, node)));
                    }
                }
            }
        }

        return cost;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int> > adj[V];   // C++11 supported

    cout << "Enter edges (u v weight):" << endl;

    for (int i = 0; i < E; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    Prim obj;
    cout << "Minimum Cost of MST = " << obj.spanningTree(V, adj);

    return 0;
}
