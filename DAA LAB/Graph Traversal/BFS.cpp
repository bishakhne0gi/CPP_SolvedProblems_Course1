/*
    Using adjacency list
    TC: O(V+E) v-number of vertices, e-number of edge
    Using adjacecny matrix
    TC: O(v2)
    
    SC: O(V) v-numbe of vertices
*/
#include <bits/stdc++.h>
using namespace std;
int graph[20][20];
bool visited[20]={false};
char q[20];
int rear = -1, front = -1;
void pushFunc(int n, char x)
{
    if (rear == -1 && front == -1)
    {
        rear ++;
        front ++;
        q[rear] = x;
    }
    else if (rear == n-1)
    {
        cout<<"The queue is overflowing."<<endl;
    }
    else
    {
        rear ++;
        q[rear] = x;
    }
}
void popFunc()
{
    if (rear == -1 && front == -1)
    {
        cout<<"The queue is underflowing."<<endl;
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front ++;
    }
}
void BFS (int n)
{
    visited[0] = true;
    int v = 0;
    char u;
    pushFunc(n,v + 65);
    cout<<"The BFS traversal of the graph is : "<<endl;
    while ((rear != -1 && front != -1) || front < rear)
    {
        u = q[front];
        popFunc();
        cout<<u<<"\t"<<endl;
        for (int i = 0; i < n; i ++)
        {
            if (graph[u-65][i] == 1)
            {
                if (visited[i] == false)
                {
                    pushFunc(n, i+65);
                    visited[i] = true;
                }
            }
        }
    }
}

void print(int n)
{
    cout<<"The graph is: "<<endl;
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            cout<<"\t"<<graph[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    FILE *fp = fopen("bfs.txt", "r");
    if (fp == NULL)
    {
        cout<<" Error opening \n"<<endl;
        exit(0);
    }
    int n, x;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    print(n);
    BFS (n);
    return 0;
}
