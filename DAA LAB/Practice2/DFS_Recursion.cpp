#include <bits/stdc++.h>
using namespace std;
int graph[20][20];
bool visited[20]={false};
char q[20];
int front=-1;
int rear=-1;
void printGraph(int n)
{
    cout<<"The graph is: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<endl;
    }
}
void DFS(int a, int n)
{
    visited[a]=true;
    char u=a+65;
    cout<<u<<" -> ";
    for(int i=0; i<n; i++)
    {
        if(graph[a][i]==1 && visited[i]==false)// check visited[i]==false
        {
            DFS(i,n);
        }
    }
    
}
int main()
{
    FILE *fp=fopen("abc.txt","r");
    int n;
    fscanf(fp,"%d", &n);
    cout<<"Number of vertices: "<<n<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fscanf(fp,"%d", &graph[i][j]);
        }
    }
    printGraph(n);
    cout<<"DFS Traversal: "<<endl;
    DFS(0,n);
    return 0;
}