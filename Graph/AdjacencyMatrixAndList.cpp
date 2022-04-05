#include <bits/stdc++.h>
using namespace std;
void adjList(int v, int e, vector<pair<int, int>> p)
{
    vector<int> g[v + 1];
    cout << "ADJACENCY LIST: " << endl;
    for (int i = 0; i < e; i++)
    {
        g[p[i].first].push_back(p[i].second);
        g[p[i].second].push_back(p[i].first);
    }
    for (int i = 1; i <= v; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
void adjMatrix(int v, int e, vector<pair<int, int>> p)
{
    vector<vector<int>> g(v+1, vector<int>(v+1,0));
    cout << "ADJACENCY MATRIX: " << endl;
    for (int i = 0; i < e; i++)
    {
        g[p[i].first][p[i].second] = 1;
        g[p[i].second][p[i].first] = 1;
    }
    for (int i = 1; i <= v; i++)
    {
        cout << i << " -> ";
        for (int j = 1; j <= v; j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> p;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
     adjList(v, e, p);
     adjMatrix(v, e, p);
   
    return 0;
}