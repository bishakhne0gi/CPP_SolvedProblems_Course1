#include <bits/stdc++.h>
using namespace std;
int graph[20][20];
bool visited[20]={false};
char s[20];
int top=-1;
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
    if(top==n-1)
    {
        cout<<"Overflowing"<<endl;
    }
    else
    {
        top++;
        s[top]=x;
    }
}
void popfunc()
{
    if(top==-1)
    {
        cout<<"Underflowing"<<endl;
    }
    else
    {
        top--;
    }
}
void DFS(int n)
{
    visited[0]={true};
    char u;
    int v=0;
    pushfunc(n,v+65);
    cout<<"DFS Traversal: "<<endl;
    while(top!=-1)
    {
        u=s[top];
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
    DFS(n);
    return 0;
}