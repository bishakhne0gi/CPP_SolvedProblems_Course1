/*
    The graph must be connected
    TC: O(v2) v- number of vertices
    SC: O(v)  v-number of vertices in priority queue
*/
#include <bits/stdc++.h>
using namespace std;
void print(int graph[20][20], int n)
{
    cout << "The graph is" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "\t" << graph[i][j];
        }
        cout << endl;
    }
}
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

void prims(int graph[20][20], int n)
{

	int parent[20];
	int key[20];
	bool mstset[20];
	// Initalising the arrays
	for (int i = 0; i < n; i++)
	{
		key[i] = INT_MAX, mstset[i] = false, parent[i] = -1;
	}

	key[0] = 0;
	parent[0] = -1;

	// minkey function
	//Traversing m-1 edges
	for (int i = 0; i < n - 1; i++)
	{
		int mini = INT_MAX, u;

		for (int i = 0; i < n; i++)
		{
			if (mstset[i] == false && key[i] < mini)
			{
				mini = key[i], u = i;
			}
		}
		mstset[u] = true;

		for (int k= 0; k < n; k++)
		{
			if (graph[u][k] && mstset[k] == false && graph[u][k] < key[k])
			{
				parent[k] = u;
				key[k] = graph[u][k];	
			}
		}
	}
	// print the graph with minimum weights
	printPrims(parent, graph, n);
}

int main()
{
	FILE *fp = fopen("abc.txt", "r");
	if (fp == NULL)
	{
		cout<<"Cannot open file"<<endl;
	}
	int x, n;
	int graph[20][20];
	fscanf(fp, "%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(fp, "%d", &x);
			graph[i][j] = x;
		}
	}
	print(graph,n);
	prims(graph, n);
}
