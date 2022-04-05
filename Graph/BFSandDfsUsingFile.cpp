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
            cout<<"BFS TRAVERSAL: "<<endl;
            while(!q.empty())
            {
                int f=q.front();
                cout<<f<<" ";
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
            cout<<endl;
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
    Graph g(7);

      FILE *fp;
    fp = fopen("Ex.txt", "r");

    if (fp == NULL)
    {
        printf("\nError to open the file\n");
        exit(1);
    }
    int n;
    fscanf(fp, "%d", &n);

    // vector<int> adj[n];

   

    
    int i, j, count = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int temp;
            fscanf(fp, "%d", &temp);
            
            if (temp == 1)
            {
                count++;
                // addEdge(adj,i,j);
                g.addEdge(i,j);
            }
        }
    }
    g.bfs(0);
    g.dfs(0);
    return 0;
}