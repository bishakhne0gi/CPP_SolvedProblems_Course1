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
int visited[20];
char q[20];
int rear = -1, front = -1;
void enqueFunc(int n, char x)
{
    if (rear == -1 && front == -1)
    {
        rear ++;
        front ++;
        q[rear] = x;
    }
    else if (rear == n-1)
    {
        printf("\n The queue is overflowing !!! \n");
    }
    else
    {
        rear ++;
        q[rear] = x;
    }
}
void dequeFunc(int n)
{
    if (rear == -1 && front == -1)
    {
        cout<<"\n The queue is underflowing."<<endl;
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
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int v = 0;
    char u;
    enqueFunc(n, v+65);
    visited[v] = true;
    cout<<"The BFS traversal of the graph is : "<<endl;
    while ((rear != -1 && front != -1) || front < rear)
    {
        u = q[front];
        dequeFunc(n);
        cout<<u<<"\t"<<endl;
        for (int i = 0; i < n; i ++)
        {
            if (graph[u-65][i] == 1)
            {
                if (visited[i] == 0)
                {
                    enqueFunc(n, i+65);
                    visited[i] = 1;
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
    FILE *fp = fopen("VE.txt", "r");
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
