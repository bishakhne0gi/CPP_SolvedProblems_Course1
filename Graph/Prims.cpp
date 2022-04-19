#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<pair<int,int>> *l;
    public:
        Graph(int v)
        {
            V=v;
            l = new vector<pair<int,int>> [v];
        }
        void addEdge(int i, int j, int w)
        {
            l[i].push_back({j,w});
            l[j].push_back({i,w});

        }
        int prim_mst()
        [
            priority_queue<
        ]
};
int main()
{
    return 0;
}