#include<bits/stdc++.h>
using namespace std;
#define inf 999
int n,k=0,noofedges=0;
int graph[20][20];
int dist[20];
struct node
{
	int u;
	int v;
	int w;
};
struct node edge[20];
void bellford()
{
	int u,v,w;
	for(int i=0;i<n;i++)
	{
		dist[i]=inf;
	}
	dist[0]=0;
	//n-1 times relaxation
	for(int i=1;i<=n-1;i++)
	{
		for(int j=0;j<noofedges;j++)
		{
			u=edge[j].u;
			v=edge[j].v;
			w=edge[j].w;
			if(dist[u]!=inf && dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
			}
		}
	}
	//Negative cycle detection
	for(int j=0;j<noofedges;j++)
	{
		u=edge[j].u;
		v=edge[j].v;
		w=edge[j].w;
		if(dist[u]!=inf && dist[u]+w<dist[v])
		{
			cout<<"Negative weight cycle detected!"<<endl;
			return;
		}
	}
	cout<<"The shortest path from source vertex A is:"<<endl;
	for(int i=0;i<n;i++)
	{
		char ch=i+65;
		cout<<ch<<" -- "<<dist[i]<<endl;
	}
}
int main()
{
	FILE *fp;
	fp=fopen("input_bellford.txt","r");
	if(fp==NULL)
	{
		printf("Error to open the file\n\n");
	}
	fscanf(fp,"%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			fscanf(fp,"%d",&graph[i][j]);
		}
	}
	cout<<"The graph in matrix format:"<<endl;
	for(int i=0;i<n;i++)
	{
		char ch=i+65;
		cout<<"\t"<<ch;
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		char ch=i+65;
		cout<<ch<<"\t";
		for(int j=0;j<n;j++)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"Inputs are:"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]!=0)
			{
				edge[k].u=i;
				edge[k].v=j;
				edge[k].w=graph[i][j];
				char U=edge[k].u+65;
				char V=edge[k].v+65;
				cout<<U<<" -- "<<V<<" : "<<edge[k].w<<endl;
				k++;
				noofedges++;
			}
		}
	}
	bellford();
	fclose(fp);
	return 0;
}
