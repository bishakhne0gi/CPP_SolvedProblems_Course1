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
void pushfunc(int n, char x)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        q[rear]=x;
    }
    else if(rear==n-1)
    {
        cout<<"Overflowing"<<endl;
    }
    else
    {
        rear++;
        q[rear]=x;
    }
}
void popfunc()
{
    if(front==-1 && rear==-1)
        cout<<"Underflowing"<<endl;
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
}
void BFS(int n)
{
    visited[0]={true};
    char u;
    int v=0;
    pushfunc(n,v+65);
    cout<<"BFS Traversal: "<<endl;
    while((front !=1 && rear!=-1)|| front<rear)
    {
        u=q[front];
        popfunc();
        cout<<u<<" -> ";
        for(int i=0; i<n; i++)
        {
            if(graph[u-65][i]==1 && visited[i]==false) //u-65 for the row 
            {
                pushfunc(n,i+65);
                visited[i]=true;
            }
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
    BFS(n);
    return 0;
}