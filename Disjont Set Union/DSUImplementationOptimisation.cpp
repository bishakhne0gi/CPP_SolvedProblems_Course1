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
        int p= findSet(parent[i],parent);
        parent[i]=p;
        return p;
    }
    void unionSet(int x, int y, int parent[], int rank[])
    {
       int s1= findSet(x,parent);
       int s2= findSet(y,parent);
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
       cout<<"PARENT: ";
		for(int i=0;i<V;i++){
			cout<<parent[i]<<" ";
		}
       cout<<endl;
       cout<<"RANK: ";
       for(int j=0; j<V; j++)
        cout<<rank[j]<<" ";
       cout<<endl;
    }
    bool contains_cycle()
    {
        int *parent = new int[V];
        int *rank= new int[V];
        for(int i=0; i<V; i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        for(auto edge: l)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=findSet(i,parent);
            int s2=findSet(j,parent);
            cout<<i<<"-"<<s1<<" and "<<j<<"-"<<s2<<endl;
            if(s1!=s2)
                unionSet(s1,s2,parent,rank);
            else
            {
                cout<<"PARENT: ";
				for(int i=0;i<V;i++){
					cout<<parent[i]<<" ";
				}
                cout<<endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};
int main()
{
    cout<<"ENTER THE NUMBER OF VERTICES: "<<endl;
    int V;
    cin>>V;
    Graph g(V);
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
