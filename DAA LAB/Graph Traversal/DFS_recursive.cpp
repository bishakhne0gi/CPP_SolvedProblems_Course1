#include<bits/stdc++.h>
using namespace std;
int graph[20][20];
bool visited[20];
int top=-1;
void initialize()
{
    for(int i=0;i<20;i++)
    {
        visited[i]=false;
    }
}
void dfs(int a, int n){
	visited[a]=true;
    char u=a+65;
	cout<<u<<endl;
	for(int i=0;i<n;i++){
		if(graph[a][i]==1 && visited[i]==false){
			dfs(i, n);
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
    FILE *fp;
    fp=fopen("VE.txt","r");
    if (fp == NULL)
    { 
        printf("\nError to open the file\n");
        exit (1);
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
        fclose(fp);  
        print(n);
        dfs(0, n);
        return 0;
}