#include <bits/stdc++.h>
using namespace std;
int graph[20][20];
int colours[20];
int counter=0;
bool flag=false;

void printgraph(int n)
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
bool isSafe(int graph[20][20], int colours[20], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(graph[i][j] && colours[i]==colours[j])
            {
                return false;
            }
        }
    }
    return true;
}
void printSol(int colours[20], int n)
{
    cout<<"Solution is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<colours[i]<<"\t";
    }
    cout<<endl;
}
bool graphColouring(int graph[20][20], int colours[20], int n, int m, int node)
{
    if(node==n)
    {
        if(isSafe(graph, colours,n))
        {
            counter++;
            flag=true;
            printSol(colours,n);
        }
        return false;
    }
    for(int j=1; j<=m; j++)
    {
        colours[node]=j;
        if(graphColouring(graph, colours, n, m, node+1))
        {
            return true;
        }
        colours[node]=0;
    }
    return false;
}
int main()
{
    FILE *fp=fopen("mcolour.txt","r");
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
    printgraph(n);
    int m;
    cout<<"Enter the number of colours(M): "<<endl;
    cin>>m;
    for(int i=0; i<n; i++)
    {
        colours[i]=0;
    }
    if(!(graphColouring(graph,colours,n,m,0)) && flag==false)
    {
        cout<<"Solution does not exist"<<endl;
    }
    cout<<"Total number of solutions: "<<counter<<endl;
    return 0;
}