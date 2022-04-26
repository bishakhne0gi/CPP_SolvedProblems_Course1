#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int v,e;
    vector<vector<int>> *edges;
    public:
     Graph(int N, int M)
     {
         v=N;
         e=M;
         edges= new vector<vector<int>>[v];

     }
    void addEdge(int u, int v, int wt)
    {
        edges[u].push_back({u,v,wt});
    }  
    vector<int> bellmanford(int v,int src)
    {
        vector<int> dist(v+1, INT_MAX);
        dist[src]=0;
        for(int i=0; i<v-1; i++)
        {
            for(auto edge: edges[i])
            {
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(dist[u]!=INT_MAX && dist[u] + wt < dist[v])
                {
                    dist[v]= dist[u]+wt;
                }
            }
            for(auto edge: edges[i])
            {
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(dist[u]!=INT_MAX && dist[u] + wt < dist[v])
                {
                    cout<<"Negative wt cycle found"<<endl;
                    exit(0);
                }
            }
        }
        return dist;
    }      
};
int main()
{
    Graph g(3,3);
    g.addEdge(1,2,3);
    g.addEdge(2,3,4);
    g.addEdge(1,3,-10);
    vector<int> path= g.bellmanford(3,1);
    for(int i=1; i<=3; i++)
    {
        cout<<"NODE "<<i<<" is at dist "<<path[i]<<endl;
    }
    return 0;
}