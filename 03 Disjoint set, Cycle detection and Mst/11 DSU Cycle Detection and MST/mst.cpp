#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int grp_size[N];
void dsu_init(int n)
{
    for(int i=0; i<n; i++)
    {
        parent[i] = -1;
        grp_size[i] = 1;
    }
}
int dsu_find(int node)
{
    if(parent[node] == -1) return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void union_by_size(int nodeA, int nodeB)
{
    int leaderA = dsu_find(nodeA);
    int leaderB = dsu_find(nodeB);
    if(grp_size[leaderA] > grp_size[leaderB])
    {
        parent[leaderB] = leaderA;
        grp_size[leaderA] += grp_size[leaderB];
    }
    else
    {
        parent[leaderA] = leaderB;
        grp_size[leaderB] += grp_size[leaderA];
    }
}
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

bool cmp(Edge a, Edge b)
{
    return a.c < b.c;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, e;
    cin >> n >> e;
    dsu_init(n);
    vector<Edge> edgelist;
    while(e--)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edgelist.push_back(Edge(u, v, c));
    }
    sort(edgelist.begin(), edgelist.end(), cmp);
    int totalcost = 0;
    for(Edge ed : edgelist)
    {
        int leaderU = dsu_find(ed.u);
        int leaderV = dsu_find(ed.v);
        if(leaderU == leaderV)
        {
            continue;
        }
        else
        {
            union_by_size(ed.u, ed.v);
            totalcost += ed.c;
        }
    }
    cout << totalcost;
    return 0;
}