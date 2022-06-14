#include <bits/stdc++.h>
using namespace std;
class DSU
{
    int *parent;
    int *rank;
    public:
    DSU(int n)
    {
        parent=new int[n];
        rank=new int[n];

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
        return parent[i]=find(parent[i]);
    }
    void unite(int u, int v)
    {
        int s1=find(u);
        int s2=find(v);
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=s1;
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=s2;
            }
        }
    }


};
class Graph
{
    int edgelist[20][3];
    int i=0;
    int V;
    public:
    Graph(int v)
    {
        V=v;
    }
    void addEdge(int u, int v, int w)
    {
        edgelist[i][0]=w;        
        edgelist[i][1]=u;        
        edgelist[i][2]=v;        
        i++;
    }int kruskal_mst(int e)
        {
            //sort all the edges based on weight
            // sort(edgelist.begin(), edgelist.end());
            int temp_w=0, temp_x=0, temp_y=0;
            for(int i=0; i<e; i++)
            {
                for(int j=i+1; j<e; j++)
                {
                    if(edgelist[i][0]>edgelist[j][0])
                    {
                        temp_w= edgelist[j][0];
                        edgelist[j][0]=edgelist[i][0];
                        edgelist[i][0]=temp_w;

                        temp_x= edgelist[j][1];
                        edgelist[j][1]=edgelist[i][1];
                        edgelist[i][1]=temp_x;

                        temp_y= edgelist[j][2];
                        edgelist[j][2]=edgelist[i][2];
                        edgelist[i][2]=temp_y;
                    }
                }
            }
            //initialise DSU
            DSU s(V);
            int ans=0;
            cout<<"Edges \t"<<"Weights"<<endl;
            for(int i=0; i<e; i++)
            {
                int w=edgelist[i][0];
                int x= edgelist[i][1];
                int y= edgelist[i][2];
                
                if(s.find(x)!=s.find(y))
                {
                    s.unite(x,y);
                    cout<<x<<"---"<<y<<"\t"<<w<<endl;
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
    cout<<"COST OF MINIMUM SPANNING TREE: "<<endl;
    cout<<g.kruskal_mst(e)<<endl;
    return 0;
}