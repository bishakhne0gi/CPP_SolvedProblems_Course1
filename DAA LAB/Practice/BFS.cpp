#include<bits/stdc++.h>
using namespace std;
int graph[20][20];
char q[20];
int front=-1,rear=-1;
bool visited[20]={false};
void pushFunc(int n, char x)
{
    if(rear==-1 && front==-1)
    {
        rear++;
        front++;
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
    if(rear==-1 && front==-1)
    {
        cout<<"Underflowing"<<endl;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
}
void print(int n)
{
    cout<<"No of vertices: "<<n<<endl;
    cout<<"The graph is: "<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"\t"<<graph[i][j];
        }
        cout<<endl;
    }
}
void BFS(int n)
{   
    int v=0;
    pushFunc(n,v+65);
    char u;
    visited[0]=true;
    cout<<"BFS TRAVERSAL IS: "<<endl;
    while((rear!=-1 && front!=-1))
    {
        u=q[front];
        popfunc();
        cout<<u<<endl;
        for(int i=0; i<n; i++)
        {
            if(graph[u-65][i]==1 && visited[i]==false)
            {
                pushFunc(n,i+65);
                visited[i]=true;
            }
        }
    }   
}
int main()
{
    FILE *fp= fopen("abc.txt","r");
    if(fp==NULL)
        cout<<"Error in opening"<<endl;
    int n;
    fscanf(fp,"%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fscanf(fp,"%d", &graph[i][j]); 
        }
    }
    print(n);
    BFS(n);
    return 0;
}