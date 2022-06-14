#include<bits/stdc++.h>
using namespace std;
#define inf 999
int graph[20][20];
int dist[20][20];
void floydwarshall(int graph[20][20], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    cout<<"THE DISTANCE IS AS FOLLOW: "<<endl;

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
			cout<<dist[i][j]<<"\t";
		}
		cout<<endl;
	}
}
int main()
{
	FILE *fp;
	fp=fopen("input_floydwar.txt","r");
	if(fp==NULL)
	{
		printf("Error to open the file\n\n");
	}
    int n;
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
    floydwarshall(graph,n);
	fclose(fp);
	return 0;
}
