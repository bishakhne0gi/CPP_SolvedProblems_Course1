#include <bits/stdc++.h>
using namespace std;
#define inf 999
int graph[20][20];
int dist[20];
int noe = 0;
void printGraph(int n)
{
    cout << "The graph is: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
struct Node
{
    int u;
    int v;
    int w;
};
struct Node edge[20];
void bellmanfor(int n)
{
    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        dist[i] = inf;
    }
    dist[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < noe; j++)
        {
            u = edge[j].u;
            v = edge[j].v;
            w = edge[j].w;
            if (dist[u] != inf && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int j = 0; j < noe; j++)
    {
        u = edge[j].u;
        v = edge[j].v;
        w = edge[j].w;
        if (dist[u] != inf && dist[u] + w < dist[v])
        {
            cout<<"Negative cycle"<<endl;
            return;
        }
    }
        char a;
        cout<<"BELLMANFORD: "<<endl;
        cout<<"SOURCE: A"<<endl;
        cout<<"VERTICES \t"<<"DISTANCES"<<endl;
        for(int i=0; i<n; i++)
        {
            a=i+65;
            cout<<a<<"\t"<<dist[i]<<endl;
        }
}
int main()
{
    FILE *fp = fopen("bellman.txt", "r");
    int n;
    fscanf(fp, "%d", &n);
    cout << "No. of vertices: " << n << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    printGraph(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(graph[i][j]!=0)
            {
                edge[noe].u=i;
                edge[noe].v=j;
                edge[noe].w=graph[i][j];
                noe++;
            }
        }
    }
    cout<<"EdgeList: "<<endl;
    cout<<"Edges\t"<<"Weights"<<endl;
    for(int i=0; i<noe; i++)
    {
        cout<<edge[i].u<<"--"<<edge[i].v<<"\t"<<edge[i].w<<endl;
    }
    cout<<endl;
    bellmanfor(n);
    return 0;
}