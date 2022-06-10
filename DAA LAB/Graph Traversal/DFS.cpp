/*
    Using adjacency list
    TC: O(V+E) v-number of vertices, e-number of edge
    
    SC: O(V) v-visited array space of size v 
*/

#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<int> *l;
    public:
        Graph(int v)
        {
            V=v;
            l=new list<int>[v];
        }
        void addEdge(int i, int j)
        {
            l[i].push_back(j);
            l[j].push_back(i);
        }
        void printAdjList()
        {
            cout<<"Adjacency List: "<<endl;
            for(int i=0; i<V; i++)
            {
                cout<<i<<"->";
                for(auto node: l[i])
                {
                    cout<<node<<" , ";
                }
                cout<<endl;
            }
        }
         void dshelp(int node, bool *visited)
        {
            
            visited[node]=true;
            cout<<node<<" ";
            for(int nbr: l[node])
            {
                if(!visited[nbr])
                {
                    dshelp(nbr,visited);
                }
            }
           
            return;
        }
            void dfs(int source)
        {
            cout<<"DFS TRAVERSAL: "<<endl;
           bool *visited = new bool[V]{0};
            dshelp(source,visited);
             cout<<endl;
        }
};
int main()
{
    cout<<"Enter the number of vertices: "<<endl;
    int n;
    cin>>n;
    Graph g(n);
    int count=0;
    cout<<"Enter the number of edges: "<<endl;
    int m;
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.printAdjList();
    int source;
    cout<<"Enter the source: "<<endl;
    cin>>source;
    g.dfs(source);
    return 0;
}