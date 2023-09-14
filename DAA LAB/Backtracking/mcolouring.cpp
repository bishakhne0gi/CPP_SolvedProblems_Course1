/*
    TC: O(m * n^m)
    SC: O(n)
*/
#include<iostream>
using namespace std;
bool graph[20][20];
int c=0;
int node;
bool flag=false;

void printSolution(int color[], int n);

bool isSafe(bool graph[20][20], int color[], int n)
{
	for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (graph[i][j] && color[j] == color[i])
            {
                return false;
            }	
        }
    }	
	return true;
}


bool graphColoring(bool graph[20][20], int m, int node,int color[20], int n)
{
	if (node == n) {
		if (isSafe(graph, color,n)) {
		    c++;
            flag=true;
			printSolution(color,n);
        
		}
		return false;
	}
	for (int j = 1; j <= m; j++) {
		color[node] = j;
		if (graphColoring(graph, m, node+ 1, color,n))
        {
			return true;
        }   
		color[node] = 0;
	}
	return false;
}
void printSolution(int color[], int n)
{
	cout << "Solution Exists:" " Following are the assigned colors "<<endl;
	for (int i = 0; i < n; i++)
		cout << " " << color[i];
	cout << endl;
}
int main()
{
	FILE *fp = fopen("pqr.txt","r");
    if(fp==NULL)
        cout<<"Error in opening file."<<endl;
    int n;
    fscanf(fp,"%d",&n);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            fscanf(fp,"%d", &graph[i][j]);
        }
    }
    cout<<"Enter the number of colors: "<<endl;
    int m;
    cin>>m;
	int color[20];
    //initialising color array
	for (int i = 0; i < n; i++)
    {
		color[i] = 0;
    }
	if (!graphColoring(graph, m, 0, color,n) && flag==false)
    {
		cout << "Solution does not exist";
    }
    cout<<"Number of solution "<<c<<endl;
	return 0;
}