#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<pair<int,int>> *l;
    public:
    Graph(int v)
    {
        V=v;
        l= new vector<pair<int,int>> [v];
    }
    void addEdge(int u, int v, int wt)
    {
        l[u].push_back({wt,v});
        l[v].push_back({wt,u});
    }
    int dikstra(int src, int dest)
    {
        vector<int> distance(V,INT_MAX);
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
        distance[src]=0;
        Q.push({0,src});
        while(!Q.empty())
        {
            auto it= Q.top();
            int node= it.second;
            int distTillNow= it.first;
            Q.pop();
            for(auto nbrPair: l[node])
            {
                int nbr= nbrPair.second;
                int currentEdge= nbrPair.first;
                if(distTillNow+ currentEdge < distance[nbr])
                {
                    distance[nbr]= distTillNow+ currentEdge;
                    Q.push({distance[nbr],nbr});
                }        

            }
        }
        // for(int i=0; i<V; i++)
        // {
        //     cout<<"Node  "<<i<<"is at Dist "<<distance[i]<<endl;
        // }
        return distance[dest];
    }
};
int main()
{
    cout<<"Enter the no. of vertices: "<<endl;
    int v;
    cin>>v;
    Graph g(v);
    cout<<"Enter the no. of edges: "<<endl;
    int e;
    cin>>e;
    cout<<"INITIAL FINAL WEIGHT"<<endl;
    for(int i=1; i<=e; i++)
    {
        int u, fin, w;
        cin>>u>>fin>>w;
        g.addEdge(u,fin,w);
    }
    cout<<"Source: "<<endl;
    int source;
    cin>>source;
    cout<<"Destination: "<<endl;
    int dest;
    cin>>dest;
    // source: 0, dest: 5
    cout<<g.dikstra(source,dest)<<endl;
    //ANS: 13
    return 0;
}