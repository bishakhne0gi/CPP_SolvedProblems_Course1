#include <bits/stdc++.h>
using namespace std;
#define INF 10000
class Graph
{
    vector<vector<int>> *g;
    int V;

public:
    Graph(int v)
    {
        int V = v;
        vector<vector<int>> g(V);
    }
    
    vector<vector<int>> floyd_warshall(vector<vector<int>> g)
    {
        vector<vector<int>> dist(g);
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        return dist;
    }
};

int main()
{
    int v;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>v;
    Graph g(v+1);
    cout<<"Enter the weights of the edges: "<<endl;
    vector<vector<int>> graph(v);
    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            cin>>graph[i][j];
        }
    }
    auto res = g.floyd_warshall(graph);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}