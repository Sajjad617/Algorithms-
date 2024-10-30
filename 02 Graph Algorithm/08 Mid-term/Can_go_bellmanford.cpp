// Right

#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u, v, c;
        Edge(int u, int v, int c)
        {
            this->u = u;
            this->v = v;
            this->c = c;
        }
};

const int N = 1e5+5;
long long int dis[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while(e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    for(int i=0; i<=n; i++)
    {
        dis[i] = INT_MAX;
    }
    int src;
    cin >> src;

    dis[src] = 0;
    for(int i=0; i<=n-1; i++)
    {
        for(Edge ed : EdgeList)
        {
            int u, v, c;
            u = ed.u;
            v = ed.v;
            c = ed.c;

            if(dis[u] < INT_MAX && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }

    int t;
    cin >> t;
    while(t--)
    {
        int node, c;
        cin >> node >> c;
        if(dis[node]==INT_MAX)
        {
            cout << "NO" << endl;
        }
        else
        {
            if(dis[node]<=c)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

    }
    
    return 0;
}