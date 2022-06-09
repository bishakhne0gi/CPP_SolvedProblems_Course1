/*
    TC: O(V+E) v-number of vertices, e-number of edge
    SC: O(V) v-numbe of vertices
*/

#include <bits/stdc++.h>
using namespace std;
class Queue
{
    int *arr;
    int cs;
    int ms;
    int front;
    int rear;

public:
    Queue(int default_size = 5)
    {
        ms = default_size;
        arr = new int[ms];
        cs = 0;
        front = 0;
        rear = ms - 1;
    }

    bool full()
    {
        return cs == ms;
    }
    bool empty()
    {
        return cs == 0;
    }
    void push(int data)
    {
        if (!full())
        {
            rear = (rear + 1) % ms;
            arr[rear] = data;
            cs++;
        }
    }
    int frontFun()
    {
        if (!empty())
            return arr[front];
        return 0;
    }
    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % ms;
            cs--;
        }
    }
};
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
        void bfs(int source)
        {
            Queue q;
            bool visited[100]={false};
            q.push(source);
            visited[source]=true;
            cout<<"BFS TRAVERSAL: "<<endl;
            while(!q.empty())
            {
                int f=q.frontFun();
                cout<<f<<" ";
                q.pop();
                for(auto nbr:l[f])
                {
                    if(visited[nbr]!=true)
                    {
                        q.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
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
    g.bfs(source);
    return 0;
}