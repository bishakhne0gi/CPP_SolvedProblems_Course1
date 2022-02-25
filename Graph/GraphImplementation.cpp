#include<bits/stdc++.h>
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
        void addEdge(int i, int j, bool onedirectional=true)
        {
            l[i].push_back(j);
            if(onedirectional)
                l[j].push_back(i);
        }
        void printAdjList()
        {
            for(int i=0; i<V; i++)
            {
                cout<<i<<"->";
                for(auto node:l[i])
                {
                    cout<<node;
                }
            }
        }
        void bfs(int source)
        {
            queue<int> q;
            vector<bool> visited(V,0);
            q.push(source);
            visited[source]=true;
            while(!q.empty())
            {
                int f=q.front();
                cout<<f<<endl;
                q.pop();
                for(auto nbr:l[f])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            } 
        }
        void dshelp(int node, bool *visited)
        {
            visited[node]=true;
            cout<<node<<", ";
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
           bool *visited = new bool[V]{0};
            dshelp(source,visited);
        }
};
int main()
{
    Graph g(7);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.bfs(1);
    g.dfs(1);
    return 0;
}