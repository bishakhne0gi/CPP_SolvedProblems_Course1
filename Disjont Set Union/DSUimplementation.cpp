#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    list<pair<int,int>> l;
    public:
    Graph(int v)
    {
        V=v;
    }
    int addEdge(int i,int j)
    {
        //creation of edgelist
        l.push_back(make_pair(i,j));
    }
    int findSet(int i, int parent[])
    {
        if(parent[i]==-1)
            return i;
        return findSet(parent[i], parent);
    }
    void unionSet(int x, int y, int parent[])
    {
        int s1=findSet(x,parent);
        int s2=findSet(y,parent);
        if(s1!=s2)
            parent[s1]=s2;
    }
    bool contains_cycle()
    {
        int *parent = new int[V];
        for(int i=0; i<V; i++)
            parent[i]=-1;
        for(auto edge: l)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=findSet(i,parent);
            int s2=findSet(j,parent);
            if(s1!=s2)
                unionSet(s1,s2,parent);
            else
            {
                cout<<"PARENTS ARE SAME "<<s1<<" "<<s2<<endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};
int main()
{
    Graph g(4);
    cout<<"Enter the no. of edges: "<<endl;
    int e;
    cin>>e;
    for(int i=1; i<=e; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }
    if(g.contains_cycle()==true)
    {
        cout<<"Cycle detected!"<<endl;
    }
    else
        cout<<"Cycle not detected!"<<endl;
    return 0;
}
