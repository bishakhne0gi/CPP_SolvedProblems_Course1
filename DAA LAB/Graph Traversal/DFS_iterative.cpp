/*
    Using adjacency list
    TC: O(V+E) v-number of vertices, e-number of edge
    
    SC: O(V) v-visited array space of size v 
*/
#include <bits/stdc++.h>
using namespace std;
int graph[20][20];
bool visited[20];
char s[20];
int top = -1;
void pushFunc(char v)
{
    if (top == 20-1)
    {
        cout<<"The stack is overflowing."<<endl;
    }
    else
    {
        top ++ ;
        s[top] = v;
    }
}
void popFunc()
{
    if (top == -1)
    {
        cout<<"The stack is underflowing."<<endl;
    }
    else
    {
        top --;
    }
}
void DFS(int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    int v = 0;
    char u;
    pushFunc(v + 65);
    visited[v] = true;
    cout<<"The DFS traversal of the graph is : "<<endl;    while (top != -1)
    {
        u = s[top];
        popFunc();
        cout<<u<<"\t"<<endl;
        for (int i = 0; i < n; i ++)
        {
            if (graph[u-65][i] == 1)
            {
                if (visited[i] == false)
                {
                    pushFunc(i + 65);
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
    FILE *fp = fopen("VE.txt", "r");
    if (fp == NULL)
    {
        cout<<" Error opening \n"<<endl;
    }
    int n;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            fscanf(fp, "%d", &graph[i][j]);
        }
    }
    print(n);
    DFS (n);
    return 0;
}
