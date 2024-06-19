#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion
{
    public:
        vector<int> parent, rank;

        DisjointSetUnion(int n)
        {
            parent.resize(n+1,-1);
            rank.resize(n+1,1);
            for (int i = 0; i <= n; i++)
            {
                parent[i] = -1;
                rank[i] = 1;
            }
        }

        int find(int i)
        {
            if(parent[i]==-1)
            {
                return i;
            }
            return parent[i]=find(parent[i]);
        }

        void uniteByRank(int u, int v)
        {
            int s1 = find(u);
            int s2 = find(v);
            if(s1==s2)
                return;
           
             if(s1!=s2)
            {
                if(rank[s1]<rank[s2])
                {
                    parent[s1]=s2;
                    rank[s2]+=rank[s1];
                }
                else
                {
                    parent[s2]=s1;
                    rank[s1]+=rank[s2];
                }
            }
            
        }
};
int main()
{
    int n, edges;
    cin >> n >> edges;
    vector<pair<int, pair<int, int> > > graph[n];
    int a, b, wt;
    for (int i = 1; i <= edges; i++)
    {
        cin >> a >> b >> wt;
        graph->push_back(make_pair(wt, make_pair(a, b)));
    }

    DisjointSetUnion dsu(n);
    sort(graph->begin(), graph->end());
    int cost = 0;
    vector<pair<int, pair<int, int> > >it;
    for(auto it:graph)
    {
        for(auto edge:it)
        {

        int wt = edge.first;
        int a =edge.second.first;
        int b = edge.second.second;
        if(dsu.find(a)!=dsu.find(b))
        {
            dsu.uniteByRank(a,b);
            cost+=wt;
        }
        }
    }
    cout<<cost<<endl;
    return 0;
}