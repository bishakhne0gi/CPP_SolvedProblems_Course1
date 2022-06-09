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
        set<pair<int,int>> s;
        distance[src]=0;
        s.insert({0,src});
        while(!s.empty())
        {
            auto it= s.begin();
            int node= it->second;
            int distTillNow= it->first;
            s.erase(it);
            for(auto nbrPair: l[node])
            {
                int nbr= nbrPair.second;
                int currentEdge= nbrPair.first;
                if(distTillNow+ currentEdge < distance[nbr])
                {
                    auto f =s.find({distance[nbr],nbr});
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }
                    distance[nbr]= distTillNow+ currentEdge;
                    s.insert({distance[nbr],nbr});
                }        

            }
        }
        for(int i=0; i<V; i++)
        {
            cout<<"Node  "<<i<<"is at Dist "<<distance[i]<<endl;
        }
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
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,4);
    // g.addEdge(0,3,7);
    // g.addEdge(2,3,2);
    // g.addEdge(3,4,3);
    cout<<"Source: "<<endl;
    int source;
    cin>>source;
    cout<<"Destination: "<<endl;
    int dest;
    cin>>dest;
    cout<<g.dikstra(source,dest)<<endl;
    return 0;
}