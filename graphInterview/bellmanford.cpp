#include <bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};
int main()
{
    int n, edges, src;
    cin >> n >> edges >> src;
    vector<node > g;

    int a, b, wt;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b >> wt;
        g.push_back(node(a,b,wt));
    }
    vector<int> distance(n+1, INT_MAX);
    distance[src] = 0;
    //relaxation n-1 times
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto it: g)
        {
            int u = it.u;
            int v = it.v;
            int wt = it.wt;
            if (distance[u] != INT_MAX && distance[u] + wt < distance[v])
            {
                distance[v] = distance[u] + wt;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << "node: " << i << " distance: " << distance[i] << endl;
    }
    return 0;
}