#include <bits/stdc++.h>
using namespace std;

struct Graph
{
    int u,w;
    bool operator < (const Graph & a)const
    {
        return w > a.w;
    }
};


const int N = 1e5;
int node[N],dist[N];
priority_queue <Graph> PQ;
vector <Graph> adj[N];

void dijkstra(int st)
{
    dist[st] = 0;
    PQ.push({st,0});
    while (!PQ.empty())
    {
        auto [u,w] = PQ.top();
        PQ.pop();
        if (w > dist[u])
        {
            continue;
        }
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (dist[adj[u][i].u] > w + adj[u][i].w)
            {
                PQ.push({adj[u][i].u,dist[adj[u][i].u] = w + adj[u][i].w});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fill(dist,dist + N,INT_MAX);
    int n,e,u,v,w;
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i];
    }
    for (int i = 0; i < e; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        if (dist[i] >= 10)
        {
            cout << " ";
        }
        cout << char((node[i]-1)+'A') << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    
    return 0;
}