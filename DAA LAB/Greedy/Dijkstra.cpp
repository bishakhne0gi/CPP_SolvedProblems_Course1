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

void dijkstra(int graph[20][20], int src, int m)
{
	int dist[20];
	bool sptSet[20];

	for (int i = 0; i < m; i++)
	{
		dist[i] = INT_MAX, sptSet[i] = false;
	}
	dist[src] = 0;

	for (int count = 0; count < m - 1; count++)
	{
		int mini = INT_MAX, u;

		for (int v = 0; v < m; v++)
		{
			if (sptSet[v] == false && dist[v] <= mini)
			{
				mini = dist[v], u = v;
			}
		}
		sptSet[u] = true;
		for (int v = 0; v < m; v++)
		{
			if (graph[u][v] && sptSet[v] == false && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
			{

				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	printSolution(dist, m);
}

int main()
{
	cout << "Source--> S" << endl;

	FILE *fp = fopen("abc.txt", "r");
	if (fp == NULL)
	{
		printf("\n Cannot open file");
	}
	int x, m;
	int graph[20][20];
	fscanf(fp, "%d", &m);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			fscanf(fp, "%d", &x);
			graph[i][j] = x;
		}
	}

	dijkstra(graph, 0, m);

	return 0;
}
