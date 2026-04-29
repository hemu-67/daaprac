#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define INF 1000000000

class solution {
public:
    vector<int> dijikstra(int V, vector<vector<int> > adj[], int S) {

        vector<bool> Explored(V, false);
        vector<int> dist(V, INF);

        dist[S] = 0;

        priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;
        pq.push(make_pair(0, S));

        while(!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            if(Explored[node]) continue;

            Explored[node] = true;

            for(int j = 0; j < adj[node].size(); j++) {
                int neighbour = adj[node][j][0];
                int weight = adj[node][j][1];

                if(!Explored[neighbour] && dist[node] + weight < dist[neighbour]) {
                    dist[neighbour] = dist[node] + weight;
                    pq.push(make_pair(dist[neighbour], neighbour));
                }
            }
        }

        return dist;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int> > adj[100];   // fixed size for Dev-C++

    cout << "Enter edges (u v weight):\n";
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        vector<int> temp1;
        temp1.push_back(v);
        temp1.push_back(w);
        adj[u].push_back(temp1);

        vector<int> temp2;
        temp2.push_back(u);
        temp2.push_back(w);
        adj[v].push_back(temp2);   // remove if directed graph
    }

    int S;
    cout << "Enter source vertex: ";
    cin >> S;

    solution obj;
    vector<int> result = obj.dijikstra(V, adj, S);

    cout << "\nShortest distances from source:\n";
    for(int i = 0; i < V; i++) {
        cout << "To " << i << " = " << result[i] << endl;
    }

    return 0;
}
