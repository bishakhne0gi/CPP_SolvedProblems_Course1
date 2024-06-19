#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, edges, src;
    cin >> n >> edges >> src;
    vector<pair<int, int> > g[n + 1];

    int a, b, wt;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b >> wt;
        g[a].push_back(make_pair(b,wt));
        g[b].push_back(make_pair(a, wt));
    }


    //min heap
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    //distance array initialized with INT_MAX
    vector<int> distance(n, INT_MAX);

    distance[src] = 0;
    //wt,node
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        int dist = pq.top().first;
        int prev=pq.top().second;
        pq.pop();

        vector<pair<int, int> >::iterator it;
        for(auto it :g[prev])
        {
            int next = it.first;
            int nextDist = it.second;
            if(distance[next]>distance[prev]+nextDist)
            {
                distance[next]=distance[prev]+nextDist;
                pq.push(make_pair(distance[next],next));
            }
            
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<"node: "<<i<<"distance: "<<distance[i]<<endl;
    }
    return 0;
}