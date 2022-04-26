#include <bits/stdc++.h>
using namespace std;
class DSU
{
    int *parent;
    int *rank;
    public:
        DSU(int n)
        {
            parent= new int[n];
            rank= new int[n];

            for(int i=0; i<n; i++)
            {
                parent[i]=-1;
                rank[i]=1;
            }
        }
        int find(int i)
        {
            if(parent[i]==-1)
                return i;
            int p=find(parent[i]);
            parent[i]=p;
            return p;
        }
        void unite(int u, int v)
        {
            int s1= find(u);
            int s2= find(v);
            if(s1!=s2)
            {
                if(rank[s1]<rank[s2])
                {
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else
                {
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
        }
};
// class Edge
// {
    
//     public:
//         int w;
//         char x;
//         char y;
// };
class Graph
{
    vector<vector<int>> edgelist;
    int V;
    public:
        Graph(int v)
        {
            V=v;
        }
        void addEdge(int x, int y, int w)
        {
            edgelist.push_back({w,x,y});
        }
        int kruskal_mst()
        {
            //sort all the edges based on weight
            sort(edgelist.begin(), edgelist.end());
            //initialise DSU
            DSU s(V);
            int ans=0;
            for(auto edge: edgelist)
            {
                int w= edge[0];
                int x= edge[1];
                int y= edge[2];
                if(s.find(x)!=s.find(y))
                {
                    s.unite(x,y);
                    ans+=w;
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
    cout<<g.kruskal_mst()<<endl;
    return 0;
}