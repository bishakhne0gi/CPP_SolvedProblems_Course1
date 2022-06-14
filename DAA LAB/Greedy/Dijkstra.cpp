/*
    TC: O(v2) v- number of vertices
    SC: O(v)  v-number of vertices in priority queue
*/
#include <bits/stdc++.h>
using namespace std;
int minDistance(int dist[], bool sptSet[], int m)
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < m; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[], int m)
{
	cout << "Vertex \t Distance from Source(S)" << endl;
	cout << "S \t\t" << dist[0] << endl;
	for (int i = 1; i < m; i++)
		cout << char(i + 65) << " \t\t" << dist[i] << endl;
}

void dijkstra(int graph[20][20], int src, int n)
{
	int dist[20];
	bool sptSet[20];

	for (int i = 0; i < n; i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	dist[src] = 0;

	for (int i = 0; i < n- 1; i++)
	{
		int mini = INT_MAX, u;

		for (int j = 0; j < n; j++)
		{
			if (sptSet[j] == false && dist[j] < mini)
			{
				mini = dist[j];
				u = j;
			}
		}
		sptSet[u] = true;
		for (int k = 0; k < n; k++)
		{
			if (graph[u][k] && sptSet[k] == false && dist[u] != INT_MAX && dist[u] + graph[u][k] < dist[k])
			{
				dist[k] = dist[u] + graph[u][k];
			}
		}
	}
	printSolution(dist, n);
}

int main()
{
	cout << "Source--> S" << endl;

	FILE *fp = fopen("dij.txt", "r");
	if (fp == NULL)
	{
		printf("\n Cannot open file");
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

	dijkstra(graph, 0, n);

	return 0;
}
