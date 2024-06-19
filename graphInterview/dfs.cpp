#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, edges;
    cin >> n >> edges;
    vector<int> g[n + 1];
    int a, b;
    for (int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    stack<int> s;
    vector<bool> visited(n + 1, false);
    s.push(1);
    visited[1] = true;
    while(!s.empty())
    {
        int node = s.top();
        s.pop();
        cout << node << " ";
        for(auto it: g[node])
        {
            if(!visited[it])
            {
                s.push(it);
                visited[it] = true;
            }
        }
    }
    return 0;
}