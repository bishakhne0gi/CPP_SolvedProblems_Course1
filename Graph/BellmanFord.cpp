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
    int v;
    int e;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>v;
    cout<<"Enter the number of edges: "<<endl;
    cin>>e;
    Graph g(v+1,e);
    cout<<"Initial Final Weight"<<endl;
    for(int i=0; i<e; i++)
    {
        int u,fin,w;
        cin>>u>>fin>>w;
        g.addEdge(u,fin,w);
    }
    vector<int> path= g.bellmanford(v,1);
    cout<<"SOURCE NODE: "<<1<<endl;
    for(int i=1; i<=v; i++)
    {
        cout<<"NODE "<<i<<" is at dist "<<path[i]<<endl;
    }
    return 0;
}