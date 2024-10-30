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
    if(parent[node]==-1) return node;
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
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    int n, e;
    cin >> n >> e;
    dsu_init(n);
    bool cycle = false;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA == leaderB)
            cycle = true;
        else
            union_by_size(a, b);
    }
    if(cycle)
        cout << "Cycle found" << endl;
    else
        cout << "Cycle Not Found" << endl;
    return 0;
}