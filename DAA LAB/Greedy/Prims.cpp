#include<bits/stdc++.h>
using namespace std;
class Graph
{
    vector<pair<int,int>> *l;
    int V;
    public:
    Graph(int v)
    {
        V=v;
        l= new vector<pair<int,int>> [v];
    }
    void addEdge(int x, int y ,int w)
    {
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }
    void printAdjList()
        {
            cout<<"Adjacency List: "<<endl;
            for(int i=0; i<V; i++)
            {
                cout<<i<<"->";
                for(auto node: l[i])
                {
                    cout<<node.first<<" "<<node.second<<" ,";
                }
                cout<<endl;
            }
        }
    int prim_mst()
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
        bool *visited= new bool[V]{0};
        int ans=0;

        //begin

        Q.push({0,0});//weight,node
        while(!Q.empty())
        {
            auto best= Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if(visited[to]== true)
            {
                continue;
            }
            ans+=weight;
            visited[to]=true;
            //add the new edges in the priority queue
            for(auto x: l[to])
            {
                if(visited[x.first]==0)
                    {
                        Q.push({x.second,x.first});
                    }
            }
        }
        return ans;
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
    g.printAdjList();
    // Graph g(6);
    // g.addEdge(0,1,7);
    // g.addEdge(0,3,8);
    // g.addEdge(1,3,3);
    // g.addEdge(1,2,6);
    // g.addEdge(3,2,4);
    // g.addEdge(3,4,3);
    // g.addEdge(2,4,2);
    // g.addEdge(2,5,5);
    // g.addEdge(4,5,2);
    cout<<"COST OF MINIMUM SPANNING TREE: "<<endl;
    cout<<g.prim_mst()<<endl;
    //ANS: 17
    return 0;
}