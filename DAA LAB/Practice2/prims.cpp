#include <bits/stdc++.h>
using namespace std;
int graph[20][20];
bool mst[20];
int key[20];
int parent[20];
void prims(int n)
{   
    for (int i = 0; i < n; i++)
	{
		key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
	}
    parent[0]=-1;
    key[0]=0;
    // creating min spanning tree traversing so n-1 edges
    for(int i=0; i<n-1; i++)
    {
        int mini=INT_MAX,u;
        // finding minimum among key array and storing in mini
        for(int j=0; j<n; j++)
        {
            if(mst[j]==false && key[j]<mini)
            {
                mini=key[j];
                u=j;
            }
        }
        //making mst true
        mst[u]=true;
        //changing parent and key according to the mini
        for(int k=0; k<n; k++)
        {
            if(graph[u][k] && mst[k]==false && graph[u][k]<key[k])
            {
                parent[k]=u;
                key[k]=graph[u][k];
            }
        }
    }

    int sum=0;
    cout<<"EDGES \t "<<" WEIGHTS"<<endl;
    for(int i=1; i<n; i++)
    {
        cout<<char(parent[i]+65)<<" --- "<<char(i+65)<<"\t"<<graph[i][parent[i]]<<endl;
        sum+=graph[i][parent[i]];
    }
   
    cout<<"COST: "<<sum<<endl;
}
void prinGraph(int n)
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
int main()
{
    FILE *fp=fopen("prims.txt","r");
    if(fp==NULL)
        cout<<"Error in opening file"<<endl;
    int n;
    fscanf(fp,"%d", &n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fscanf(fp,"%d", &graph[i][j]);
        }
    }
    cout<<"No of vertices: "<<n<<endl;
    prinGraph(n);
    prims(n);
    return 0;
}