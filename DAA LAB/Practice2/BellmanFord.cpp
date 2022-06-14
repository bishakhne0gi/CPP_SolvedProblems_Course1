#include <bits/stdc++.h>
using namespace std;
#define inf 999
int graph[20][20];
int k = 0;
int dist[20];
int noedges=0;
struct node
{
    int u;
    int v;
    int w;
};
struct node edge[20];
void bellmanford(int n)
{
    int u, v, w;
    for (int i = 0; i < n; i++)
    {
        dist[i] = inf;
    }
    dist[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < noedges; j++)
        {
            u = edge[j].u;
            v = edge[j].v;
            w = edge[j].w;
            if (dist[u] != inf && dist[u]+w<dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int j = 0; j < noedges; j++)
    {
        u = edge[j].u;
        v = edge[j].v;
        w = edge[j].w;
        if (dist[u] != inf && (dist[u]+w < dist[v]))
        {
            cout << "Negative cycle detected" << endl;
            return;
        }
    }
    cout<<"The shortest path from source vertex A is:"<<endl;
	for(int i=0;i<n;i++)
	{
		char ch=i+65;
		cout<<ch<<" -- "<<dist[i]<<endl;
	}
}
void printGraph(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    FILE *fp= fopen("belf.txt","r");
    int n;
    fscanf(fp,"%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fscanf(fp,"%d", &graph[i][j]);
        }
    }
    printGraph(n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(graph[i][j]!=0)
            {
                edge[noedges].u=i;
                edge[noedges].v=j;
                edge[noedges].w=graph[i][j];
                char U=edge[noedges].u+65;
                char V=edge[noedges].v+65;
                cout<<U<<" --- "<<V<<" --- "<<edge[noedges].w<<endl;
                noedges++;
            }
        }
    }
    bellmanford(n);
    return 0;
}