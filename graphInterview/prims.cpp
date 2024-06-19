#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, edges;
    cin >> n >> edges;
    vector<pair<int, int> > graph[n + 1]; // Adjacency list for the graph

    int a, b, wt;
    for (int i = 0; i < edges; i++) {
        cin >> a >> b >> wt;
        graph[a].push_back(make_pair(b, wt)); // Add edges to the graph
        graph[b].push_back(make_pair(a, wt)); // For undirected graphs, add edge in both directions
    }

    vector<int> distance(n + 1, INT_MAX); // Distance array for Prim's algorithm
    distance[0] = 0; // Start from node 0 (assuming any node can be the starting point)

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, 0)); // Push starting node with distance 0

    vector<bool> visited(n + 1, false); // Visited flag to avoid revisiting nodes

    int mst = 0; // Minimum Spanning Tree weight
    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        int u = node.second;

        if (visited[u]) { // Skip already visited nodes
            continue;
        }

        visited[u] = true;
        mst += node.first;

        for (auto it : graph[u]) {
            int v = it.first;
            int weight = it.second;

            if (!visited[v]){
                pq.push(make_pair(weight, v)); // Push neighbor with updated distance
            }
        }
    }

    cout << "Minimum Spanning Tree weight: " << mst << endl;
    return 0;
}
