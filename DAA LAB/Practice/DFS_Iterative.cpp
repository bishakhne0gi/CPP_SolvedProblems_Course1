#include<bits/stdc++.h>
using namespace std;
int graph[20][20];
char s[20];
int top=-1;
bool visited[20]={false};
void print(int n)
{
    cout<<"The graph is"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<"\t"<<graph[i][j];
        }
        cout<<endl;
    }
}
void pushFunc(int n, char x)
{
    if(top==-1)
    {
        top++;
        s[top]=x;
    }
    else if(top==n-1)
    {
        cout<<"Overflowing"<<endl;
    }
    else
    {
        top++;
        s[top]=x;
    }
}
void popFunc()
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
    visited[0]=true;
    int v=0;
    char u;
    pushFunc(n,v+65);
    cout<<"DFS: "<<endl;
    while(top!=-1)
    {
        u=s[top];
        cout<<u<<endl;
        popFunc();
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
    FILE *fp=fopen("abc.txt","r");
    if(fp==NULL)
        cout<<"Error in opening file"<<endl;
    int n;
    fscanf(fp,"%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fscanf(fp,"%d", & graph[i][j]);
        }
    }
    print(n);
    DFS(n);
    return 0;
}
