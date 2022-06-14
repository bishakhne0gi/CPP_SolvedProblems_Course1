#include <bits/stdc++.h>
using namespace std;
void printPrims(int parent[], int graph[20][20], int m)
{
	int sum = 0;
	cout << "PRIMS ALGORITHM"<<endl;
	cout << "Edges"<< "\t"<< "weight" << endl;
	for (int i = 1; i < m; i++)
	{
		cout << char(parent[i] + 65) << "<--->" << char(i + 65) << "   " << graph[i][parent[i]] << endl;
		sum += graph[i][parent[i]];
	}

	cout << "MINIMUM COST: " << sum << endl;
}
// void print(int graph[20][20], int n)
// {
//     cout << "The graph is" << endl;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << "\t" << graph[i][j];
//         }
//         cout << endl;
//     }
// }
void prims(int graph[20][20], int n)
{
    bool mst[20];
    int parent[20];
    int key[20];
   
    for (int i = 0; i < n; i++)
	{
		key[i] = INT_MAX;
         mst[i] = false;
          parent[i] = -1;
	}
     key[0]=0;
     parent[0]=-1;
    for(int i=0; i<n-1; i++)
    {
        int mini=INT_MAX, u;
        for(int i=0; i<n; i++)
        {
            if(mst[i]==false && key[i]<mini)
            {
                mini=key[i];
                u=i;
            }
        }
        mst[u]=true;
        for(int k=0; k<n; k++)
        {
            if(graph[u][k] && mst[k]==false && graph[u][k]< key[k])
            {
                parent[k]=u;
                key[k]=graph[u][k];
            }
        }
    }
    printPrims(parent,graph,n);
}
int main()
{
    int graph[20][20];
    FILE *fp = fopen("mnp.txt", "r");
    int n,x;
    fscanf(fp, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(fp, "%d", &x);
            graph[i][j] = x;
        }
    }
    // print(graph,n);
    prims(graph,n);
    return 0;
}